#include "JTilemapRenderer.h"
#include "JGameObject.h"
#include "JTransform.h"
#include "JTexture.h"
#include "JRenderer.h"


Vector2 JTilemapRenderer::TileSize = Vector2::One;
Vector2 JTilemapRenderer::OriginTileSize = Vector2::One;
Vector2 JTilemapRenderer::SelectedIndex = Vector2(-1.0f, -1.0f);
JTilemapRenderer::JTilemapRenderer()
	: JComponent(enums::eComponentType::SpriteRenderer)
	, mTexture(nullptr)
	, mSize(3.0f, 3.0f)
	, mIndex(0, 0)
	, mTileSize(16.0f, 16.0f)
{
	TileSize = mTileSize * mSize;
	OriginTileSize = mTileSize;
}

JTilemapRenderer::~JTilemapRenderer()
{
}

void JTilemapRenderer::Initialize()
{
}

void JTilemapRenderer::Update()
{
}

void JTilemapRenderer::LateUpdate()
{
}

void JTilemapRenderer::Render(HDC hdc)
{
	if (mTexture == nullptr) //텍스처 세팅 해주세요!
		assert(false);

	JTransform* tr = GetOwner()->GetComponent<JTransform>();
	Vector2 pos = tr->GetPosition();
	//float rot = tr->GetRoation();
	Vector2 scale = tr->GetScale();

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
			func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

			AlphaBlend(hdc
				, pos.x, pos.y
				, mTileSize.x * mSize.x * scale.x
				, mTileSize.y * mSize.y * scale.y
				, mTexture->GetHdc()
				, mIndex.x * mTileSize.x, mIndex.y * mTileSize.y
				, mTileSize.x
				, mTileSize.y
				, func);
		}
		else
		{
			//https://blog.naver.com/power2845/50147965306
			TransparentBlt(hdc
				, pos.x, pos.y
				, mTileSize.x * mSize.x * scale.x
				, mTileSize.y * mSize.y * scale.y
				, mTexture->GetHdc()
				, mIndex.x * mTileSize.x, mIndex.y * mTileSize.y
				, mTileSize.x
				, mTileSize.y
				, RGB(255, 0, 255));
		}
	}
	//else if (mTexture->GetTextureType()
	//	== graphics::Texture::eTextureType::Png)
	//{
	//	// 투명화 시킬 픽셀의 색 범위
	//	Gdiplus::ImageAttributes imgAtt = {};
	//	imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

	//	Gdiplus::Graphics graphcis(hdc);

	//	graphcis.TranslateTransform(pos.x, pos.y);
	//	graphcis.RotateTransform(rot);
	//	graphcis.TranslateTransform(-pos.x, -pos.y);

	//	graphcis.DrawImage(mTexture->GetImage()
	//		, Gdiplus::Rect
	//		(
	//			pos.x, pos.y
	//			, mTexture->GetWidth() * mSize.x * scale.x
	//			, mTexture->GetHeight() * mSize.y * scale.y
	//		)
	//		, 0, 0
	//		, mTexture->GetWidth(), mTexture->GetHeight()
	//		, Gdiplus::UnitPixel
	//		, nullptr/*&imgAtt*/);
	//}
}
