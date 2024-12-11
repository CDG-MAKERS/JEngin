#include "JPlayScene.h"
#include "JGameObject.h"
#include "JPlayer.h"
#include "JTransform.h"
#include "JSpriteRenderer.h"
#include "JInput.h"
#include "JTitleScene.h"
#include "JSceneManager.h"
#include "JObject.h"
#include "JTexture.h"
#include "JResources.h"
#include "JPlayerScript.h"
#include "JCamera.h"
#include "JRenderer.h"
JPlayScene::JPlayScene()
{
}

JPlayScene::~JPlayScene()
{
}

void JPlayScene::Initialize()
{
	// main camera
	JGameObject* camera = object::Instantiate<JGameObject>(enums::eLayerType::None, Vector2(810.0f, 460.0f));
	JCamera* cameraComp = camera->AddComponent<JCamera>();
	JRenderer::mainCamera = cameraComp;
	//camera->AddComponent<JPlayerScript>();

	mPlayer = object::Instantiate<JPlayer>(enums::eLayerType::Player, Vector2(800.0f, 450.0f));
	JSpriteRenderer* sr
		= mPlayer->AddComponent<JSpriteRenderer>();
	sr->SetSize(Vector2(0.2f, 0.2f));
	mPlayer->AddComponent<JPlayerScript>();

	graphcis::JTexture* marioTexture =
		JResources::Find<graphcis::JTexture>(L"Mario");
	sr->SetTexture(marioTexture);

	JGameObject* bg = object::Instantiate<JGameObject>
		(enums::eLayerType::BackGround);
	JSpriteRenderer* bgSr
		= bg->AddComponent<JSpriteRenderer>();
	graphcis::JTexture* bgTexture =
		JResources::Find<graphcis::JTexture>(L"Map");
	bgSr->SetTexture(bgTexture);
		
	JScene::Initialize();


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
	//JTransform* tr
	//	= bg->GetComponent<JTransform>();
	//tr->SetPosition(Vector2(0, 0));
}
