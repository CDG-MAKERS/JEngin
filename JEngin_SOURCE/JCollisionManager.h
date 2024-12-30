#pragma once
#include "CommonInclude.h"
#include "JBoxCollider2D.h"
#include "JCircleCollider2D.h"

using namespace enums;

union CollisionID
{
	struct
	{
		UINT32 left;
		UINT32 right;
	};

	UINT64 id;
};



class JCollisionManager
{
public:
	static void Initialize();
	static void Update();
	static void LateUpdate();
	static void Render(HDC hdc);

	static void CollisionLayerCheck(eLayerType left, eLayerType right, bool enable);
	static void LayerCollision(class Scene* scene, eLayerType left, eLayerType right);
	static void ColliderCollision(JCollider* left, JCollider* right);
	static bool Intersect(JCollider* left, JCollider* right);

private:
	static std::bitset<(UINT)eLayerType::Max> mCollisionLayerMatrix[(UINT)eLayerType::Max];
	static std::unordered_map<UINT64, bool> mCollisionMap;
};

