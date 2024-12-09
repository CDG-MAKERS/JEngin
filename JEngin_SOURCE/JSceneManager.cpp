#include "JSceneManager.h"

JSceneManager::JSceneManager()
{
}

JSceneManager::~JSceneManager()
{
}

void JSceneManager::Initialize()
{
}

void JSceneManager::Update()
{
	mActiveScene->Update();
}

void JSceneManager::LateUpdate()
{
	mActiveScene->LateUpdate();
}

void JSceneManager::Render(HDC hdc)
{
	mActiveScene->Render(hdc);
}
