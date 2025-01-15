#pragma once
#include "..//JEngin_SOURCE//JResources.h"
#include "..//JEngin_SOURCE//JTexture.h"

void JLoadResources()
{
	JResources::Load<graphics::JTexture>(L"Character",
		L"..\\Resources\\character.bmp");
	JResources::Load<graphics::JTexture>(L"Cat"
		, L"..\\Resources\\Cat.bmp");
	JResources::Load<graphics::JTexture>(L"SpringFloor", L"..\\Resources\\SpringFloor.bmp");
}