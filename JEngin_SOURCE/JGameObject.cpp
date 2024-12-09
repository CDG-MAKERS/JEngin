#include "JGameObject.h"
#include "JInput.h"
#include "JTime.h"
JGameObject::JGameObject()
	: mX(0)
	, mY(0)
{

}
JGameObject::~JGameObject()
{
}

void JGameObject::Update()
{

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
}
void JGameObject::LateUpdate()
{

}
void JGameObject::Render(HDC hdc)
{
	HBRUSH MyBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
	HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, MyBrush);
	Rectangle(hdc, mX, mY, mX+50, mY+50);
	SelectObject(hdc, OldBrush);
	DeleteObject(MyBrush);
}