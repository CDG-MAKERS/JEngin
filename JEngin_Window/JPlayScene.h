#pragma once
#include "..//JEngin_SOURCE//JScene.h"
class JPlayScene : public JScene
{
public:
	JPlayScene();
	~JPlayScene();

	void Initialize()		override;
	void Update()			override;
	void LateUpdate()		override;
	void Render(HDC hdc)	override;
private:
};

