#include "JCamera.h"
#include "JGameObject.h"
#include "JTransform.h"
#include "JApplication.h"

extern JApplication application;
JCamera::JCamera()
	: JComponent(enums::eComponentType::Camera)
	, mDistance(Vector2::Zero)
	, mResolution(Vector2::Zero)
	, mLookPosition(Vector2::Zero)
	, mTarget(nullptr)
{

}

JCamera::~JCamera()
{

}

void JCamera::Initialize()
{
	mResolution.x = application.GetWidth();
	mResolution.y = application.GetHeight();
}

void JCamera::Update()
{
	if (mTarget)
	{
		JTransform* tr = mTarget->GetComponent<JTransform>();
		mLookPosition = tr->GetPosition();
	}
	JTransform* cameraTr = GetOwner()->GetComponent<JTransform>();
	mLookPosition = cameraTr->GetPosition();
	mDistance = mLookPosition - (mResolution / 2.0f);
}

void JCamera::LateUpdate()
{
}

void JCamera::Render(HDC hdc)
{
}
