#pragma once
#include "JGameObject.h"
#include "JEntity.h"

class JScene : public JEntity
{
public:
	JScene();
	~JScene();
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	void AddGameObject(JGameObject* gameObj);
private:
	std::vector<JGameObject*> mGameObjects;
};
