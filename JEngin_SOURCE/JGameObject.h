#pragma once
#include "CommonInclude.h"
#include "JComponent.h"


//Actor
class JGameObject 
{
public:
	//friend void object::Destory(JGameObject* obj);

	enum class eState
	{
		Active,
		Paused,
		Dead,
		End
	};


	JGameObject();
	~JGameObject();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Destroy();

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

	eState GetActive() { return mState; }
	void SetActive(bool power)
	{
		if (power == true) mState = eState::Active;
		if (power == false) mState = eState::Paused;
	}


private:
	void initializeTransform();
	void Death() { mState = eState::Dead; }

private:
	eState mState;
	std::vector<JComponent*> mComponents;
};

