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
	JTransform* tr = GetOwner()->GetComponent<JTransform>();
	Vector2 pos = tr->GetPosition();
	Gdiplus::Graphics graphcis(hdc);
	graphcis.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
}

void JSpriteRenderer::ImageLoad(const std::wstring& path)
{
	mImage = Gdiplus::Image::FromFile(path.c_str());
	mWidth = mImage->GetWidth();
	mHeight = mImage->GetHeight();
}
