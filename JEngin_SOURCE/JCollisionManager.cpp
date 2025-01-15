#include "JCollisionManager.h"
#include "JScene.h"
#include "JSceneManager.h"
#include "JGameObject.h"
#include "JCollider.h"
#include "JTransform.h"


std::bitset<(UINT)eLayerType::Max> JCollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::Max] = {};
std::unordered_map<UINT64, bool> JCollisionManager::mCollisionMap = {};


void JCollisionManager::Initialize()
{
	int a = 1;
	int b = a << 1;
}

void JCollisionManager::Update()
{
	JScene* scene = JSceneManager::GetActiveScene();
	for (UINT row = 0; row < (UINT)eLayerType::Max; row++)
	{
		for (UINT col = 0; col < (UINT)eLayerType::Max; col++)
		{
			if (mCollisionLayerMatrix[row][col] == true)
			{
				LayerCollision(scene, (eLayerType)row, (eLayerType)col);
			}
		}
	}
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
			JCollider* rightCol = right->GetComponent<JCollider>();
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
	// 두 충돌체 번호로 가져온 ID 확인하여 CollisionID 세팅
	CollisionID id = {};
	id.left = left->GetID();
	id.right = right->GetID();

	// 이전 충돌 정보를 검색한다.
	// 만약에 충돌정보가 없는 상태라면
	// 충돌정보를 생성해준다.

	auto iter = mCollisionMap.find(id.id);
	if (iter == mCollisionMap.end())
	{
		mCollisionMap.insert(std::make_pair(id.id, false));
		iter = mCollisionMap.find(id.id);
	}

	// 충돌 체크를 해준다
	if (Intersect(left, right))
	{
		//최초 충돌할
		if (iter->second == false)
		{
			left->OnCollisionEnter(right);
			right->OnCollisionEnter(left);
			iter->second = true;
		}
		else // 이미 충돌 중
		{
			left->OnCollisionStay(right);
			right->OnCollisionStay(left);
		}
	}
	else
	{
		//충돌을 하지 않은 상태
		if (iter->second == true)
		{
			left->OnCollisionExit(right);
			right->OnCollisionExit(left);

			iter->second = false;
		}
	}
}

bool JCollisionManager::Intersect(JCollider* left, JCollider* right)
{
	JTransform* leftTr = left->GetOwner()->GetComponent<JTransform>();
	JTransform* rightTr = right->GetOwner()->GetComponent<JTransform>();

	Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
	Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();

	// size 1,1 일 기본크기가 100픽셀
	Vector2 leftSize = left->GetSize() * 100.0f;
	Vector2 rightSize = right->GetSize() * 100.0f;

	//AABB 충돌
	enums::eColliderType leftType = left->GetColliderType();
	enums::eColliderType rightType = right->GetColliderType();

	if (leftType == enums::eColliderType::Rect2D
		&& rightType == enums::eColliderType::Rect2D)
	{
		if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
			&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
		{
			return true;
		}
	}
	if (leftType == enums::eColliderType::Circle2D
		&& rightType == enums::eColliderType::Circle2D)
	{
		//circle -circle
		Vector2 leftCirclePos = leftPos + (leftSize / 2.0f);
		Vector2 rightCirclePos = rightPos + (rightSize / 2.0f);
		float distance = (leftCirclePos - rightCirclePos).length();
		if (distance <= (leftSize.x / 2.0f + rightSize.x / 2.0f))
		{
			return true;
		}
	}

	if ((leftType == enums::eColliderType::Circle2D && rightType == enums::eColliderType::Rect2D)
		|| (leftType == enums::eColliderType::Rect2D && rightType == enums::eColliderType::Circle2D))
	{
		// circle - rect
		// 숙제

	}


	return false;
}