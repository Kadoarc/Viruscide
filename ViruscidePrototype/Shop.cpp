#include "Shop.h"

Shop::Shop()
{
	this->m_goldItem.setPosition(sf::Vector2f(this->getPosition().x + Globals::rasterLeft, this->getPosition().y + Globals::rasterTop / 6));
	this->m_goldItem.setSize(sf::Vector2f(180, 40));
	this->m_goldItem.setTextPosition(m_goldItem.getPosition());

	this->m_lifePointsItem.setPosition(sf::Vector2f(this->getPosition().x + Globals::rasterLeft, this->m_goldItem.getPosition().y + m_goldItem.getHeight() + Globals::itemSpacingHeight));
	this->m_lifePointsItem.setSize(sf::Vector2f(180, 40));
	this->m_lifePointsItem.setTextPosition(m_lifePointsItem.getPosition());

	//default tower
	newButton.setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y + 1 * (Globals::shopItemSize.y / 2) + Globals::rasterTop));
	newButton.setSize(Globals::shopItemSize);
	newButton.setTextPosition(newButton.getPosition());
	newButton.setTextSize(20);
	newButton.setText(" Price: " + std::to_string(Globals::defaultTowerPrice) + "\n Damage: " + std::to_string(Globals::defaultTowerDamage) +
		"\n Fire Rate: " + std::to_string(Globals::defaultTowerFireRate));
	m_shopItems.push_back(newButton);

	//speedy tower
	newButton.setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y + 4 * (Globals::shopItemSize.y / 2) + Globals::rasterTop));
	newButton.setSize(Globals::shopItemSize);
	newButton.setTextPosition(newButton.getPosition());
	newButton.setTextSize(20);
	newButton.setText(" Price: " + std::to_string(Globals::speedyTowerPrice) + "\n Damage: " + std::to_string(Globals::speedyTowerDamage) +
		"\n Fire Rate: " + std::to_string(Globals::towerSpeedyFireRate));
	m_shopItems.push_back(newButton);

	//powerfull tower
	newButton.setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y + 7 * (Globals::shopItemSize.y / 2) + Globals::rasterTop));
	newButton.setSize(Globals::shopItemSize);
	newButton.setTextPosition(newButton.getPosition());
	newButton.setTextSize(20);
	newButton.setText(" Price: " + std::to_string(Globals::powerfullTowerPrice) + "\n Damage: " + std::to_string(Globals::powerfullTowerDamage) +
		"\n Fire Rate: " + std::to_string(Globals::powerfullTowerFireRate));
	m_shopItems.push_back(newButton);
}

Shop::~Shop()
{
}

void Shop::update(const sf::Vector2f & mouseCoordinates)
{
	/* If the mouse button was pressed and the mouse is in bounds of the Shop */
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->isCollisonWithPoint(mouseCoordinates))
	{
		/* Start checking if it pressed on any shop items */
		for (unsigned int i = 0; i < m_shopItems.size(); ++i)
		{
			/*  */
			if (m_shopItems[i].isCollisonWithPoint(mouseCoordinates))
			{
				this->isSelected = true;
				selectedItem = i;
				return;
			}
		}
	}
}

void Shop::setGold(const int newGold)
{
	this->m_goldItem.setText("Gold: " + std::to_string(newGold));
}

void Shop::setLifePoints(const int newLifePoints)
{
	this->m_lifePointsItem.setText("Life: " + std::to_string(newLifePoints));
}

void Shop::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	Entity::draw(target, states);
	for (const Button& shopItem : m_shopItems)
		target.draw(shopItem);

	target.draw(m_goldItem);
	target.draw(m_lifePointsItem);
}


