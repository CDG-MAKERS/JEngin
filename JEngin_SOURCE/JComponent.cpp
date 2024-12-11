#include "JComponent.h"

JComponent::JComponent(enums::eComponentType type)
	: mOwner(nullptr)
	, mType(type)
{
}

JComponent::~JComponent()
{
}

void JComponent::Initialize()
{
}

void JComponent::Update()
{
}

void JComponent::LateUpdate()
{
}

void JComponent::Render(HDC hdc)
{
}
