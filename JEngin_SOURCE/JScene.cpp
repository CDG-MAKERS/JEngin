#include "JScene.h"

JScene::JScene()
	: mLayers{}
{
	mLayers.resize((UINT)enums::eLayerType::Max);
	for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
	{
		mLayers[i] = new JLayer();
	}
}

JScene::~JScene()
{
}

void JScene::Initialize()
{
	for (JLayer* layer : mLayers)
		layer->Initialize();
}

void JScene::Update()
{
	for (JLayer* layer : mLayers)	//범위기반
		layer->Update();
}

void JScene::LateUpdate()
{
	for (JLayer* layer : mLayers)
		layer->LateUpdate();
}

void JScene::Render(HDC hdc)
{
	for (JLayer* layer : mLayers)
		layer->Render(hdc);
}

void JScene::Destroy()
{

	for (JLayer* layer : mLayers)
	{
		if (layer == nullptr)
			continue;

		layer->Destroy();
	}
}

void JScene::OnEnter()
{
}

void JScene::OnExit()
{
}

void JScene::AddGameObject(JGameObject* gameObj, const enums::eLayerType type)
{
	mLayers[(UINT)type]->AddGameObject(gameObj);
}

