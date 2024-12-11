#include "JTransform.h"

JTransform::JTransform()
	: JComponent(enums::eComponentType::Transform)
	, mPosition(Vector2::Zero)
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
