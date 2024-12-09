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
	for (JGameObject* gameObj : mGameObjects)	//�������
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
