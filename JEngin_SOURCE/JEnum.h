#pragma once

namespace enums
{
	enum class eComponentType
	{
		Transform,
		Colider,
		Script,
		SpriteRenderer,
		Animator,
		Camera,
		End,

	};

	enum class eLayerType
	{
		None,
		BackGround,
		Character,
		Monter,
		Player,
		Particle,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};
}
