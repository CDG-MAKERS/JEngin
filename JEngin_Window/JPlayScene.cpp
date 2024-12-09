#include "JPlayScene.h"
#include "JGameObject.h"

JPlayScene::JPlayScene()
{
}

JPlayScene::~JPlayScene()
{
}

void JPlayScene::Initialize()
{
	JGameObject* objc = new JGameObject;
	AddGameObject(objc);
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
