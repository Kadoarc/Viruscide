#pragma once

#include <SFML/Graphics.hpp>

class Money : public sf::Drawable, public sf::Transformable
{
public:
	Money();

	void setFont(const sf::Font &font);

	void computeMoney(int gold, int lives, int level);
	int getMoney() const;

	sf::Vector2f getSize() const;
private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	sf::Text MoneyText;
	int Money;
};
