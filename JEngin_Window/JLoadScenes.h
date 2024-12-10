#pragma once
#include "..//JEngin_SOURCE//JSceneManager.h"
#include "JPlayScene.h"
#include "JTitleScene.h"
void JLoadScenes()
{
	JSceneManager::CreateScene<JTitleScene>(L"TitleScene");
	JSceneManager::CreateScene<JPlayScene>(L"PlayScene");


	JSceneManager::LoadScene(L"TitleScene");
}