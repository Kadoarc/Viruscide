#include "Tile.h"



Tile::Tile()
	: tileNumber(0)
	, state(Tile::Type::None)
{
}


Tile::~Tile()
{
}

void Tile::setState(Type state)
{
	this->state = state;
}

void Tile::setTexture(const sf::Texture & texture, sf::IntRect rect)
{
	sprite.setTexture(texture);
	sprite.setTextureRect(rect);
}

void Tile::setTileNumber(int number)
{
	tileNumber = number;
}

Tile::Type Tile::getState() const
{
	return state;
}

int Tile::getTileNumber() const
{
	return tileNumber;
}

void Tile::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite, states);
}
