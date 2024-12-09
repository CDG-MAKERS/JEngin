#pragma once
#include "JGameObject.h"
#include "JEntity.h"

class JScene : public JEntity
{
public:
	JScene();
	~JScene();
	void Initialize();
	void Update();
	void LateUpdate();
	void Render(HDC hdc);
private:
	std::vector<JGameObject*> mGameObjects;
};

