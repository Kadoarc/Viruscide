#include "ItemDrop.h"


ItemDrop::ItemDrop(float spawn_xPos, float spawn_yPos, int spawn_ItemType)
{
	// Assign passed in variables
	xPos = spawn_xPos;
	yPos = spawn_yPos;
	ItemType = spawn_ItemType;
	// Draw Calls
	//drawItem();

	if (!itemTexture.loadFromFile("Resources/Images/ItemDrop1.png"))
	{
		std::cout << "Item texture failed loading" << std::endl;
	}

	itemSprite.setTexture(itemTexture);
	itemSprite.setOrigin(itemSprite.getGlobalBounds().width / 2, itemSprite.getGlobalBounds().height / 2);
	itemSprite.setPosition(sf::Vector2f(xPos, yPos));
}


ItemDrop::ItemDrop()
{

}


ItemDrop::~ItemDrop()
{

}

// old convex shape draw call

//void ItemDrop::drawItem()
//{
//	this->setPointCount(6);
//	this->setPoint(0, sf::Vector2f(TILE_SIZE / 2, 25));
//	this->setPoint(1, sf::Vector2f(TILE_SIZE - 30, TILE_SIZE / 4));
//	this->setPoint(2, sf::Vector2f(TILE_SIZE - 30, TILE_SIZE*0.75));
//	this->setPoint(3, sf::Vector2f(TILE_SIZE / 2, TILE_SIZE - 25));
//	this->setPoint(4, sf::Vector2f(15, TILE_SIZE*0.75));
//	this->setPoint(5, sf::Vector2f(15, TILE_SIZE / 4));
//	this->setOutlineThickness(5);
//
//	if (ItemType == 1)
//	{
//		this->setOutlineColor(sf::Color::Yellow);
//		this->setFillColor(sf::Color::Black);
//	}
//	if (ItemType == 2)
//	{
//		this->setOutlineColor(sf::Color::Yellow);
//		this->setFillColor(sf::Color::Black);
//	}
//}

sf::Sprite ItemDrop::getSprite()
{
	return (itemSprite);
}

sf::Vector2f ItemDrop::getPosition()
{
	return (itemSprite.getPosition());
}

sf::FloatRect ItemDrop::getGlobalBounds()
{
	return (itemSprite.getGlobalBounds());
}

