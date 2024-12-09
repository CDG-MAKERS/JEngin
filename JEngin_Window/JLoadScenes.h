#pragma once
#include "..//JEngin_SOURCE//JSceneManager.h"
#include "JPlayScene.h"
void JLoadScenes()
{
	JSceneManager::CreateScene<JPlayScene>(L"PlayScene");


	JSceneManager::LoadScene(L"PlayScene");
}