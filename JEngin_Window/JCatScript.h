#pragma once
#include "..//JEngin_SOURCE//JScript.h"
#include "..//JEngin_SOURCE//JTransform.h"

class JCatScript : public JScript
{
public:
	enum class eState
	{
		SitDown,
		Walk,
		Sleep,
		LayDown,
		Attack,
	};

	enum class eDirection
	{
		Left,
		Right,
		Down,
		Up,
		End,
	};

	JCatScript();
	~JCatScript();

	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;

	void SetPlayer(JGameObject* player) { mPlayer = player; }
	Vector2 mDest;
private:
	void idle();
	void move();
	void layDown();

	void PlayWalkAnimationByDirection(eDirection dir);
	void translate(JTransform* tr);

private:
	eState mState;
	class JAnimator* mAnimator;
	eDirection mDirection;
	float mTime;
	float mDeathTime;

	JGameObject* mPlayer;
	float mRadian;
};
