#pragma once
#include "JScene.h"
class JSceneManager
{
public:

	JSceneManager();
	~JSceneManager();
	static void Initialize();
	static void Update();
	static void LateUpdate();
	static void Render(HDC hdc);
private:

	static std::vector<JScene*> mScene;
	static JScene* mActiveScene;
};

