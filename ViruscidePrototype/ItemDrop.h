#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "Utils.h"
#include "Grid.h"
#include <math.h>


class ItemDrop : public sf::ConvexShape
{
	int Value;
	int xPos;
	int yPos;
	int ItemType;

public:

	ItemDrop(float spawn_xPos, float spawn_yPos, int spawn_ItemType);
	ItemDrop();
	~ItemDrop();
	void drawItem();
};
