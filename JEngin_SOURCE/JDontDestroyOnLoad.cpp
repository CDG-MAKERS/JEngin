#include "JDontDestroyOnLoad.h"

JDontDestroyOnLoad::JDontDestroyOnLoad()
{
}

JDontDestroyOnLoad::~JDontDestroyOnLoad()
{
}

void JDontDestroyOnLoad::Initialize()
{
	JScene::Initialize();
}

void JDontDestroyOnLoad::Update()
{
	JScene::Update();
}

void JDontDestroyOnLoad::LateUpdate()
{
	JScene::LateUpdate();
}

void JDontDestroyOnLoad::Render(HDC hdc)
{
	JScene::Render(hdc);
}

void JDontDestroyOnLoad::OnEnter()
{
	JScene::OnEnter();
}

void JDontDestroyOnLoad::OnExit()
{
	JScene::OnExit();
}
