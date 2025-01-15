#pragma once
#include "JGameObject.h"
#include "JEntity.h"
#include "JLayer.h"

class JScene : public JEntity
{
public:
	JScene();
	~JScene();
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Destroy();

	//¾À ÀÌµ¿¿ë
	virtual void OnEnter();
	virtual void OnExit();

	void AddGameObject(JGameObject* gameObj, const enums::eLayerType type);
	void EraseGameObject(JGameObject* gameObj);

	JLayer* GetLayer(const enums::eLayerType type) { return mLayers[(UINT)type]; }

private:
	std::vector<JLayer*> mLayers;
};
