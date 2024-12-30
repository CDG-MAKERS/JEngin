#include "JCollisionManager.h"
#include "JScene.h"
#include "JSceneManager.h"
#include "JGameObject.h"
#include "JCollider.h"
#include "JTransform.h"

void JCollisionManager::Initialize()
{
}

void JCollisionManager::Update()
{
}

void JCollisionManager::LateUpdate()
{
}

void JCollisionManager::Render(HDC hdc)
{
}

void JCollisionManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
{
	int row = 0;
	int col = 0;

	if (left <= right)
	{
		row = (UINT)left;
		col = (UINT)right;
	}
	else
	{
		row = (UINT)right;
		col = (UINT)left;
	}
	mCollisionLayerMatrix[row][col] = enable;
}

void JCollisionManager::LayerCollision(JScene* scene, eLayerType left, eLayerType right)
{
	const std::vector<JGameObject*>& lefts = scene->GetLayer(left)->GetGameObjects();
	const std::vector<JGameObject*>& rights = scene->GetLayer(right)->GetGameObjects();

	for (JGameObject* left : lefts)
	{
		if (left->IsActive() == false)
			continue;
		JCollider* leftCol = left->GetComponent<JCollider>();
		if (leftCol == nullptr)
			continue;

		for (JGameObject* right : rights)
		{
			if (right->IsActive() == false)
				continue;
			Collider* rightCol = right->GetComponent<Collider>();
			if (rightCol == nullptr)
				continue;
			if (left == right)
				continue;

			ColliderCollision(leftCol, rightCol);
		}

	}
}

void JCollisionManager::ColliderCollision(JCollider* left, JCollider* right)
{
}

bool JCollisionManager::Intersect(JCollider* left, JCollider* right)
{
	return false;
}
