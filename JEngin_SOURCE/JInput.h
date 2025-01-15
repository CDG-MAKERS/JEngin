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
	Q, W, e, r, t, y, u, i, o, p, A, S, D, f, g, h, j, k, l, z, x, c, v, b, n, m,
	Left, Right, Down, Up, 
	LButton, MButton, RButton, 
	end
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

	//static void keyStatus();

	static bool GetKeyDown(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Down; }
	static bool GetKeyUp(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Up; }
	static bool GetKey(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Pressed; }
	static JMath::Vector2 GetMousePosition() { return mMousePosition; }

private:
	static void createKeys();
	static void updateKeys();
	static void updateKey(JInput::Key& key);
	static bool isKeyDown(eKeyCode code);
	static void updateKeyDown(JInput::Key& key);
	static void updateKeyUp(JInput::Key& key);
	static void getMousePositionByWindow();
	static void clearKeys();

private:
	static std::vector<Key> Keys;
	static JMath::Vector2	mMousePosition;
};