#include "JPlayerScript.h"
#include "JInput.h"
#include "JTransform.h"
#include "JTime.h"
#include "JGameObject.h"
#include "JAnimator.h"
JPlayerScript::JPlayerScript()
	: mState(JPlayerScript::eState::SitDown)
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
	case JPlayerScript::eState::SitDown:
		sitDown();
		break;
	case JPlayerScript::eState::Walk:
		move();
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
		mState = JPlayerScript::eState::SitDown;
		mAnimator->PlayAnimation(L"CharacterFrontMove", false);
	}
}

void JPlayerScript::sitDown()
{
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
