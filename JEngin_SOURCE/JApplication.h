#pragma once

#include "CommonInclude.h"


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

private:
	inline void clearReanderTarget();
	inline void copyReanderTarget(HDC source, HDC dest);
	inline void adjustWindowRect(HANDLE hwnd, UINT width, UINT height);

private:
	HWND	mHwnd;
	HDC		mHdc;

	HDC		mBackHdc;
	HBITMAP mBackBitmap;	//백버퍼용 플립구조보단 복붙용

	UINT	mWidth;
	UINT	mHeight;


	//std::vector<JGameObject*>	mGameObjects;
	//std::vector<SceneMenager*> mSceneMenager
};

