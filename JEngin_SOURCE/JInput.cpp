#include "JInput.h"
#include "JApplication.h"

extern JApplication application;

//초기화 / static 전역변수와 다르게 0으로 초기화가안됨
std::vector<JInput::Key> JInput::Keys = {};

JMath::Vector2 JInput::mMousePosition = JMath::Vector2::One;

int ASCII[(UINT)eKeyCode::end] =
{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON,
};
void JInput::Initailize()
{
	createKeys();
}


void JInput::Update()
{
	updateKeys();

}


void JInput::createKeys()
{
	for (size_t i = 0; i < (UINT)eKeyCode::end; i++)
	{
		Key key = {};
		key.bPressed = false;
		key.state = eKeyState::None;
		key.keyCode = (eKeyCode)i;

		Keys.push_back(key);
	}
}	


void JInput::updateKeys()
{
	std::for_each(Keys.begin(), Keys.end(), [](Key& key) -> void 
		{ 
			updateKey(key); 
		});
}

void JInput::updateKey(JInput::Key& key)
{
	if (GetFocus()) //포커스 창 체크
	{
		if (isKeyDown(key.keyCode))
			updateKeyDown(key);
		else
			updateKeyUp(key);

		getMousePositionByWindow();
	}
	else
	{
		clearKeys();
	}
	//키가 눌렀는지 아닌지
	/*if (GetAsyncKeyState(ASCII[keyNum]) & 0x8000)
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
	}*/
}

bool JInput::isKeyDown(eKeyCode code)
{
	return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
}

void JInput::updateKeyDown(JInput::Key& key)
{
	if (key.bPressed == true)
		key.state = eKeyState::Pressed;
	else
		key.state = eKeyState::Down;

	key.bPressed = true;
}

void JInput::updateKeyUp(JInput::Key& key)
{
	if (key.bPressed == true)
		key.state = eKeyState::Up;
	else
		key.state = eKeyState::None;

	key.bPressed = false;
}

void JInput::getMousePositionByWindow()
{
	POINT mousePos = { };
	GetCursorPos(&mousePos);
	ScreenToClient(application.GetHwnd(), &mousePos);

	mMousePosition.x = mousePos.x;
	mMousePosition.y = mousePos.y;
}

void JInput::clearKeys()
{
	for (Key& key : Keys)
	{
		if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
			key.state = eKeyState::Up;
		else if (key.state == eKeyState::Up)
			key.state = eKeyState::None;

		key.bPressed = false;
	}
}
