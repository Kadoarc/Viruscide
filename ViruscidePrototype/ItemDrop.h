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
