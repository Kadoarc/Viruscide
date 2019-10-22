//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Label.h
// Description	: Class definition for Label
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#pragma once

#include "Utils.h"

class LabelClass 
{
public:
	LabelClass();
	LabelClass(sf::Vector2f _position ,float _size, std::string _string, sf::Color _color, std::string _fontPath);
	~LabelClass();

	void render(sf::RenderWindow& _window);
	void loadFont(std::string _font);
	void setText(std::string _text);
	sf::Text getText();

private:
	sf::Text text;
	int textSize;
};