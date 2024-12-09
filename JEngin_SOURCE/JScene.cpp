#include "JScene.h"

JScene::JScene()
{
}

JScene::~JScene()
{
}

void JScene::Initialize()
{
}

void JScene::Update()
{
	for (JGameObject* gameObj : mGameObjects)	//범위기반
		gameObj->Update();
}

void JScene::LateUpdate()
{
	for (JGameObject* gameObj : mGameObjects)
		gameObj->LateUpdate();
}

void JScene::Render(HDC hdc)
{
	for (JGameObject* gameObj : mGameObjects)
		gameObj->Render(hdc);
}
