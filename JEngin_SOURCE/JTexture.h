#pragma once
#include "JResource.h"


namespace graphcis
{
	class JTexture : public JResource
	{
	public:
		enum class eTextureType
		{
			Bmp,
			Png,
			None,
		};

		JTexture();
		~JTexture();

		virtual HRESULT Load(const std::wstring& path) override;

		UINT	GetWidth() { return mWidth; }
		UINT	GetHeight() { return mHeight; }
		HDC		GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }

	private:
		eTextureType mType;

		Gdiplus::Image* mImage;		//32
		HBITMAP mBitmap;			//24
		HDC		mHdc;

		UINT mWidth;
		UINT mHeight;
	};
}
