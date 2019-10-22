//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: GameOver.h
// Description	: Class definition for GameOver
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#pragma once

#include "Utils.h"
#include "Label.h"
#include "Button.h"

class GameOverScreenClass
{
public:
	GameOverScreenClass();
	~GameOverScreenClass();

	void render(sf::RenderWindow & _window);
private: 
	sf::RectangleShape backgroundImage;
	sf::Texture backgroundTexture;
	LabelClass text;
};