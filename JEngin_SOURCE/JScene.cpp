#include "JScene.h"

JScene::JScene()
	: mLayers{}
{
	mLayers.resize((UINT)eLayerType::Max);
	for (size_t i = 0; i < (UINT)eLayerType::Max; i++)
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

void JScene::OnEnter()
{
}

void JScene::OnExit()
{
}

void JScene::AddGameObject(JGameObject* gameObj, const eLayerType type)
{
	mLayers[(UINT)type]->AddGameObject(gameObj);
}

