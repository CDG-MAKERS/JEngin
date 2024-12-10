#include "JPlayScene.h"
#include "JGameObject.h"
#include "JPlayer.h"
#include "JTransform.h"
#include "JSpriteRenderer.h"
#include "JInput.h"
#include "JTitleScene.h"
#include "JSceneManager.h"
JPlayScene::JPlayScene()
{
}

JPlayScene::~JPlayScene()
{
}

void JPlayScene::Initialize()
{
	//JGameObject* objc = new JGameObject;
	{
		bg = new JPlayer();
		JTransform* tr
			= bg->AddComponent<JTransform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");
		JSpriteRenderer* sr
			= bg->AddComponent<JSpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\deving\\JEngin\\Resources\\aaa.jpg");
		AddGameObject(bg, eLayerType::BackGround);
	}

}

void JPlayScene::Update()
{
	JScene::Update();
}

void JPlayScene::LateUpdate()
{
	JScene::LateUpdate();
	if (JInput::GetKeyDown(eKeyCode::n))
	{
		JSceneManager::LoadScene(L"TitleScene");
	}
}

void JPlayScene::Render(HDC hdc)
{
	JScene::Render(hdc);
	wchar_t str[50] = L"PlayScene Scene";
	TextOut(hdc, 0, 0, str, 10);
}

void JPlayScene::OnEnter()
{
}

void JPlayScene::OnExit()
{
	JTransform* tr
		= bg->GetComponent<JTransform>();
	tr->SetPos(Vector2(0, 0));
}
