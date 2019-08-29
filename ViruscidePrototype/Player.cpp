#include "Player.h"


Player::Player(float xPos, float yPos)
{
	drawPlayer();
	this->setPosition(xPos, yPos);
	this->setOrigin(TILE_SIZE / 2, TILE_SIZE / 2);
}

Player::Player(float xPos, float yPos)
{
	drawPlayer();
	this->setPosition(xPos, yPos);
	this->setOrigin(TILE_SIZE / 2, TILE_SIZE / 2);
}

Player::Player()
{
}


Player::~Player()
{
}

void Player::drawPlayer()
{
	this->setPointCount(6);
	this->setPoint(0, sf::Vector2f(TILE_SIZE / 2, 25));
	this->setPoint(1, sf::Vector2f(TILE_SIZE - 30, TILE_SIZE / 4));
	this->setPoint(2, sf::Vector2f(TILE_SIZE - 30, TILE_SIZE*0.75));
	this->setPoint(3, sf::Vector2f(TILE_SIZE / 2, TILE_SIZE - 25));
	this->setPoint(4, sf::Vector2f(15, TILE_SIZE*0.75));
	this->setPoint(5, sf::Vector2f(15, TILE_SIZE / 4));
	this->setFillColor(sf::Color::Cyan);

}
