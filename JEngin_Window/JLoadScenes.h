#pragma once
#include "..//JEngin_SOURCE//JSceneManager.h"
#include "JPlayScene.h"
#include "JTitleScene.h"
#include "JToolScene.h"


void JLoadScenes()
{
	JSceneManager::CreateScene<JTitleScene>(L"TitleScene");
	JSceneManager::CreateScene<JPlayScene>(L"PlayScene");
	JSceneManager::CreateScene<JToolScene>(L"ToolScene");
	//JSceneManager::LoadScene(L"ToolScene");
	JSceneManager::LoadScene(L"PlayScene");
}