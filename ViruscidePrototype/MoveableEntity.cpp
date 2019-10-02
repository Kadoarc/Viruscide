#include "MoveableEntity.h"


MoveableEntity::MoveableEntity(const sf::Vector2f& position,
	const sf::Vector2f& size,
	const float speed,
	const sf::Vector2i& movementDirection)

	: Entity(position, size), m_speed(speed), m_movementDirection(movementDirection)
{}

MoveableEntity::MoveableEntity(float xPos, float yPos, const sf::Vector2f & size, const float speed)
	: Entity(xPos, yPos, size, speed)
{
}

MoveableEntity::~MoveableEntity()
{}

void MoveableEntity::setSpeed(float speed)
{
	this->m_speed = speed;
}

float MoveableEntity::getSpeed() const
{
	return m_speed;
}

void MoveableEntity::setMovementDirection(const sf::Vector2i& movementDirection)
{
	this->m_movementDirection = movementDirection;
}

void MoveableEntity::setMovementX(const int direction)
{
	setMovementDirection(sf::Vector2i(direction, m_movementDirection.y));
}

void MoveableEntity::setMovementY(const int direction)
{
	setMovementDirection(sf::Vector2i(m_movementDirection.x, direction));
}

int MoveableEntity::getMovementX() const
{
	return this->m_movementDirection.x;
}

int MoveableEntity::getMovementY() const
{
	return this->m_movementDirection.y;
}

void MoveableEntity::move()
{
	setPosition(sf::Vector2f(m_movementDirection.x * m_speed + getPosition().x, m_movementDirection.y  * m_speed + getPosition().y));
}

void MoveableEntity::moveTo(const sf::Vector2f & offset)
{
	this->hitbox.move(offset);
}
