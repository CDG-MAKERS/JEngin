#include "JSpriteRenderer.h"
#include "JGameObject.h"
#include "JTransform.h"
JSpriteRenderer::JSpriteRenderer()
{
}

JSpriteRenderer::~JSpriteRenderer()
{
}

void JSpriteRenderer::Initialize()
{
}

void JSpriteRenderer::Update()
{
}

void JSpriteRenderer::LateUpdate()
{
}

void JSpriteRenderer::Render(HDC hdc)
{
	//�귯�� ����
	HBRUSH MyBrush = (HBRUSH)GetStockObject(RGB(255, 0, 255));
	//�� �귯�� dc ���� ���� �귯�� ��ȯ(OldBrush�� �����귯���� �ȴ�)
	HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, MyBrush);

	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
	HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
	SelectObject(hdc, oldPen);

	JTransform* tr = GetOwner()->GetComponent<JTransform>();
	Rectangle(hdc, tr->GetX(), tr->GetY(), 100 + tr->GetX(), 100 + tr->GetY());
	SelectObject(hdc, OldBrush);
	DeleteObject(MyBrush);
	DeleteObject(redPen);
}
