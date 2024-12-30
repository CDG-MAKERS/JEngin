#pragma once
#include "JEntity.h"
#include "JComponent.h"
#include "JTexture.h"

class JSpriteRenderer : public JComponent
{
public:
	JSpriteRenderer();
	~JSpriteRenderer();

	void Initialize() override;
	void Update()  override;
	void LateUpdate()  override;
	void Render(HDC hdc)  override;

	void SetTexture(graphics::JTexture* texture) { mTexture = texture; }
	void SetSize(JMath::Vector2 Size) { mSize = Size; }
private:
	graphics::JTexture* mTexture;
	JMath::Vector2 mSize;
};

