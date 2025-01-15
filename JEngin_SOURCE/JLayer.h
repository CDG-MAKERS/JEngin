#pragma once
#include "JEntity.h"
#include "CommonInclude.h"
#include "JGameObject.h"
class JLayer : public JEntity
{
public:
	JLayer();
	~JLayer();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Destroy();

	void AddGameObject(JGameObject* gameObj);

	void EraseGameObject(JGameObject* eraseGameObj);
	const std::vector<JGameObject*> GetGameObjects() { return mGameObjects; }

private:
	void findDeadGameObjects(OUT std::vector<JGameObject*>& gameObjs);
	void deleteGameObjects(std::vector<JGameObject*> deleteObjs);
	void eraseDeadGameObject();
private:
	//eLayerType mType;
	std::vector<JGameObject*> mGameObjects;
};
typedef std::vector<JGameObject*>::iterator GameObjectIter;
