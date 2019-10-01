#include "Label.h"

LabelClass::LabelClass()
{
}

LabelClass::LabelClass(sf::Vector2f _position, float _size, std::string _string, sf::Text::Style _style, sf::Color _color, std::string _fontPath)
{
	loadFont(_fontPath);
	text.setFont(font);
	text.setString(_string);
	text.setCharacterSize(_size);
	text.setFillColor(_color);
	text.setStyle(_style);
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
	// Dont forget the file path!
	//"Resources/Fonts/example.ttf"
	if (!font.loadFromFile(_font))
	{
		//error
		std::cout << "error loading font" << std::endl;
	}
}

void LabelClass::setText(std::string _text)
{
	text.setString(_text);
}

sf::Text LabelClass::getText()
{
	return (text);
}
