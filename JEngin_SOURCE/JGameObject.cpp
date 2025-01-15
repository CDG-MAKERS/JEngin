#include "JGameObject.h"
#include "JInput.h"
#include "JTime.h"
#include "JTransform.h"
JGameObject::JGameObject()
	: mState(eState::Active)
	, mLayerType(eLayerType::None)
{
	mComponents.resize((UINT)enums::eComponentType::End);
	initializeTransform();
}
JGameObject::~JGameObject()
{
	//오브젝트가 날라갈때 할당 해제
	for (JComponent* comp : mComponents)
	{
		if (comp == nullptr)
			continue;
		delete comp;
		comp = nullptr;	//디버깅 체크
	}
}

void JGameObject::Initialize()
{
	for (JComponent* comp : mComponents)
	{
		if (comp == nullptr) continue;
		comp->Initialize();
	}

}

void JGameObject::Update()
{
	for (JComponent* comp : mComponents)
	{
		if (comp == nullptr) continue;
		comp->Update();
	}

}
void JGameObject::LateUpdate()
{
	for (JComponent* comp : mComponents)
	{
		if (comp == nullptr) continue;
		comp->LateUpdate();
	}
}

void JGameObject::Render(HDC hdc)
{
	for (JComponent* comp : mComponents)
	{
		if (comp == nullptr) continue;
		comp->Render(hdc);
	}
}

void JGameObject::Destroy()
{
	std::vector<JGameObject*> deleteObjects = {};
	//findDeadGameObjects(deleteObjects);
	//eraseGameObject();
	//deleteGameObjects(deleteObjects);
}

void JGameObject::initializeTransform()
{
	AddComponent<JTransform>();
}