#include "JTile.h"
#include "JTransform.h"
#include "JTime.h"
#include "JTilemapRenderer.h"

void JTile::Initialize()
{
	JGameObject::Initialize();
}

void JTile::Update()
{
	JGameObject::Update();
}

void JTile::LateUpdate()
{
	JGameObject::LateUpdate();
}

void JTile::Render(HDC hdc)
{
	JGameObject::Render(hdc);
}

void JTile::SetPosition(int x, int y)
{
	JTransform* tr = GetComponent<JTransform>();
	Vector2 pos;
	pos.x = x * JTilemapRenderer::TileSize.x;
	pos.y = y * JTilemapRenderer::TileSize.y;
	tr->SetPosition(pos);
}