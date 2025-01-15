#include "JTransform.h"

JTransform::JTransform()
	: JComponent(enums::eComponentType::Transform)
	, mPosition(Vector2::Zero)
	, mScale(Vector2::One)
	, mRoation(0.0f)
{
}

JTransform::~JTransform()
{
}

void JTransform::Initialize()
{
}

void JTransform::Update()
{
}

void JTransform::LateUpdate()
{
}

void JTransform::Render(HDC hdc)
{
}
