#include "JPlayerScript.h"
#include "JInput.h"
#include "JTransform.h"
#include "JTime.h"
#include "JGameObject.h"
JPlayerScript::JPlayerScript()
{
}

JPlayerScript::~JPlayerScript()
{
}

void JPlayerScript::Initialize()
{
}

void JPlayerScript::Update()
{
	if (JInput::GetKey(eKeyCode::Right))
	{
		JTransform* tr = GetOwner()->GetComponent<JTransform>();
		Vector2 pos = tr->GetPosition();
		pos.x += 100.0f * JTime::DeltaTime();
		tr->SetPosition(pos);
	}
	if (JInput::GetKey(eKeyCode::Left))
	{
		JTransform* tr = GetOwner()->GetComponent<JTransform>();
		Vector2 pos = tr->GetPosition();
		pos.x -= 100.0f * JTime::DeltaTime();
		tr->SetPosition(pos);
	}
	if (JInput::GetKey(eKeyCode::Up))
	{
		JTransform* tr = GetOwner()->GetComponent<JTransform>();
		Vector2 pos = tr->GetPosition();
		pos.y -= 100.0f * JTime::DeltaTime();
		tr->SetPosition(pos);
	}
	if (JInput::GetKey(eKeyCode::Down))
	{
		JTransform* tr = GetOwner()->GetComponent<JTransform>();
		Vector2 pos = tr->GetPosition();
		pos.y += 100.0f * JTime::DeltaTime();
		tr->SetPosition(pos);
	}
}

void JPlayerScript::LateUpdate()
{
}

void JPlayerScript::Render(HDC hdc)
{
}
