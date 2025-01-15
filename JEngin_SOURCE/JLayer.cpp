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
		JGameObject::eState state = gameObj->GetState();
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
		JGameObject::eState state = gameObj->GetState();
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
		JGameObject::eState state = gameObj->GetState();
		if (state == JGameObject::eState::Paused
			|| state == JGameObject::eState::Dead)
			continue;

		gameObj->Render(hdc);
	}
}

void JLayer::Destroy()
{
	std::vector<JGameObject*> deleteObjects = {};
	findDeadGameObjects(deleteObjects);
	eraseDeadGameObject();
	deleteGameObjects(deleteObjects);
}

void JLayer::AddGameObject(JGameObject* gameObj)
{
	if (!gameObj)
		return;

	mGameObjects.push_back(gameObj);
}

void JLayer::EraseGameObject(JGameObject* eraseGameObj)
{
	// std::erase() iter넣어줘서 해당 이터레이와 같은 객체 삭제
	std::erase_if(mGameObjects,
		[=](JGameObject* gameObj)
		{
			return gameObj == eraseGameObj;
		});
}

void JLayer::findDeadGameObjects(OUT std::vector<JGameObject*>& gameObjs)
{
	for (JGameObject* gameObj : mGameObjects)
	{
		JGameObject::eState active = gameObj->GetState();
		if (active == JGameObject::eState::Dead)
			gameObjs.push_back(gameObj);
	}
}

void JLayer::deleteGameObjects(std::vector<JGameObject*> deleteObjs)
{
	for (JGameObject* obj : deleteObjs)
	{
		delete obj;
		obj = nullptr;
	}
}

void JLayer::eraseDeadGameObject()
{
	std::erase_if(mGameObjects,
		[](JGameObject* gameObj)
		{
			return (gameObj)->IsDead();
		});
}
