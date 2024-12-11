#include "JSceneManager.h"

std::map<const std::wstring, JScene*> JSceneManager::mScene = {};
JScene* JSceneManager::mActiveScene = nullptr;

JSceneManager::JSceneManager()
{
}

JSceneManager::~JSceneManager()
{
}

JScene* JSceneManager::LoadScene(const std::wstring& name)
{
	if (mActiveScene)
		mActiveScene->OnExit();

	std::map<const std::wstring, JScene*>::iterator iter
		= mScene.find(name);
	if (iter == mScene.end())
		return nullptr;

	mActiveScene = iter->second;
	mActiveScene->OnEnter();
	return iter->second;

}

void JSceneManager::Initialize()
{
	//mActiveScene->Initialize();
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
