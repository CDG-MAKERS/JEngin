#include "JPlayer.h"
#include "JInput.h"
#include "JTransform.h"
#include "JTime.h"
void JPlayer::Initialize()
{
	JGameObject::Initialize();
}

void JPlayer::Update()
{
	JGameObject::Update();
}

void JPlayer::LateUpdate()
{
	JGameObject::LateUpdate();
	if (JInput::GetKey(eKeyCode::Right))
	{
		JTransform* tr = GetComponent<JTransform>();
		Vector2 pos = tr->GetPosition();
		pos.x += 100.0f * JTime::DeltaTime();
		tr->SetPos(pos);
	}
}

void JPlayer::Render(HDC hdc)
{
	JGameObject::Render(hdc);
}
