#pragma once
#include "..//JEngin_SOURCE//JResources.h"
#include "..//JEngin_SOURCE//JTexture.h"

void JLoadResources()
{
	JResources::Load<graphcis::JTexture>(L"Map", 
		L"..\\Resources\\map.png");
	JResources::Load<graphcis::JTexture>(L"Mario",
		L"..\\Resources\\mario.png");
	JResources::Load<graphcis::JTexture>(L"Title",
		L"..\\Resources\\aaa.png");
}

