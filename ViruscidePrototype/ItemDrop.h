//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: ItemDrop.h
// Description	: Class definition for ItemDrop
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "Utils.h"
#include "Grid.h"
#include <math.h>


class ItemDrop
{
	sf::Sprite itemSprite;
	sf::Texture itemTexture;

	int Value;
	int xPos;
	int yPos;
	int ItemType;

public:

	ItemDrop(float spawn_xPos, float spawn_yPos, int spawn_ItemType);
	ItemDrop();
	~ItemDrop();
	void drawItem();

	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	sf::FloatRect getGlobalBounds();
};
