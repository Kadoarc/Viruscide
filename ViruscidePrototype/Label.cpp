//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Label.cpp
// Description	: Class for making labels
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#include "Label.h"

LabelClass::LabelClass()
{
}

LabelClass::LabelClass(sf::Vector2f _position, float _size, std::string _string, sf::Color _color, std::string _fontPath)
{
	loadFont(_fontPath);
	//text.setFont(font);
	text = sf::Text();
	text.setString(_string);
	text.setCharacterSize(_size);
	text.setFillColor(_color);
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(_position);
}

LabelClass::~LabelClass()
{
}

void LabelClass::render(sf::RenderWindow & _window)
{
	_window.draw(text);
}

void LabelClass::loadFont(std::string _font)
{
	sf::Font font;
	// Dont forget the file path!
	//"Resources/Fonts/example.ttf"
	if (!font.loadFromFile(_font))
	{
		//error
		std::cout << "error loading font" << std::endl;
	}

	text.setFont(font);
}

void LabelClass::setText(std::string _text)
{
	text.setString(_text);
}

sf::Text LabelClass::getText()
{
	return (text);
}
