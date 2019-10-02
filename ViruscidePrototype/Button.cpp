#include "Button.h"
#include "..\Logging\Logging.h"
#include<fstream>

Button::Button()
	: Entity(sf::Vector2f(0, 0), sf::Vector2f(50, 30))
{
	setUpButton();
}

Button::Button(const sf::Vector2f& position, const sf::Vector2f& size)
	: Entity(position, size)
{
	setUpButton();
}

Button::~Button()
{
}

void Button::setUpButton()
{
	setColour(Globals::Color::defaultButtonColor);

	if (!font.loadFromFile(Globals::Fonts::defaultFont))
	{
		throw "Could not load font!";

		Logger logger(std::cout);
		logger.log("Error loading font from file", Logger::Level::Error);
	}

	text.setFont(font);
	text.setString("Default String!");
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(24);
}

sf::Font Button::getFont() const
{
	return font;
}

void Button::setFont(const sf::Font& f)
{
	text.setFont(f);
}

void Button::setTextSize(unsigned int size)
{
	text.setCharacterSize(size);
}

void Button::setTextPosition(const sf::Vector2f & position)
{
	text.setPosition(position);
}

void Button::setTextColor(const sf::Color& color)
{
	text.setFillColor(color);
}

sf::Text Button::getText() const
{
	return text;
}

void Button::setText(const std::string & text)
{
	this->text.setString(text);
}
void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//target.draw(this->hitbox);
	Entity::draw(target, states);
	target.draw(this->text);
}
