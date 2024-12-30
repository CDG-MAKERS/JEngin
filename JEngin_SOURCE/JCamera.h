#pragma once
#include "JComponent.h"

class JCamera :public JComponent
{
public:
	JMath::Vector2 CaluatePosition(JMath::Vector2 pos) { return pos - mDistance; }

	JCamera();
	~JCamera();

	virtual void Initialize() override;
	virtual void Update()override;
	virtual void LateUpdate()override;
	virtual void Render(HDC hdc)override;

	void SetTarget(JGameObject* target) { mTarget = target; }

private:
	//std::vector<JGameObject*> mGameObjects;
	class JGameObject* mTarget;

	JMath::Vector2 mDistance;
	JMath::Vector2 mResolution;
	JMath::Vector2 mLookPosition;
};

