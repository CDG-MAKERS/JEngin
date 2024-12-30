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
#include "JAnimator.h"
#include "JCat.h"
#include "JCatScript.h"

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

	mPlayer = object::Instantiate<JPlayer>(enums::eLayerType::Player, Vector2(800.0f, 450.0f));
	mPlayer->AddComponent<JPlayerScript>();

	graphics::JTexture* marioTexture =
		JResources::Find<graphics::JTexture>(L"Character");
	JAnimator* animator = mPlayer->AddComponent<JAnimator>();
	animator->CreateAnimation(L"CharacterFrontMove", marioTexture
		, Vector2(0.0f, 0.0f), Vector2(34.0f, 48.0f), Vector2::Zero
		, 4, 0.5f);
	animator->CreateAnimation(L"CharacterLeftMove", marioTexture
		, Vector2(0.0f, 48.0f), Vector2(34.0f, 48.0f), Vector2::Zero
		, 4, 0.5f);
	animator->CreateAnimation(L"CharacterRightMove", marioTexture
		, Vector2(0.0f, 96.0f), Vector2(34.0f, 48.0f), Vector2::Zero
		, 4, 0.5f);
	animator->CreateAnimation(L"CharacterBottomMove", marioTexture
		, Vector2(0.0f, 144.0f), Vector2(34.0f, 48.0f), Vector2::Zero
		, 4, 0.5f);
	animator->PlayAnimation(L"CharacterFrontMove", true);

	JCat* cat = object::Instantiate<JCat>(enums::eLayerType::Monter);
	cat->AddComponent<JCatScript>();
	//cameraComp->SetTarget(cat);
	graphics::JTexture* catTex = JResources::Find<graphics::JTexture>(L"Cat");
	JAnimator* catAnimator = cat->AddComponent<JAnimator>();
	
	catAnimator->CreateAnimation(L"DownWalk", catTex
		, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	catAnimator->CreateAnimation(L"RightWalk", catTex
		, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	catAnimator->CreateAnimation(L"UpWalk", catTex
		, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	catAnimator->CreateAnimation(L"LeftWalk", catTex
		, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	catAnimator->CreateAnimation(L"SitDown", catTex
		, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	catAnimator->CreateAnimation(L"Grooming", catTex
		, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	catAnimator->CreateAnimation(L"LayDown", catTex
		, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

	catAnimator->PlayAnimation(L"SitDown", false);
	cat->GetComponent<JTransform>()->SetPosition(Vector2(200.0f, 200.0f));
	cat->GetComponent<JTransform>()->SetScale(Vector2(2.0f, 2.0f));

	JGameObject* bg = object::Instantiate<JGameObject>
		(enums::eLayerType::BackGround);
	JSpriteRenderer* bgSr
		= bg->AddComponent<JSpriteRenderer>();
	graphics::JTexture* bgTexture =
		JResources::Find<graphics::JTexture>(L"Map");
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
