//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Level.cpp
// Description	: Class for handling and managing levels
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#include "Level.h"

Level::Level()
{
}


Level::~Level()
{
}

void Level::CreateLevel()
{
	int path = 0;
	for (int j = 42; j < FullHdresolution::y; j += TILE_SIZE)
	{
		for (int i = GUI_OFFSET; i < FullHdresolution::x - GUI_OFFSET; i += TILE_SIZE)
		{
			map.push_back(new Grid(i, j, GridType::hill));
			i += TILE_OFFSET;
		}
		j += TILE_OFFSET;
	}
	LoadLevel();

}

void Level::LoadLevel()
{
	for (int y = 0; y < lvlHeight; y++)
	{
		for (int x = 0; x < lvlWidth; x++)
		{
			int index = y * lvlWidth + x;
			if (level2[y][x] == 1)
			{
				map[index]->SetGridType(GridType::path);
			}
			else if (level2[y][x] == 2)
			{
				map[index]->SetGridType(GridType::core);
			}
		}
	}

}

std::vector<Grid*> Level::GetMap()
{
	return map;
}
