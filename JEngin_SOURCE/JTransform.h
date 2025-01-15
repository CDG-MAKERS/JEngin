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
	float	GetRoation()		{ return mRoation; }
	Vector2 GetScale()			{ return mScale; }
	void SetRotation(float rotate) { mRoation = rotate; }
	void SetScale(Vector2 scale) { mScale = scale; }


private:
	Vector2 mPosition;
	Vector2 mScale;
	float	mRoation;
};

