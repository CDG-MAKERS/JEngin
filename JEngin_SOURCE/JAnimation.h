#pragma once
#include "JResource.h"
#include "JTexture.h"
class JAnimation : public JResource
{
public:
	struct Sprite
	{
		Vector2 leftTop;
		Vector2 size;
		Vector2 offset;
		float	duration;

		Sprite()
			: leftTop(Vector2::Zero)
			, size(Vector2::Zero)
			, offset(Vector2::Zero)
			, duration(0.0f)
		{

		}
	};

	JAnimation();
	~JAnimation();
	HRESULT Load(const std::wstring& path) override;

	void Update();
	void Render(HDC hdc);

	void CreateAnimation(const std::wstring& name
		, graphics::JTexture* spriteSheet
		, Vector2 leftTop, Vector2 size, Vector2 offset
		, UINT spriteLenth, float duration);

	void Reset();

	bool IsComplete() { return mbComplete; }
	void SetAnimator(class JAnimator* animator) { mAnimator = animator; }
private:
	class JAnimator* mAnimator;
	graphics::JTexture* mTexture;
	std::vector<Sprite> mAnimationSheet;
	UINT	mIndex;
	float	mTime;
	bool	mbComplete;
};

