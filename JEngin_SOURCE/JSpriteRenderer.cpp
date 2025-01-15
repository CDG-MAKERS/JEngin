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
	Vector2 scale = tr->GetScale();
	float rot = tr->GetRoation();
	pos = JRenderer::mainCamera->CaluatePosition(pos);
	if (mTexture->GetTextureType() 
		== graphics::JTexture::eTextureType::Bmp)
	{
		if (mTexture->IsAlpha())
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 255; // 0불투 255 투

			HDC imgHdc = mTexture->GetHdc();
			AlphaBlend(hdc
				, pos.x 
				, pos.y 
				, mTexture->GetWidth() * mSize.x * scale.x
				, mTexture->GetHeight() * mSize.y * scale.y
				, mTexture->GetHdc()
				, 0, 0
				, mTexture->GetWidth()
				, mTexture->GetHeight()
				, func);
		}
		else
		{
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x * scale.x
				, mTexture->GetHeight() * mSize.y * scale.y
				, mTexture->GetHdc()
				, 0, 0
				, mTexture->GetWidth()
				, mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
	}
	else if (mTexture->GetTextureType()
		== graphics::JTexture::eTextureType::Png)
	{
		// 내가 원하는 픽셀을 투명화 시킬때
		Gdiplus::ImageAttributes imgAtt = {};
		// 투명화 시킬 픽셀의 색 범위
		imgAtt.SetColorKey(Gdiplus::Color(100, 100, 100)
			, Gdiplus::Color(255, 255, 255));

		Gdiplus::Graphics graphics(hdc);

		graphics.TranslateTransform(pos.x, pos.y);
		graphics.RotateTransform(rot);
		graphics.TranslateTransform(-pos.x, -pos.y);

		graphics.DrawImage(mTexture->GetImage()
			, Gdiplus::Rect
			(
				pos.x, pos.y
				, mTexture->GetWidth() * mSize.x
				, mTexture->GetHeight() * mSize.y
			)
			, 0, 0
			, mTexture->GetWidth()
			, mTexture->GetHeight()
			, Gdiplus::UnitPixel
			, nullptr
		);


	}
}

