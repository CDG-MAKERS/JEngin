#include "JTime.h"
LARGE_INTEGER JTime::CpuFrequency = {};
LARGE_INTEGER JTime::PrevFrequency = {};
LARGE_INTEGER JTime::CurrentFrequency = {};
float JTime::DeltaTimeValue = 0.0f;
void JTime::Initailize()
{
	//cpu 고유 진동수
	QueryPerformanceFrequency(&CpuFrequency);

	//프로그램이 실행될 때 진동수
	QueryPerformanceCounter(&PrevFrequency);



}

void JTime::Update()
{

	//시작부터 끝까지 진동수를 알고싶어
	QueryPerformanceCounter(&CurrentFrequency);
	float differenceFrequency = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

	DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);

	PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
}

void JTime::Render(HDC hdc)
{
	static float time = 0.0f;
	time += DeltaTimeValue;
	float fps = 1.0f / DeltaTimeValue;
	wchar_t str[50] = L"";
	swprintf_s(str, 50,L"%d", (int)fps);
	int len = wcsnlen_s(str, 50);
	TextOut(hdc, 0, 0, str, len);
}
