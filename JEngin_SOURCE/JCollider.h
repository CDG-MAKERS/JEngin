#pragma once
#include "JComponent.h"

class JCollider : public JComponent
{
public:
	JCollider();
	~JCollider();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	virtual void OnCollisionEnter(JCollider* other);
	virtual void OnCollisionStay(JCollider* other);
	virtual void OnCollisionExit(JCollider* other);

	Vector2 GetOffset() { return mOffset; }
	void SetOffset(Vector2 offset) { mOffset = offset; }
	UINT32 GetID() { return mID; }
	Vector2 GetSize() { return mSize; }
	void SetSize(Vector2 size) { mSize = size; }

private:
	static UINT CollisionID;

	UINT32 mID;
	Vector2 mOffset;
	Vector2 mSize;

	//Charcater type;
};

