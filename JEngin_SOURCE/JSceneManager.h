#pragma once
#include "JScene.h"
class JSceneManager
{
public:

	JSceneManager();
	~JSceneManager();
	template <typename T>
	static JScene* CreateScene(const std::wstring& name)
	{
		T* scene = new T();
		scene->SetName(name);
		mActiveScene = scene;
		scene->Initialize();

		mScene.insert(std::make_pair(name, scene));

		return scene;
	}

	static JScene* LoadScene(const std::wstring& name);
	static JScene* GetActiveScene() { return mActiveScene; }
	static JScene* GetDontDestroyOnLoad() { return mDontDestroyOnLoad; }

	static void Initialize();
	static void Update();
	static void LateUpdate();
	static void Render(HDC hdc);
	static void Destroy();
	static void Release();

private:
	static std::map<const std::wstring, JScene*> mScene;
	static JScene* mActiveScene;
	static JScene* mDontDestroyOnLoad;
};

