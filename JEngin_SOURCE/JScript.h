#pragma once
#include "JComponent.h"

//�ۼ����� ����
class JScript : public JComponent
{
public:
	JScript();
	~JScript();

	virtual void Initialize()		override;
	virtual void Update()			override;
	virtual void LateUpdate()		override;
	virtual void Render(HDC hdc)	override;
private:

};

