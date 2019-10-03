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