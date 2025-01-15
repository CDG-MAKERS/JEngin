#include "JTexture.h"
#include "JApplication.h"
#include "JResources.h"

//해당 전역변수가 존재함을 알림
extern JApplication application;

namespace graphics
{
	JTexture* JTexture::Create(const std::wstring& name, UINT width, UINT height)
	{
		JTexture* image = JResources::Find<JTexture>(name);
		if (image)
			return image;

		image = new JTexture();
		image->SetName(name);
		image->SetWidth(width);
		image->SetHeight(height);

		HDC hdc = application.GetHdc();
		HWND hwnd = application.GetHwnd();

		image->mBitmap = CreateCompatibleBitmap(hdc, width, height);
		image->mHdc = CreateCompatibleDC(hdc);


		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);
		Rectangle(image->mHdc, -1, -1, image->GetWidth() + 1, image->GetHeight() + 1);
		SelectObject(hdc, oldBrush);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
		DeleteObject(oldBitmap);

		JResources::Insert(name + L"Image", image);

		return image;
	}

	JTexture::JTexture()
		:JResource(enums::eResourceType::Texture)
		, mbAlpha(false)
	{
	}

	JTexture::~JTexture()
	{
	}
	HRESULT JTexture::Load(const std::wstring& path)
	{
		//확장자 체크해서 분류
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);

		if (ext == L"bmp")			//bmp 일때
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 
				0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
			if (!mBitmap)
				return S_FALSE;
			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);
			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			if (info.bmBitsPixel == 32)
				mbAlpha = true;
			else if (info.bmBitsPixel == 24)
				mbAlpha = false;

			HDC mainDc = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDc);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(oldBitmap);

		}
		else if (ext == L"png")		//png 일때
		{
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());
			if (mImage == nullptr)
			{
				return S_FALSE;
			}
			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}
		return S_OK;
	}
}