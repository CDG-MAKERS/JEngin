#pragma once
#include "..//JEngin_SOURCE//JScene.h"
class JDontDestroyOnLoad : public JScene
{
public:
	JDontDestroyOnLoad();
	~JDontDestroyOnLoad();

	void Initialize()		override;
	void Update()			override;
	void LateUpdate()		override;
	void Render(HDC hdc)	override;

	void OnEnter()			override;
	void OnExit()			override;

private:
};

