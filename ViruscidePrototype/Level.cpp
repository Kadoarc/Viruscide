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
			if (level[y][x] == 1)
			{
				map[index]->SetGridType(GridType::path);
			}
			else if (level[y][x] == 2)
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
