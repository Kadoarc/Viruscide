//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Grid.h
// Description	: Class definition for Grid
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

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

