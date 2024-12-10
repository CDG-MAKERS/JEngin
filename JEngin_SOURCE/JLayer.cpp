#include "JLayer.h"

JLayer::JLayer()
	:mGameObjects{}
{
}

JLayer::~JLayer()
{
}

void JLayer::Initialize()
{
	for (JGameObject* gameObj : mGameObjects)
		gameObj->Initialize();
}

void JLayer::Update()
{
	for (JGameObject* gameObj : mGameObjects)
		gameObj->Update();
}

void JLayer::LateUpdate()
{
	for (JGameObject* gameObj : mGameObjects)
		gameObj->LateUpdate();
}

void JLayer::Render(HDC hdc)
{
	for (JGameObject* gameObj : mGameObjects)
		gameObj->Render(hdc);
}

void JLayer::AddGameObject(JGameObject* gameObj)
{
	if (!gameObj)
		return;

	mGameObjects.push_back(gameObj);
}
