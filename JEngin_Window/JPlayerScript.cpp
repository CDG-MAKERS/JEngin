#include "JPlayerScript.h"
#include "JInput.h"
#include "JTransform.h"
#include "JTime.h"
#include "JGameObject.h"
#include "JAnimator.h"
#include "JCat.h"
#include "JCatScript.h"
#include "JObject.h"
#include "JResources.h"
JPlayerScript::JPlayerScript()
	: mState(JPlayerScript::eState::Idle)
	, mAnimator(nullptr)
{
}

JPlayerScript::~JPlayerScript()
{
}

void JPlayerScript::Initialize()
{
}

void JPlayerScript::Update()
{
	if (mAnimator == nullptr)
	{
		mAnimator = GetOwner()->GetComponent<JAnimator>();
	}


	switch (mState)
	{
	case JPlayerScript::eState::Idle:
		idle();
		break;
	case JPlayerScript::eState::Walk:
		move();
		break;
	case JPlayerScript::eState::Attack:
		break;
	default:
		break;
	}
}

void JPlayerScript::LateUpdate()
{
}

void JPlayerScript::Render(HDC hdc)
{
}

void JPlayerScript::AttackEffect()
{
	JCat* cat = object::Instantiate<JCat>(enums::eLayerType::Animal);
	//cat->AddComponent<JCatScript>();
	////cameraComp->SetTarget(cat);
	//graphics::JTexture* catTex = JResources::Find<graphics::JTexture>(L"Cat");
	//JAnimator* catAnimator = cat->AddComponent<JAnimator>();
	//
	//catAnimator->CreateAnimation(L"DownWalk", catTex
	//	, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	//catAnimator->CreateAnimation(L"RightWalk", catTex
	//	, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	//catAnimator->CreateAnimation(L"UpWalk", catTex
	//	, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	//catAnimator->CreateAnimation(L"LeftWalk", catTex
	//	, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	//catAnimator->CreateAnimation(L"SitDown", catTex
	//	, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	//catAnimator->CreateAnimation(L"Grooming", catTex
	//	, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	//catAnimator->CreateAnimation(L"LayDown", catTex
	//	, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

	//catAnimator->PlayAnimation(L"SitDown", false);
	//cat->GetComponent<JTransform>()->SetPosition(Vector2(200.0f, 200.0f));
	//cat->GetComponent<JTransform>()->SetScale(Vector2(2.0f, 2.0f));
}

void JPlayerScript::OnCollisionEnter(JCollider* other)
{
	other->GetOwner()->GetComponent<JTransform>()->SetPosition(Vector2(400.0f, 500.0f));
}

void JPlayerScript::OnCollisionStay(JCollider* other)
{
}

void JPlayerScript::OnCollisionExit(JCollider* other)
{
}

void JPlayerScript::move()
{
	JTransform* tr = GetOwner()->GetComponent<JTransform>();
	Vector2 pos = tr->GetPosition();

	if (JInput::GetKey(eKeyCode::Left))
	{
		pos.x -= 100.0f * JTime::DeltaTime();
	}
	if (JInput::GetKey(eKeyCode::Right))
	{
		pos.x += 100.0f * JTime::DeltaTime();
	}
	if (JInput::GetKey(eKeyCode::Up))
	{
		pos.y -= 100.0f * JTime::DeltaTime();
	}
	if (JInput::GetKey(eKeyCode::Down))
	{
		pos.y += 100.0f * JTime::DeltaTime();
	}

	tr->SetPosition(pos);

	if (JInput::GetKeyUp(eKeyCode::Left) || JInput::GetKeyUp(eKeyCode::Right)
		|| JInput::GetKeyUp(eKeyCode::Up) || JInput::GetKeyUp(eKeyCode::Down))
	{
		mState = JPlayerScript::eState::Idle;
		mAnimator->PlayAnimation(L"CharacterFrontMove", false);
	}
}

void JPlayerScript::idle()
{
	if (JInput::GetKey(eKeyCode::LButton))
	{
		JCat* cat = object::Instantiate<JCat>(enums::eLayerType::Animal);
		JCatScript* catScript = cat->AddComponent<JCatScript>();

		catScript->SetPlayer(GetOwner());
		graphics::JTexture* catTex = JResources::Find<graphics::JTexture>(L"Cat");

		JAnimator* catAnimator = cat->AddComponent<JAnimator>();
		
		catAnimator->CreateAnimation(L"DownWalk", catTex
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"RightWalk", catTex
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"UpWalk", catTex
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LeftWalk", catTex
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"SitDown", catTex
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"Grooming", catTex
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		catAnimator->CreateAnimation(L"LayDown", catTex
			, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		catAnimator->PlayAnimation(L"Grooming", true);

		JTransform* tr = GetOwner()->GetComponent<JTransform>();

		cat->GetComponent<JTransform>()->SetPosition(tr->GetPosition());
		cat->GetComponent<JTransform>()->SetScale(Vector2(2.0f, 2.0f));
		Vector2 mousePos = JInput::GetMousePosition();
		catScript->mDest = mousePos;
	}
	if (JInput::GetKey(eKeyCode::Right))
	{
		mState = JPlayerScript::eState::Walk;
		mAnimator->PlayAnimation(L"CharacterRightMove");
	}
	if (JInput::GetKey(eKeyCode::Left))
	{
		mState = JPlayerScript::eState::Walk;
		mAnimator->PlayAnimation(L"CharacterLeftMove");
	}
	if (JInput::GetKey(eKeyCode::Up))
	{
		mState = JPlayerScript::eState::Walk;
		mAnimator->PlayAnimation(L"CharacterBottomMove");
	}
	if (JInput::GetKey(eKeyCode::Down))
	{
		mState = JPlayerScript::eState::Walk;
		mAnimator->PlayAnimation(L"CharacterFrontMove");
	}
}
