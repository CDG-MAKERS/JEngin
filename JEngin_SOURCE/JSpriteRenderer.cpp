#include "JSpriteRenderer.h"
#include "JGameObject.h"
#include "JTransform.h"
#include "JTexture.h"
#include "JRenderer.h"

JSpriteRenderer::JSpriteRenderer()
	: JComponent(enums::eComponentType::SpriteRenderer)
	, mTexture(nullptr)
	, mSize(Vector2::One)
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
	if (mTexture == nullptr) //텍스처 세팅 안됨
		assert(false);


	JTransform* tr = GetOwner()->GetComponent<JTransform>();
	Vector2 pos = tr->GetPosition();
	pos = JRenderer::mainCamera->CaluatePosition(pos);
	if (mTexture->GetTextureType() 
		== graphcis::JTexture::eTextureType::Bmp)
	{

		TransparentBlt(hdc, pos.x, pos.y
			, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y
			, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
			, RGB(255, 0, 255));

	}
	if (mTexture->GetTextureType()
		== graphcis::JTexture::eTextureType::Png)
	{
		Gdiplus::Graphics graphcis(hdc);
		graphcis.DrawImage(mTexture->GetImage()
			, Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mSize.x
				, mTexture->GetHeight() * mSize.y));
	}
}

