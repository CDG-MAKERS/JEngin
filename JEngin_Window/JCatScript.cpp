#include "JCatScript.h"
#include "JInput.h"
#include "JTransform.h"
#include "JTime.h"
#include "JGameObject.h"
#include "JAnimator.h"
#include "JObject.h"

JCatScript::JCatScript()
	: mState(JCatScript::eState::SitDown)
	, mAnimator(nullptr)
	, mTime(0.0f)
	, mDeathTime(0.0f)
	, mDest(Vector2::Zero)
	, mRadian(0.0f)
{
}

JCatScript::~JCatScript()
{
}

void JCatScript::Initialize()
{
}

void JCatScript::Update()
{
	mDeathTime += JTime::DeltaTime();
	if (mDeathTime > 6.0f)
	{
		//object::Destory(GetOwner());
	}
	if (mAnimator == nullptr)
	{
		mAnimator = GetOwner()->GetComponent<JAnimator>();
	}

	switch (mState)
	{
	case JCatScript::eState::SitDown:
		idle();
		break;
	case JCatScript::eState::Walk:
		move();
		break;

	case JCatScript::eState::Sleep:
		break;
	case JCatScript::eState::LayDown:

		break;
	case JCatScript::eState::Attack:
		break;
	default:
		break;
	}
}

void JCatScript::LateUpdate()
{
}

void JCatScript::Render(HDC hdc)
{
}

void JCatScript::idle()
{
	mTime += JTime::DeltaTime();
	//if (mTime > 3.0f)
	//{
	//	mState = JCatScript::eState::Walk;
	//	int direction = (rand() % 4);
	//	mDirection = (eDirection)direction;
	//	PlayWalkAnimationByDirection(mDirection);
	//	mTime = 0.0f;
	//}
	JTransform* tr = GetOwner()->GetComponent<JTransform>();
	Vector2 pos = tr->GetPosition();

	// 마우스 위치 이동 ( 벡터의 뺄셈 활용 )
	//Transform* plTr = mPlayer->GetComponent<Transform>();
	//Vector2 dest = mDest - plTr->GetPosition();
	//pos += dest.normalize() * (100.0f * Time::DeltaTime());


	// 삼각함수를 통한 이동

	//mRadian += 5.0f * JTime::DeltaTime();
	//pos += Vector2(1.0f, 2.0f * cosf(mRadian)) * (100.0f * JTime::DeltaTime());


	// 마우스 위치 방향으로 회전후 마우스 위치 이동 ( 벡터의 뺄셈 활용 )
	//JTransform* plTr = mPlayer->GetComponent<JTransform>();
	//Vector2 dest = mDest - plTr->GetPosition();
	//dest.normalize();

	//float rotDegree = Vector2::Dot(dest, Vector2::Right); //cos세타
	//rotDegree = acosf(rotDegree);

	//rotDegree = ConvertDegree(rotDegree);

	//pos += dest * (100.0f * JTime::DeltaTime());

	//tr->SetPosition(pos);




	/*if (mTime > 3.0f)
	{
		mState = CatScript::eState::Walk;
		int direction = (rand() % 4);
		mDirection = (eDirection)direction;
		PlayWalkAnimationByDirection(mDirection);
		mTime = 0.0f;
	}*/
}

void JCatScript::move()
{
	mTime += JTime::DeltaTime();
	if (mTime > 2.0f)
	{
		int isLayDown = rand() % 2;
		if (isLayDown)
		{
			mState = eState::LayDown;
			mAnimator->PlayAnimation(L"LayDown", false);
		}
		else
		{
			mState = eState::SitDown;
			mAnimator->PlayAnimation(L"SitDown", false);
		}
	}

	JTransform* tr = GetOwner()->GetComponent<JTransform>();
	translate(tr);
}

void JCatScript::layDown()
{
}

void JCatScript::PlayWalkAnimationByDirection(eDirection dir)
{
	switch (dir)
	{
	case JCatScript::eDirection::Left:
		mAnimator->PlayAnimation(L"LeftWalk", true);
		break;
	case JCatScript::eDirection::Right:
		mAnimator->PlayAnimation(L"RightWalk", true);
		break;
	case JCatScript::eDirection::Down:
		mAnimator->PlayAnimation(L"DownWalk", true);
		break;
	case JCatScript::eDirection::Up:
		mAnimator->PlayAnimation(L"UpWalk", true);
		break;
	default:
		assert(false);
		break;
	}
}

void JCatScript::translate(JTransform* tr)
{
	Vector2 pos = tr->GetPosition();
	switch (mDirection)
	{
	case JCatScript::eDirection::Left:
		pos.x -= 100.0f * JTime::DeltaTime();
		break;
	case JCatScript::eDirection::Right:
		pos.x += 100.0f * JTime::DeltaTime();
		break;
	case JCatScript::eDirection::Down:
		pos.y += 100.0f * JTime::DeltaTime();
		break;
	case JCatScript::eDirection::Up:
		pos.y -= 100.0f * JTime::DeltaTime();
		break;
	default:
		assert(false);
		break;
	}
	tr->SetPosition(pos);
}
