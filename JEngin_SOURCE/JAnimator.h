#pragma once
#include "JComponent.h"
#include "JAnimation.h"

class JAnimator : public JComponent
{
public:
	struct Event
	{
		void operator=(std::function<void()> func)
		{
			mEvent = std::move(func);
		}

		void operator()()
		{
			if (mEvent)
				mEvent();
		}

		std::function<void()> mEvent;
	};

	struct Events
	{
		Event startEvent;
		Event completeEvent;
		Event endEvent;
	};

public:
	JAnimator();
	~JAnimator();

	void Initialize() override;
	void Update() override;
	void LateUpdate()override;
	void Render(HDC hdc)override;

	void CreateAnimation(const std::wstring& name
		, graphics::JTexture* spriteSheet
		, Vector2 leftTop, Vector2 size, Vector2 offset
		, UINT spriteLenth, float duration);
	void CreateAnimationByFolder(const std::wstring& name
		, const std::wstring& path
		, Vector2 offset, float duration);

	JAnimation* FindAnimation(const std::wstring& name);
	void PlayAnimation(const std::wstring& name, bool loop = true);

	Events* FindEvents(const std::wstring& name);
	std::function<void()>& GetStartEvent(const std::wstring& name);
	std::function<void()>& GetCompleteEvent(const std::wstring& name);
	std::function<void()>& GetEndEvent(const std::wstring& name);

	bool IsComplete() { return mActiveAnimation->IsComplete(); }

private:
	std::map<std::wstring, JAnimation*> mAnimations;
	JAnimation* mActiveAnimation;
	bool mbLoop;


	//Event
	std::map<std::wstring, Events*> mEvents;
};

