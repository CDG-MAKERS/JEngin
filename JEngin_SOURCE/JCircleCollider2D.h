#pragma once
#include "JCollider.h"
class JCircleCollider2D : public JCollider
{
public:
	JCircleCollider2D();
	~JCircleCollider2D();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

private:
	float mRadius;
};

