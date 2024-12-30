#pragma once
#include "..//JEngin_SOURCE//JResources.h"
#include "..//JEngin_SOURCE//JTexture.h"

void JLoadResources()
{
	JResources::Load<graphics::JTexture>(L"Map",
		L"..\\Resources\\map.png");
	JResources::Load<graphics::JTexture>(L"Mario",
		L"..\\Resources\\mario.png");
	JResources::Load<graphics::JTexture>(L"Title",
		L"..\\Resources\\aaa.png");
	JResources::Load<graphics::JTexture>(L"Character",
		L"..\\Resources\\character.bmp");
	JResources::Load<graphics::JTexture>(L"Cat"
		, L"..\\Resources\\Cat.bmp");

	//character

}

