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
		JScene* activeScene = JSceneManager::GetActiveScene();
		JLayer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(enums::eLayerType type, JMath::Vector2 position)
	{
		T* gameObject = new T();
		JScene* activeScene = JSceneManager::GetActiveScene();
		JLayer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		JTransform* tr = gameObject->GetComponent<JTransform>();
		tr->SetPosition(position);

		return gameObject;
	}
}