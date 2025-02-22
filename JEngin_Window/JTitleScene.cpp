#include "JTitleScene.h"
#include "JInput.h"
#include "JPlayScene.h"
#include "JSceneManager.h"
#include "JObject.h"
#include "JSpriteRenderer.h"
#include "JResources.h"
JTitleScene::JTitleScene()
{
}

JTitleScene::~JTitleScene()
{
}

void JTitleScene::Initialize()
{
	JScene::Initialize();
}

void JTitleScene::Update()
{
	JScene::Update();
}

void JTitleScene::LateUpdate()
{
	JScene::LateUpdate();
	if (JInput::GetKeyDown(eKeyCode::n))
	{
		JSceneManager::LoadScene(L"PlayScene");
	}
}

void JTitleScene::Render(HDC hdc)
{
	JScene::Render(hdc);

	wchar_t str[50] = L"Title Scene";
	TextOut(hdc, 0, 0, str, 11);
}

void JTitleScene::OnEnter()
{
	JScene::OnEnter();
}

void JTitleScene::OnExit()
{
	JScene::OnExit();
}
