#include "JGameObject.h"
#include "JInput.h"
#include "JTime.h"
JGameObject::JGameObject()
{
}
JGameObject::~JGameObject()
{
	//������Ʈ�� ���󰥶� �Ҵ� ����
	for (JComponent* comp : mComponents)
	{
		delete comp;
		comp = nullptr;	//����� üũ
	}
}

void JGameObject::Initialize()
{
	for (JComponent* comp : mComponents)
		comp->Initialize();
}

void JGameObject::Update()
{
	for (JComponent* comp : mComponents)
		comp->Update();
	/*
	if (JInput::GetKey(eKeyCode::a))
	{
		mX -= 100 * JTime::DeltaTime();
	}

	if (JInput::GetKey(eKeyCode::d))
	{
		mX += 100 * JTime::DeltaTime();
	}

	if (JInput::GetKey(eKeyCode::w))
	{
		mY -= 100 * JTime::DeltaTime();
	}

	if (JInput::GetKey(eKeyCode::s))
	{
		mY += 100 * JTime::DeltaTime();
	}
	*/
}
void JGameObject::LateUpdate()
{
	for (JComponent* comp : mComponents)
		comp->LateUpdate();
}
void JGameObject::Render(HDC hdc)
{

	for (JComponent* comp : mComponents)
		comp->Render(hdc);
}