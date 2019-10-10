#include "Grid.h"



void Grid::SetIsEmpty(bool gridState)
{
	isEmpty = gridState;
}

bool Grid::GetIsEmpty()
{
	return isEmpty;;
}

void Grid::SetGridType(GridType type)
{
	tileType = type;
	this->setFillColor(type == GridType::hill ? sf::Color::Yellow : sf::Color::White);
}

char Grid::GetTileType()
{
	return tileType;
}

Grid::Grid(int xPos, int yPos, int type)
{
	this->setPointCount(4);
	this->setOrigin(TILE_SIZE / 2, TILE_SIZE / 2);
	this->setPoint(1, sf::Vector2f(0 + TILE_SIZE, 0));
	this->setPoint(2, sf::Vector2f(0 + TILE_SIZE, 0 + TILE_SIZE));
	this->setPoint(3, sf::Vector2f(0, 0 + TILE_SIZE));
	this->setPosition(sf::Vector2f(xPos, yPos));
	this->setFillColor(type == GridType::hill ? sf::Color(100, 255, 100) : sf::Color(0, 0, 0));

	if (!normalTilesTexture.loadFromFile("Resources/Images/ViruscideNormalTile"))
	{
		std::cout << "error loading normal tile textures" << std::endl;
	}

	if (!pathTilesTexture.loadFromFile("Resources/Images/ViruscidePathTile"))
	{
		std::cout << "error loading normal tile textures" << std::endl;
	}

	normalTileSprite.setTexture(normalTilesTexture);
	normalTileSprite.setOrigin(normalTileSprite.getGlobalBounds().width / 2, normalTileSprite.getGlobalBounds().height / 2);
	//normalTileSprite.setPosition

	pathTileSprite.setTexture(pathTilesTexture);
	pathTileSprite.setOrigin(pathTileSprite.getGlobalBounds().width / 2, pathTileSprite.getGlobalBounds().height / 2);
	//pathTileSprite.setPosition
}


Grid::~Grid()
{
}
