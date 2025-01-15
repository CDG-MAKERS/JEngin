#pragma once
#include "..\\JEngin_SOURCE\\JGameObject.h"
class JTile : public JGameObject
{
public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;

	void SetPosition(int x, int y);
private:
};