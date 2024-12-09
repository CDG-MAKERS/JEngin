#include "JInput.h"

//초기화 / static 전역변수와 다르게 0으로 초기화가안됨
std::vector<JInput::Key> JInput::Keys = {};


int ASCII[(UINT)eKeyCode::end] =
{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
};
void JInput::Initailize()
{
	//mKeys.resize((UINT)eKeyCode::end);
	//숫자가 아니므로 형변환
	for (size_t i = 0; i < (UINT)eKeyCode::end; i++)
	{
		Key key = {};
		key.bPressed = false;
		key.state = eKeyState::None;
		key.keyCode = (eKeyCode)i;

		Keys.push_back(key);
	}
}

void JInput::Update()
{
	for (size_t i = 0; i < Keys.size(); i++)
	{
		keyStatus(i);
	}
}

inline void JInput::keyStatus(size_t keyNum)
{
	//키가 눌렀는지 아닌지
	if (GetAsyncKeyState(ASCII[keyNum]) & 0x8000)
	{
		if (Keys[keyNum].bPressed == true)
			Keys[keyNum].state = eKeyState::Pressed;
		else
			Keys[keyNum].state = eKeyState::Down;

		Keys[keyNum].bPressed = true;
	}
	else
	{
		if (Keys[keyNum].bPressed == true)
			Keys[keyNum].state = eKeyState::Up;
		else
			Keys[keyNum].state = eKeyState::None;

		Keys[keyNum].bPressed = false;
	}
}
