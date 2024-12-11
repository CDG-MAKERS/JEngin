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
	JGameObject* bg = object::Instantiate<JGameObject>
		(enums::eLayerType::BackGround);
	JSpriteRenderer* bgSr
		= bg->AddComponent<JSpriteRenderer>();
	graphcis::JTexture* bgTexture =
		JResources::Find<graphcis::JTexture>(L"Title");
	bgSr->SetTexture(bgTexture);
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
