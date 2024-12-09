#include "JInput.h"

//�ʱ�ȭ / static ���������� �ٸ��� 0���� �ʱ�ȭ���ȵ�
std::vector<JInput::Key> JInput::Keys = {};


int ASCII[(UINT)eKeyCode::end] =
{
		'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'D', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP
};
void JInput::Initailize()
{
	//mKeys.resize((UINT)eKeyCode::end);
	//���ڰ� �ƴϹǷ� ����ȯ
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
		//Ű�� �������� �ƴ���
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
