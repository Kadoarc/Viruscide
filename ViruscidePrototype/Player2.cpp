#include "Player2.h"



Player2::Player2(const sf::Vector2f & position, const sf::Vector2f & size, const float speed, const sf::Vector2i & movementDirection)
	:MoveableEntity(position, size, speed, movementDirection)
{
	this->setColour(Globals::Color::player2Color);

}

Player2::Player2()
	: MoveableEntity(sf::Vector2f(0, 0), Globals::playerSize, (5.0f), sf::Vector2i(0, 0))
{
	this->setColour(Globals::Color::player2Color);
}



Player2::~Player2()
{
}

void Player2::drawPlayer()
{

	this->setColour(Globals::Color::player2Color);
}

void Player2::movePlayer()
{


}

void Player2::moveNorth()
{
	yPos -= 1.0f;
	setXYPosition(xPos, yPos);
}

void Player2::moveEast()
{
	xPos += 1.0f;
	setXYPosition(xPos, yPos);
}

void Player2::moveWest()
{
	xPos -= 1.0f;
	setXYPosition(xPos, yPos);
}

void Player2::moveSouth()
{
	yPos += 1.0f;
	setXYPosition(xPos, yPos);
}

bool Player2::OverlapTower() const
{
	return false;
}

void Player2::setOverlapTower(const bool isOverlapping)
{

}

sf::RectangleShape Player2::getMainHitbox() const
{
	return this->m_player2.getHitbox();
}
