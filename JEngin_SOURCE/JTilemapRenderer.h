#pragma once
#include "JEntity.h"
#include "JComponent.h"
#include "JTexture.h"


class JTilemapRenderer : public JComponent
{
public:
	JTilemapRenderer();
	~JTilemapRenderer();

	void Initialize() override;
	void Update()  override;
	void LateUpdate()  override;
	void Render(HDC hdc)  override;

	void SetTexture(graphics::JTexture* texture) { mTexture = texture; }
	void SetSize(JMath::Vector2 size) { mSize = size; }
	void SetIndex(Vector2 index) { mIndex = index; }

public:
	static Vector2 TileSize;
	static Vector2 OriginTileSize;
	static Vector2 SelectedIndex;

private:
	Vector2 mTileSize;
	graphics::JTexture* mTexture;
	Vector2 mSize;
	Vector2 mIndex;
};