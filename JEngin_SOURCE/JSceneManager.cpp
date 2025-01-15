#include "JSceneManager.h"
#include "JDontDestroyOnLoad.h"
std::map<const std::wstring, JScene*> JSceneManager::mScene = {};
JScene* JSceneManager::mActiveScene = nullptr;
JScene* JSceneManager::mDontDestroyOnLoad = nullptr;

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
	mDontDestroyOnLoad = CreateScene<JDontDestroyOnLoad>(L"DontDestroyOnLoad");
}

void JSceneManager::Update()
{
	mActiveScene->Update();
	mDontDestroyOnLoad->Update();
}

void JSceneManager::LateUpdate()
{
	mActiveScene->LateUpdate();
	mDontDestroyOnLoad->LateUpdate();

}

void JSceneManager::Render(HDC hdc)
{
	mActiveScene->Render(hdc);
	mDontDestroyOnLoad->Render(hdc);

}

void JSceneManager::Destroy()
{
	mActiveScene->Destroy();
	mDontDestroyOnLoad->Destroy();

}

void JSceneManager::Release()
{
	for (auto& iter : mScene)
	{
		delete iter.second;
		iter.second = nullptr;
	}
}
