#include "JInput.h"

//초기화 / static 전역변수와 다르게 0으로 초기화가안됨
std::vector<JInput::Key> JInput::Keys = {};


int ASCII[(UINT)eKeyCode::end] =
{
		'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'D', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP
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
		//키가 눌렀는지 아닌지
		if (GetAsyncKeyState(ASCII[i]) & 0x8000)
		{
			if (Keys[i].bPressed == true)
				Keys[i].state = eKeyState::Pressed;
			else
				Keys[i].state = eKeyState::Down;

			Keys[i].bPressed = true;
		}
		else
		{
			if (Keys[i].bPressed == true)
				Keys[i].state = eKeyState::Up;
			else
				Keys[i].state = eKeyState::None;

			Keys[i].bPressed = false;
		}
	}
}
