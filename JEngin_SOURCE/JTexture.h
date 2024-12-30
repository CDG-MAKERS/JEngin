#pragma once
#include "JResource.h"


namespace graphics
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

		static JTexture* Create(const std::wstring& name, UINT width, UINT height);

		JTexture();
		~JTexture();

		virtual HRESULT Load(const std::wstring& path) override;

		UINT	GetWidth() { return mWidth; }
		void	SetWidth(UINT width) { mWidth = width; }
		UINT	GetHeight() { return mHeight; }
		void	SetHeight(UINT height) { mHeight = height; }
		HDC		GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }
		bool IsAlpha() { return mbAlpha; }

	private:
		bool mbAlpha;
		eTextureType mType;
		Gdiplus::Image* mImage;		//32
		HBITMAP mBitmap;			//24
		HDC		mHdc;

		UINT mWidth;
		UINT mHeight;
	};
}
