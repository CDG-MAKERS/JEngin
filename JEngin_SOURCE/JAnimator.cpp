#include "JAnimator.h"
#include "JResources.h"
#include "JTexture.h"
JAnimator::JAnimator()
	: JComponent(enums::eComponentType::Animator)
	, mAnimations{}
	, mActiveAnimation(nullptr)
	, mbLoop(false)
{
}

JAnimator::~JAnimator()
{
	for (auto& iter : mAnimations)
	{
		delete iter.second;
		iter.second = nullptr;
	}

	for (auto& iter : mEvents)
	{
		delete iter.second;
		iter.second = nullptr;
	}
}

void JAnimator::Initialize()
{
}

void JAnimator::Update()
{
	if (mActiveAnimation)
	{
		mActiveAnimation->Update();
		Events* events
			= FindEvents(mActiveAnimation->GetName());

		if (mActiveAnimation->IsComplete() == true
			&& mbLoop == true)
		{
			if (events)
				events->completeEvent();

			if (mbLoop == true)
				mActiveAnimation->Reset();
		}
	}
}

void JAnimator::LateUpdate()
{
}

void JAnimator::Render(HDC hdc)
{
	if (mActiveAnimation)
		mActiveAnimation->Render(hdc);
}

void JAnimator::CreateAnimation(const std::wstring& name
	, graphics::JTexture* spriteSheet
	, Vector2 leftTop, Vector2 size
	, Vector2 offset, UINT spriteLenth
	, float duration)
{
	JAnimation* animation = nullptr;
	animation = FindAnimation(name);
	if (animation != nullptr)
		return;
	animation = new JAnimation();
	animation->CreateAnimation(name, spriteSheet
		, leftTop, size, offset, spriteLenth, duration);

	animation->SetAnimator(this);

	Events* events = new Events();
	mEvents.insert(std::make_pair(name, events));

	mAnimations.insert(std::make_pair(name, animation));
}

void JAnimator::CreateAnimationByFolder(const std::wstring& name, const std::wstring& path, Vector2 offset, float duration)
{
	JAnimation* animation = nullptr;
	animation = FindAnimation(name);
	if (animation != nullptr)
		return;
	//D:\JunJae\AR50\YamYam_Engine\Resources\Mushroom\1.bmp

	int fileCount = 0;
	std::filesystem::path fs(path);
	std::vector<graphics::JTexture*> images = {};
	for (auto& p : std::filesystem::recursive_directory_iterator(fs)) //폴더내 파일을 이터레이터로 사용
	{
		std::wstring fileName = p.path().filename();
		std::wstring fullName = p.path();

		graphics::JTexture* texture = JResources::Load<graphics::JTexture>(fileName, fullName);
		images.push_back(texture);
		fileCount++;
	}


	UINT sheetWidth = images[0]->GetWidth() * fileCount;
	UINT sheetHeight = images[0]->GetHeight();
	graphics::JTexture* spriteSheet = graphics::JTexture::Create(name, sheetWidth, sheetHeight);

	UINT imageWidth = images[0]->GetWidth();
	UINT imageHeight = images[0]->GetHeight();
	for (size_t i = 0; i < images.size(); i++)
	{
		BitBlt(spriteSheet->GetHdc(), i * imageWidth, 0
			, imageWidth, imageHeight
			, images[i]->GetHdc(), 0, 0, SRCCOPY);
	}

	CreateAnimation(name, spriteSheet
		, Vector2(0.0f, 0.0f), Vector2(imageWidth, imageHeight)
		, offset, fileCount, duration);
}


JAnimation* JAnimator::FindAnimation(const std::wstring& name)
{
	auto iter = mAnimations.find(name);
	if (iter == mAnimations.end())
		return nullptr;

	return iter->second;
}

void JAnimator::PlayAnimation(const std::wstring& name, bool loop)
{
	JAnimation* animation = FindAnimation(name);
	if (animation == nullptr)
		return;
	if (mActiveAnimation)
	{
		Events* currentEvents
			= FindEvents(mActiveAnimation->GetName());

		if (currentEvents)
			currentEvents->endEvent();
	}

	Events* nextEvents
		= FindEvents(animation->GetName());

	if (nextEvents)
		nextEvents->startEvent();

	mActiveAnimation = animation;
	mActiveAnimation->Reset();
	mbLoop = loop;
}

JAnimator::Events* JAnimator::FindEvents(const std::wstring& name)
{
	auto iter = mEvents.find(name);
	if (iter == mEvents.end())
		return nullptr;

	return iter->second;
}

std::function<void()>& JAnimator::GetStartEvent(const std::wstring& name)
{
	// TODO: 여기에 return 문을 삽입합니다.
	Events* events = FindEvents(name);
	return events->startEvent.mEvent;
}

std::function<void()>& JAnimator::GetCompleteEvent(const std::wstring& name)
{
	// TODO: 여기에 return 문을 삽입합니다.
	Events* events = FindEvents(name);
	return events->completeEvent.mEvent;
}

std::function<void()>& JAnimator::GetEndEvent(const std::wstring& name)
{
	// TODO: 여기에 return 문을 삽입합니다.
	Events* events = FindEvents(name);
	return events->endEvent.mEvent;
}
