#pragma once
#include "JComponent.h"

//작성로직 실행
class JScript : public JComponent
{
public:
	JScript();
	~JScript();

	virtual void Initialize()		override;
	virtual void Update()			override;
	virtual void LateUpdate()		override;
	virtual void Render(HDC hdc)	override;

	virtual void OnCollisionEnter(class JCollider* other);
	virtual void OnCollisionStay(class JCollider* other);
	virtual void OnCollisionExit(class JCollider* other);
private:

};

