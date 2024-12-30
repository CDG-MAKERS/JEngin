#include "JScript.h"
#include "JCollider.h"

JScript::JScript()
	: JComponent(enums::eComponentType::Script)
{
}

JScript::~JScript()
{
}

void JScript::Initialize()
{
}

void JScript::Update()
{
}

void JScript::LateUpdate()
{
}

void JScript::Render(HDC hdc)
{
}

void JScript::OnCollisionEnter(JCollider* other)
{
}

void JScript::OnCollisionStay(JCollider* other)
{
}

void JScript::OnCollisionExit(JCollider* other)
{
}
