#pragma once
#include "JEntity.h"
#include "JComponent.h"


class JSpriteRenderer : public JComponent
{
public:
	JSpriteRenderer();
	~JSpriteRenderer();

	void Initialize() override;
	void Update()  override;
	void LateUpdate()  override;
	void Render(HDC hdc)  override;
private:
};

