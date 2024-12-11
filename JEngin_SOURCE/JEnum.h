#pragma once

namespace enums
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
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
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}
