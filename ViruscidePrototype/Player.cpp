#include "Player.h"



Player::Player(const sf::Vector2f & position, const sf::Vector2f & size, const float speed, const sf::Vector2i & movementDirection)
	:MoveableEntity(position, size, speed, movementDirection)
{
	this->setColour(Globals::Color::playerColor);

}

Player::Player()
	: MoveableEntity(sf::Vector2f(0, 0), Globals::playerSize, (5.0f), sf::Vector2i(0, 0))
{
	this->setColour(Globals::Color::playerColor);
}



Player::~Player()
{
}

void Player::drawPlayer()
{

	this->setColour(Globals::Color::playerColor);
}

void Player::movePlayer()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		std::cout << "E pressed \n";
	}
}

void Player::moveNorth()
{
	yPos -= 1.0f;
	setXYPosition(xPos, yPos);
}

void Player::moveEast()
{
	xPos += 1.0f;
	setXYPosition(xPos, yPos);
}

void Player::moveWest()
{
	xPos -= 1.0f;
	setXYPosition(xPos, yPos);
}

void Player::moveSouth()
{
	yPos += 1.0f;
	setXYPosition(xPos, yPos);
}

bool Player::OverlapTower() const
{
	return false;
}

void Player::setOverlapTower(const bool isOverlapping)
{

}

sf::RectangleShape Player::getMainHitbox() const
{
	return this->m_player1.getHitbox();
}
