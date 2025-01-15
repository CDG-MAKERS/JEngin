#pragma once
#include "..//JEngin_SOURCE//JScript.h"
class JPlayerScript : public JScript
{
public:
	enum class eState
	{
		Idle,
		Walk,
		Sleep,
		GiveWater,
		Attack,
	};

	JPlayerScript();
	~JPlayerScript();

	virtual void Initialize()		override;
	virtual void Update()			override;
	virtual void LateUpdate()		override;
	virtual void Render(HDC hdc)	override;

	void AttackEffect();

	void OnCollisionEnter(JCollider* other) override;
	void OnCollisionStay(JCollider* other) override;
	void OnCollisionExit(JCollider* other) override;
private:
	void move();
	void idle();
private:
	eState mState;
	class JAnimator* mAnimator;
};

