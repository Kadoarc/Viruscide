#include "Label.h"

using namespace gui;

Label::Label()
{
}

void Label::handleEvent(const sf::Event &event)
{
	//auto rect = sprite.getGlobalBounds();
	/*rect.left = getPosition().x;
	rect.top = getPosition().y;
	rect.width = sprite.getLocalBounds().width;
	rect.height = sprite.getLocalBounds().height;*/
}

void Label::update(sf::Time dt)
{
}

void Label::setTexture(const sf::Texture &texture)
{
	sprite.setTexture(texture);
}

void Label::setText(const std::string &text)
{
	this->text.setString(text);
	//centerText();
}

void Label::setFont(const sf::Font &font)
{
	text.setFont(font);
}

bool gui::Label::isMouseOver(const sf::Vector2i &mouse) const
{
	sf::FloatRect rect;
	rect.left = getPosition().x;
	rect.top = getPosition().y;
	rect.width = sprite.getLocalBounds().width;
	rect.height = sprite.getLocalBounds().height;
	return rect.contains(static_cast<sf::Vector2f>(mouse));
}

void Label::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	if (sprite.getTexture())
		target.draw(sprite, states);
	else target.draw(text, states);
}

void Label::centerText()
{
	sf::FloatRect rect = text.getGlobalBounds();
	text.setOrigin(rect.left, rect.top);
	text.setPosition({ sprite.getLocalBounds().width / 2 - rect.width / 2,
		sprite.getLocalBounds().height / 2 - rect.height / 2 });
}