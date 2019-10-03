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