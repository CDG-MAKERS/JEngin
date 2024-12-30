#pragma once
#include "..\\JEngin_SOURCE\\JGameObject.h"


class JCat : public JGameObject
{
public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;

private:

};

