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
	JSceneManager::LateUpdate();
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
	//����� ����
	mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

	//����۸� ����ų dc ����
	mBackHdc = CreateCompatibleDC(mHdc);

	HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
	DeleteObject(oldBitmap);
}
