#pragma once
#include "CommonInclude.h"

//Actor
class JGameObject 
{
public:
	JGameObject();
	~JGameObject();

	void SetPosition(int x, int y)
	{
		mX = x;
		mY = y;
	}

	int GetPositionX() { return mX; }
	int GetPositionY() { return mY; }

	void Update();
	void LateUpdate();
	void Render(HDC hdc);
	
private:
	float mX;
	float mY;
	int mSpeed;
};

