#include "JCircleCollider2D.h"
#include "JTransform.h"
#include "JGameObject.h"
#include "JRenderer.h"
#include "JCamera.h"

JCircleCollider2D::JCircleCollider2D()
	:JCollider(enums::eColliderType::Circle2D)
{
}

JCircleCollider2D::~JCircleCollider2D()
{
}

void JCircleCollider2D::Initialize()
{
}

void JCircleCollider2D::Update()
{
}

void JCircleCollider2D::LateUpdate()
{
}

void JCircleCollider2D::Render(HDC hdc)
{
	JTransform* tr = GetOwner()->GetComponent<JTransform>();
	Vector2 pos = tr->GetPosition();

	if (JRenderer::mainCamera)
		pos = JRenderer::mainCamera->CaluatePosition(pos);

	Vector2 offset = GetOffset();

	HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

	HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

	Vector2 rightBottom;
	rightBottom.x = pos.x + offset.x + 100 * GetSize().x;
	rightBottom.y = pos.y + offset.y + 100 * GetSize().y;

	Ellipse(hdc, pos.x + offset.x
		, pos.y + offset.y
		, rightBottom.x
		, rightBottom.y);

	SelectObject(hdc, oldBrush);
	SelectObject(hdc, oldPen);
	DeleteObject(greenPen);
}
