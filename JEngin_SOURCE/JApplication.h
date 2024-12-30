#pragma once

#include "JGameObject.h"


class JApplication
{
public:
	JApplication();
	~JApplication();


	void Initialize(HWND hwnd, UINT width, UINT height);
	void Run();

	void Update();
	void LateUpdate();
	void Render();
	void Destroy();
	void Release();

	HWND	GetHwnd()		{ return mHwnd; }
	HDC		GetHdc()		{ return mHdc; }
	UINT	GetWidth()		{ return mWidth; }
	UINT	GetHeight()		{ return mHeight; }
private:
	inline void clearReanderTarget();
	inline void copyReanderTarget(HDC source, HDC dest);
	inline void adjustWindowRect(HWND hwnd, UINT width, UINT height);
	inline void createBuffer(UINT width, UINT height);
private:
	HWND	mHwnd;
	HDC		mHdc;

	HDC		mBackHdc;
	HBITMAP mBackBitmap;	//백버퍼용 플립구조보단 복붙용

	UINT	mWidth;
	UINT	mHeight;
};

