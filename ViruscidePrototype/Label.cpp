#include "Label.h"




gui::Label::Label()
{
}

void gui::Label::handleEvent(const sf::Event & event)
{
}

void gui::Label::update(sf::Time dt)
{
}

void gui::Label::setText(const sf::Text & text)
{
	this->text.setString();
}

void gui::Label::setTexture(const sf::Texture & texture)
{
	sprite.setTexture(texture);
}

void gui::Label::setFont(const sf::Font & font)
{
	text.setFont(font);
}

bool gui::Label::isMouseOver(const sf::Vector2i & mouse)
{
	sf::FloatRect rect;
	rect.left = getPosition().x;
	rect.top = getPosition().y;
	rect.width = sprite.getLocalBounds().width;
	rect.height = sprite.getLocalBounds().height;
	return rect.contains(static_cast<sf::Vector2f>(mouse));

}

void gui::Label::draw(sf::RenderTarget & target, sf::RenderStates & states) const
{
	states.transform *= getTransform();
	if (sprite.getTexture())
		target.draw(sprite, states);
	else target.draw(text, states);
}

void gui::Label::centreText()
{
}


