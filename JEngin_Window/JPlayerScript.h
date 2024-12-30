#pragma once
#include "..//JEngin_SOURCE//JScript.h"
class JPlayerScript : public JScript
{
public:
	enum class eState
	{
		SitDown,
		Walk,
	//	Sleep,
	//	Attack,
	};

	JPlayerScript();
	~JPlayerScript();

	virtual void Initialize()		override;
	virtual void Update()			override;
	virtual void LateUpdate()		override;
	virtual void Render(HDC hdc)	override;
private:
	void move();
	void sitDown();
private:
	eState mState;
	class JAnimator* mAnimator;
};

