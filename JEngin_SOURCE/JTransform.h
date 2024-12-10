#pragma once
#include "JEntity.h"
#include "JComponent.h"

using namespace JMath;
class JTransform : public JComponent
{
public:
	JTransform();
	~JTransform();

	void Initialize()		override;
	void Update()			override;
	void LateUpdate()		override;
	void Render(HDC hdc)	override;

	void SetPos(Vector2 pos)	{ mPosition.x = pos.x; mPosition.y = pos.y; }
	Vector2 GetPosition()		{ return mPosition; }

private:
	Vector2 mPosition;
};

