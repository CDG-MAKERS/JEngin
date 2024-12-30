#include "JLayer.h"

JLayer::JLayer()
	:mGameObjects{}
{
}

JLayer::~JLayer()
{
	for (JGameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		delete gameObj;
		gameObj = nullptr;
	}
}

void JLayer::Initialize()
{
	for (JGameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->Initialize();
	}
}

void JLayer::Update()
{
	for (JGameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;
		JGameObject::eState state = gameObj->GetActive();
		if (state == JGameObject::eState::Paused
			|| state == JGameObject::eState::Dead)
			continue;

		gameObj->Update();
	}
}

void JLayer::LateUpdate()
{
	for (JGameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;
		JGameObject::eState state = gameObj->GetActive();
		if (state == JGameObject::eState::Paused
			|| state == JGameObject::eState::Dead)
			continue;

		gameObj->LateUpdate();
	}
}

void JLayer::Render(HDC hdc)
{
	for (JGameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;
		JGameObject::eState state = gameObj->GetActive();
		if (state == JGameObject::eState::Paused
			|| state == JGameObject::eState::Dead)
			continue;

		gameObj->Render(hdc);
	}
}

void JLayer::Destroy()
{
	for (GameObjectIter iter = mGameObjects.begin()
		; iter != mGameObjects.end()
		; )
	{
		JGameObject::eState active = (*iter)->GetActive();
		if (active == JGameObject::eState::Dead)
		{
			JGameObject* deathObj = (*iter);
			iter = mGameObjects.erase(iter);

			delete deathObj;
			deathObj = nullptr;

			continue;
		}

		iter++;
	}
}

void JLayer::AddGameObject(JGameObject* gameObj)
{
	if (!gameObj)
		return;

	mGameObjects.push_back(gameObj);
}
