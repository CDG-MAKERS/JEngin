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

	void SetPosition(Vector2 position)	{ mPosition.x = position.x; mPosition.y = position.y; }
	Vector2 GetPosition()		{ return mPosition; }

private:
	Vector2 mPosition;
};

