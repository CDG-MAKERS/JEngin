#pragma once
#include "JCollider.h"
class JBoxCollider2D : public JCollider
{
public:
	JBoxCollider2D();
	~JBoxCollider2D();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

private:
};

