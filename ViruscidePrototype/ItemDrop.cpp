//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: ItemDrop.cpp
// Description	: Handles the creation and managing of item drops
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

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

