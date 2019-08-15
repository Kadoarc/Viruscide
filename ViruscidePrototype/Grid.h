#pragma once
#include <SFML/Graphics.hpp>
#include "Utils.h"
class Grid :public sf::ConvexShape
{
	bool isEmpty = true;
	char tileType = GridType::hill;
	sf::Texture tileset;
public:
	void SetIsEmpty(bool gridState);
	bool GetIsEmpty();
	void SetGridType(GridType type);
	char GetTileType();
	Grid(int xPos, int yPos, int type);
	~Grid();
};

