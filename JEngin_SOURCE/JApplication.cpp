#include "JApplication.h"
#include "JInput.h"
#include "JTime.h"
#include "JSceneManager.h"
#include "JResources.h"
#include "JCollisionManager.h"

JApplication::JApplication()
	: mHwnd(nullptr)
	, mHdc(nullptr)
	, mWidth(0)
	, mHeight(0)
	, mBackHdc(nullptr)
	, mBackBitmap(nullptr)
{
}

JApplication::~JApplication()
{
}

void JApplication::Initialize(HWND hwnd, UINT width,UINT height)
{
	adjustWindowRect(hwnd, width, height);
	createBuffer(width, height);

	JInput::Initailize();
	JTime::Initailize();

	JCollisionManager::Initialize();
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
	JCollisionManager::Update();
	JSceneManager::Update();
}
void JApplication::LateUpdate()
{
	JCollisionManager::LateUpdate();
	JSceneManager::LateUpdate();
}
void JApplication::Render()
{
	clearReanderTarget();

	JTime::Render(mBackHdc);

	JCollisionManager::Render(mBackHdc);
	JSceneManager::Render(mBackHdc);

	copyReanderTarget(mBackHdc, mHdc);
}

void JApplication::Destroy()
{
	JSceneManager::Destroy();
}

void JApplication::Release()
{
	//JSceneManager::Release();	
	//JResources::Release();
}

inline void JApplication::clearReanderTarget()
{
	HBRUSH grayBrush = (HBRUSH)CreateSolidBrush(RGB(128, 128, 128));
	HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, grayBrush);
	Rectangle(mBackHdc, -1, -1, 1601, 901);

	(HBRUSH)SelectObject(mBackHdc, oldBrush);
	DeleteObject(grayBrush);
}

inline void JApplication::copyReanderTarget(HDC source, HDC dest)
{
	BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
}

inline void JApplication::adjustWindowRect(HWND hwnd, UINT width, UINT height)
{
	mHwnd = hwnd;
	mHdc = GetDC(hwnd);
	RECT rect = { 0, 0, width, height };

	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
	mWidth = rect.right - rect.left, mHeight = rect.bottom - rect.top;
	SetWindowPos(mHwnd, nullptr, 0, 0, mWidth,
		mHeight, 0);
	ShowWindow(mHwnd, true);
}
inline void JApplication::createBuffer(UINT width, UINT height)
{
	//백버퍼 생성
	mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

	//백버퍼를 가리킬 dc 생성
	mBackHdc = CreateCompatibleDC(mHdc);

	HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
	DeleteObject(oldBitmap);
}
