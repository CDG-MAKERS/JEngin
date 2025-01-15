#pragma once
#include "JComponent.h"
#include "JGameObject.h"
#include "JLayer.h"
#include "JScene.h"
#include "JSceneManager.h"
#include "JTransform.h"

namespace object
{
	template <typename T>
	static T* Instantiate(enums::eLayerType type)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);
		JScene* activeScene = JSceneManager::GetActiveScene();
		JLayer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(enums::eLayerType type, JMath::Vector2 position)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);
		JScene* activeScene = JSceneManager::GetActiveScene();
		JLayer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		JTransform* tr = gameObject->GetComponent<JTransform>();
		tr->SetPosition(position);

		return gameObject;
	}

	static void DontDestroyOnLoad(JGameObject* gameObject)
	{
		JScene* activeScene = JSceneManager::GetActiveScene();
		// 현재씬에서 게임오브젝트를 지워준다.
		activeScene->EraseGameObject(gameObject);
		// 해당 게임오브젝트를 -> DontDestroy씬으로 넣어준다.
		JScene* dontDestroyOnLoad = JSceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(gameObject, gameObject->GetLayerType());
	}
}