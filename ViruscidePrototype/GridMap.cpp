#include <fstream>

#include "GridMap.h"
#include "Constants.h"

GridMap::Grid(sf::RenderWindow &window)
	: window(window)
{
	texture.loadFromFile("data/mapnospace.png");
	texture.setSmooth(true);

	matrix.resize(MAP_HEIGHT, std::vector<Tile>(MAP_WIDTH));
	loadFromCSV("data/map.csv");
}

void Grid::draw()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
		for (int j = 0; j < MAP_WIDTH; j++)
			window.draw(matrix[i][j]);
}

Tile &Grid::getTile(int i, int j)
{
	return matrix[i][j];
}

void Grid::loadFromCSV(const std::string &filename)
{
	std::ifstream fin(filename);

	char comma;
	int tileNumber;

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			fin >> tileNumber;

			matrix[i][j].setTileNumber(tileNumber);
			sf::IntRect rect{ TILE_SIZE * (tileNumber % 19), TILE_SIZE * (tileNumber / 19), TILE_SIZE, TILE_SIZE };
			matrix[i][j].setTexture(texture, rect);
			matrix[i][j].setPosition(static_cast<float>(j * TILE_SIZE), static_cast<float>(i * TILE_SIZE));

			if (tileNumber == 266) matrix[i][j].setState(Tile::Type::Valid);
			else matrix[i][j].setState(Tile::Type::Invalid);

			fin >> comma;
		}
	}

	fin.close();
}