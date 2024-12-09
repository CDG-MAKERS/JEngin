#include "JSceneManager.h"

std::map<const std::wstring, JScene*> JSceneManager::mScene = {};
JScene* JSceneManager::mActiveScene = nullptr;

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
