#pragma once
#include "JEntity.h"
#include "JComponent.h"

struct JPos
{
	int mX;
	int mY;
};
class JTransform : public JComponent
{
public:
	JTransform();
	~JTransform();

	void Initialize()		override;
	void Update()			override;
	void LateUpdate()		override;
	void Render(HDC hdc)	override;

	void SetPos(int x, int y)	{ mX = x; mY = y; }
	int GetX()					{ return mX; }
	int GetY()					{ return mY; }
private:
	int mX;
	int mY;
};

