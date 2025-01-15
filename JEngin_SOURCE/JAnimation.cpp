#include "JAnimation.h"
#include "JTime.h"
#include "JTransform.h"
#include "JGameObject.h"
#include "JAnimator.h"
#include "JRenderer.h"
#include "JCamera.h"

//#define ALPHA_Y
JAnimation::JAnimation()
    :JResource(enums::eResourceType::Animation)
	, mAnimator(nullptr)
    , mTexture(nullptr)
    , mAnimationSheet{}
    , mIndex(-1)
    , mTime(0.0f)
    , mbComplete(false)
{
}

JAnimation::~JAnimation()
{
}

HRESULT JAnimation::Load(const std::wstring& path)
{
    return E_NOTIMPL;
}

void JAnimation::Update()
{
    if (mbComplete)
        return;
    mTime += JTime::DeltaTime();
    if (mAnimationSheet[mIndex].duration < mTime)
    {
        mTime = 0.0f;
        if (mIndex < mAnimationSheet.size() -1)
            mIndex++;
        else
            mbComplete = true;
    }
}

void JAnimation::Render(HDC hdc)
{
    //알파 채널이 있어야 한다.
    //AlphaBlend(125, );
    if (mTexture == nullptr)
        return;

    JGameObject* gameObj = mAnimator->GetOwner();
    JTransform* tr = gameObj->GetComponent<JTransform>();
    Vector2 pos = tr->GetPosition();
    float rot = tr->GetRoation();
    Vector2 scale = tr->GetScale();

    if (JRenderer::mainCamera)
    {
        pos = JRenderer::mainCamera->CaluatePosition(pos);
    }

    Sprite sprite = mAnimationSheet[mIndex];
    graphics::JTexture::eTextureType type = mTexture->GetTextureType();
    if (type == graphics::JTexture::eTextureType::Bmp)
    {

        pos = JRenderer::mainCamera->CaluatePosition(pos);

        HDC imgHdc = mTexture->GetHdc();

        if (mTexture->IsAlpha())
        {
            BLENDFUNCTION func = {};
            func.BlendOp = AC_SRC_OVER;
            func.BlendFlags = 0;
            func.AlphaFormat = AC_SRC_ALPHA;
            func.SourceConstantAlpha = 255; // 0불투 255 투

            HDC imgHdc = mTexture->GetHdc();
            AlphaBlend(hdc
                , pos.x - (sprite.size.x / 2.0f) + sprite.offset.x
                , pos.y - (sprite.size.y / 2.0f) + sprite.offset.y
                , sprite.size.x * scale.x
                , sprite.size.y * scale.y
                , imgHdc
                , sprite.leftTop.x
                , sprite.leftTop.y
                , sprite.size.x
                , sprite.size.y
                , func);
            Rectangle(hdc, pos.x, pos.y, pos.x + 10, pos.y + 10);
        }
        else 
        {
            TransparentBlt(hdc
                , pos.x - (sprite.size.x / 2.0f) + sprite.offset.x
                , pos.y - (sprite.size.y / 2.0f) + sprite.offset.y
                , sprite.size.x * scale.x
                , sprite.size.y * scale.y
                , imgHdc
                , sprite.leftTop.x
                , sprite.leftTop.y
                , sprite.size.x
                , sprite.size.y
                , RGB(255, 0, 255));
            Rectangle(hdc, pos.x, pos.y, pos.x + 10, pos.y + 10);
        }
    }
    else if (type == graphics::JTexture::eTextureType::Png)
    {
        // 내가 원하는 픽셀을 투명화 시킬때
        Gdiplus::ImageAttributes imgAtt = {};
        // 투명화 시킬 픽셀의 색 범위
        imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230)
            , Gdiplus::Color(255,255,255));

        Gdiplus::Graphics graphics(hdc);

        graphics.TranslateTransform(pos.x, pos.y);
        graphics.RotateTransform(rot);
        graphics.TranslateTransform(-pos.x, -pos.y);

        graphics.DrawImage(
            mTexture->GetImage()
            , Gdiplus::Rect
            (
                pos.x - (sprite.size.x / 2.0f)
                , pos.y - (sprite.size.y / 2.0f)
                , sprite.size.x * scale.x
                , sprite.size.y * scale.y
            )
            , sprite.leftTop.x, sprite.leftTop.y
            , sprite.size.x
            , sprite.size.y
            , Gdiplus::UnitPixel
            , nullptr
        );
    }


}

void JAnimation::CreateAnimation(const std::wstring& name
    , graphics::JTexture* spriteSheet, Vector2 leftTop, Vector2 size
    , Vector2 offset, UINT spriteLenth, float duration)
{
    mTexture = spriteSheet;
    for (size_t i = 0; i < spriteLenth; i++)
    {
        Sprite sprite = {};
        sprite.leftTop.x = leftTop.x + (size.x * i);
        sprite.leftTop.y = leftTop.y;
        sprite.size = size;
        sprite.offset = offset;
        sprite.duration = duration;

        mAnimationSheet.push_back(sprite);
    }
}

void JAnimation::Reset()
{
    mTime = 0.0f;
    mIndex = 0;
    mbComplete = false;
}
