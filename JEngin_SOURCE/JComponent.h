#pragma once

#include "JEntity.h"

class JGameObject;	//순환참조 조심
class JComponent : public JEntity
{

public:
	JComponent();
	~JComponent();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	void SetOwner(JGameObject* owner)	{ mOwner = owner; }
	JGameObject* GetOwner()				{ return mOwner; }
private:
	JGameObject* mOwner;
};

