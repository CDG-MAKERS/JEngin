#include "JTexture.h"
#include "JApplication.h"

//�ش� ���������� �������� �˸�
extern JApplication application;

namespace graphcis
{

	JTexture::JTexture()
		:JResource(enums::eResourceType::Texture)
	{
	}

	JTexture::~JTexture()
	{
	}
	HRESULT JTexture::Load(const std::wstring& path)
	{
		//Ȯ���� üũ�ؼ� �з�
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);

		if (ext == L"bmp")			//bmp �϶�
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

			HDC mainDc = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDc);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(oldBitmap);

		}
		else if (ext == L"png")		//png �϶�
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