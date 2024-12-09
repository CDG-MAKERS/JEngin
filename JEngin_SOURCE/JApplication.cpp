#include "JApplication.h"
#include "JInput.h"
#include "JTime.h"
#include "JSceneManager.h"
JApplication::JApplication()
	: mHwnd(nullptr)
	, mHdc(nullptr)
	, mWidth(0)
	, mHeight(0)
	, mBackHdc(nullptr)
	, mBackBitmap(nullptr)
	, 
{
}
JApplication::~JApplication()
{
}
void JApplication::Initialize(HWND hwnd, UINT width,UINT height)
{
	mHwnd = hwnd;
	mHdc = GetDC(hwnd);
	RECT rect = { 0, 0, width, height };

	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
	mWidth = rect.right - rect.left, mHeight = rect.bottom - rect.top;
	SetWindowPos(mHwnd, nullptr, 0, 0, mWidth,
		mHeight, 0 );
	ShowWindow(mHwnd, true);

	//백버퍼 생성
	mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

	//백버퍼를 가리킬 dc 생성
	mBackHdc = CreateCompatibleDC(mHdc);

	HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
	DeleteObject(oldBitmap);

	JInput::Initailize();
	JTime::Initailize();

	JSceneManager::Initialize();
}
void JApplication::Run()
{
	Update();
	LateUpdate();
	Render();
}
void JApplication::Update()
{

	JInput::Update();
	JTime::Update();
	JSceneManager::Update();

}
void JApplication::LateUpdate()
{
}
void JApplication::Render()
{
	clearReanderTarget();

	JTime::Render(mBackHdc);
	JSceneManager::Render(mBackHdc);

	copyReanderTarget(mBackHdc, mHdc);
}

inline void JApplication::clearReanderTarget()
{
	Rectangle(mBackHdc, -1, -1, 1601, 901);
}

inline void JApplication::copyReanderTarget(HDC source, HDC dest)
{
	BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
}

inline void JApplication::adjustWindowRect(HANDLE hwnd, UINT width, UINT height)
{
}
