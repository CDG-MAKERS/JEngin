#pragma once
#include "..//JEngin_SOURCE//JScript.h"
class JPlayerScript : public JScript
{
public:
	JPlayerScript();
	~JPlayerScript();

	virtual void Initialize()		override;
	virtual void Update()			override;
	virtual void LateUpdate()		override;
	virtual void Render(HDC hdc)	override;
private:
};

