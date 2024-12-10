#pragma once
#include "..//JEngin_SOURCE//JScene.h"
class JTitleScene : public JScene
{
public:
	JTitleScene();
	~JTitleScene();

	void Initialize()		override;
	void Update()			override;
	void LateUpdate()		override;
	void Render(HDC hdc)	override;
};

