#pragma once
#include "CommonInclude.h"

enum class eKeyState
{
	Down,
	Pressed,
	Up,
	None,
};

enum class eKeyCode
{
	q, w, e, r, t, y, u, i, o, p, a, s, d, f, g, h, j, k, l, z, x, c, v, b, n, m,
	Left, Right, Down, Up, end
};

class JInput
{
public:
	struct Key
	{
		eKeyCode keyCode;
		eKeyState state;
		bool bPressed;
	};


	static void Initailize();
	static void Update();

	//static void KeyUsing();

	static bool GetKeyDown(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Down; }
	static bool GetKeyUp(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Up; }
	static bool GetKey(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Pressed; }
private:
	static std::vector<Key> Keys;
};