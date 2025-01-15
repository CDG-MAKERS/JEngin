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
#include "JBoxCollider2D.h"
#include "JCollisionManager.h"

#pragma warning(disable: 26495)
JPlayScene::JPlayScene()
{
}

JPlayScene::~JPlayScene()
{
}

void JPlayScene::Initialize()
{
	JCollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);

	// main camera
	JGameObject* camera = object::Instantiate<JGameObject>(enums::eLayerType::None, Vector2(810.0f, 460.0f));
	JCamera* cameraComp = camera->AddComponent<JCamera>();
	JRenderer::mainCamera = cameraComp;

	mPlayer = object::Instantiate<JPlayer>(enums::eLayerType::Player, Vector2(800.0f, 450.0f));
	object::DontDestroyOnLoad(mPlayer);

	JPlayerScript* plScript = mPlayer->AddComponent<JPlayerScript>();
	JBoxCollider2D* collider = mPlayer->AddComponent<JBoxCollider2D>();
	collider->SetOffset(Vector2(-50.0f, -50.0));

	graphics::JTexture* playerMan =
		JResources::Find<graphics::JTexture>(L"Character");
	JAnimator* animator = mPlayer->AddComponent<JAnimator>();
	animator->CreateAnimation(L"CharacterFrontMove", playerMan
		, Vector2(0.0f, 0.0f), Vector2(34.0f, 48.0f), Vector2::Zero
		, 4, 0.5f);
	animator->CreateAnimation(L"CharacterLeftMove", playerMan
		, Vector2(0.0f, 48.0f), Vector2(34.0f, 48.0f), Vector2::Zero
		, 4, 0.5f);
	animator->CreateAnimation(L"CharacterRightMove", playerMan
		, Vector2(0.0f, 96.0f), Vector2(34.0f, 48.0f), Vector2::Zero
		, 4, 0.5f);
	animator->CreateAnimation(L"CharacterBottomMove", playerMan
		, Vector2(0.0f, 144.0f), Vector2(34.0f, 48.0f), Vector2::Zero
		, 4, 0.5f);
	animator->PlayAnimation(L"CharacterFrontMove", true);


	JCat* cat = object::Instantiate<JCat>(enums::eLayerType::Animal);
	//cat->SetActive(true);
	cat->AddComponent<JCatScript>();
	//cameraComp->SetTarget(cat);
	graphics::JTexture* catTex = JResources::Find<graphics::JTexture>(L"Cat");
	JAnimator* catAnimator = cat->AddComponent<JAnimator>();
	JBoxCollider2D* boxCatCollider = cat->AddComponent<JBoxCollider2D>();
	boxCatCollider->SetOffset(Vector2(-50.0f, -50.0f));
	catAnimator->CreateAnimationByFolder(L"MushroomIdle", L"..\\Resources\\Mushroom", Vector2::Zero, 0.1f);
	catAnimator->PlayAnimation(L"MushroomIdle", true);

	cat->GetComponent<JTransform>()->SetPosition(Vector2(200.0f, 200.0f));
	cat->GetComponent<JTransform>()->SetScale(Vector2(1.0f, 1.0f));
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
}
