#include "JCollider.h"
#include "JGameObject.h"
#include "JScript.h"


UINT JCollider::CollisionID = 1;

JCollider::JCollider(eColliderType type)
	: JComponent(enums::eComponentType::Colider)
	, mType(type)
	, mID(CollisionID++)
	, mSize(Vector2::One)
{
}

JCollider::~JCollider()
{
}

void JCollider::Initialize()
{
}

void JCollider::Update()
{
}

void JCollider::LateUpdate()
{
}

void JCollider::Render(HDC hdc)
{
}

void JCollider::OnCollisionEnter(JCollider* other)
{
	JScript* script = GetOwner()->GetComponent<JScript>();
	script->OnCollisionEnter(other);
}

void JCollider::OnCollisionStay(JCollider* other)
{
	JScript* script = GetOwner()->GetComponent<JScript>();
	script->OnCollisionStay(other);
}

void JCollider::OnCollisionExit(JCollider* other)
{
	JScript* script = GetOwner()->GetComponent<JScript>();
	script->OnCollisionExit(other);
}
