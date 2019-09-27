#pragma once

#include "Tile.h"

class GridMap
{
public:
	explicit Grid(sf::RenderWindow &window);
	~GridMap() = default;

	void draw();

	Tile &getTile(int i, int j);

private:
	void loadFromCSV(const std::string &filename);

	sf::Texture texture;

	std::vector<std::vector<Tile>> matrix;
	sf::RenderWindow &window;
};
