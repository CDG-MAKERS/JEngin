#include "JPlayScene.h"
#include "JGameObject.h"
#include "JPlayer.h"
#include "JTransform.h"
#include "JSpriteRenderer.h"

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
		JPlayer* pl = new JPlayer();
		JTransform* tr
			= pl->AddComponent<JTransform>();
		tr->SetPos(800, 450);
		tr->SetName(L"TR");
		JSpriteRenderer* sr
			= pl->AddComponent<JSpriteRenderer>();
		sr->SetName(L"SR");
		AddGameObject(pl);
	}
	{
		JPlayer* pl = new JPlayer();
		JTransform* tr
			= pl->AddComponent<JTransform>();
		tr->SetPos(300, 450);
		tr->SetName(L"TR");
		JSpriteRenderer* sr
			= pl->AddComponent<JSpriteRenderer>();
		sr->SetName(L"SR");
		AddGameObject(pl);
	}
}

void JPlayScene::Update()
{
	JScene::Update();
}

void JPlayScene::LateUpdate()
{
	JScene::LateUpdate();
}

void JPlayScene::Render(HDC hdc)
{
	JScene::Render(hdc);
}
