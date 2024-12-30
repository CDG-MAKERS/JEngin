#include "JBoxCollider2D.h"
#include "JTransform.h"
#include "JGameObject.h"

JBoxCollider2D::JBoxCollider2D()
	: JCollider()
{
}

JBoxCollider2D::~JBoxCollider2D()
{
}

void JBoxCollider2D::Initialize()
{
}

void JBoxCollider2D::Update()
{
}

void JBoxCollider2D::LateUpdate()
{
}

void JBoxCollider2D::Render(HDC hdc)
{
	JTransform* tr = GetOwner()->GetComponent<JTransform>();
	Vector2 pos = tr->GetPosition();

	Vector2 offset = GetOffset();

	HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

	HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

	Rectangle(hdc, pos.x + offset.x
		, pos.y + offset.y
		, pos.x + offset.x + 100 * GetSize().x
		, pos.y + offset.y + 100 * GetSize().y);

	SelectObject(hdc, oldBrush);
	SelectObject(hdc, oldPen);
	DeleteObject(greenPen);
}
