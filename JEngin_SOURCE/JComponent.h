#pragma once

#include "JEntity.h"
using namespace enums;

class JGameObject;	//순환참조 조심
class JComponent : public JEntity
{

public:
	JComponent(enums::eComponentType type);
	JComponent() = delete;
	~JComponent();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	void SetOwner(JGameObject* owner)	{ mOwner = owner; }
	JGameObject* GetOwner()				{ return mOwner; }
	enums::eComponentType GetType() { return mType; }
private:
	JGameObject* mOwner;
	enums::eComponentType mType;
};

