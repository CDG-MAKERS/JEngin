#pragma once
#include "CommonInclude.h"
#include "JComponent.h"

//Actor
class JGameObject 
{
public:
	JGameObject();
	~JGameObject();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	template <typename T>
	T* AddComponent()
	{
		T* comp = new T();
		comp->Initialize();
		comp->SetOwner(this);

		mComponents[(UINT)comp->GetType()] = comp;
		mComponents.push_back(comp);
		return comp;
	}

	//왜 1개만? 몰루 테스트 코드 돌려볼것
	template <typename T>
	T* GetComponent()
	{
		T* component = nullptr;
		for (JComponent* comp : mComponents)
		{
			component = dynamic_cast<T*>(comp);
			if (component)
				break;
		}
		return component;
	}
private:
	void initTransform();
private:
	std::vector<JComponent*> mComponents;
};

