#pragma once
#include "Entity.h"

class MoveableEntity : public Entity
{
public:
	MoveableEntity(const sf::Vector2f& position, const sf::Vector2f& size, const float speed, const sf::Vector2i& movementDirection);
	MoveableEntity(float xPos, float yPos, const sf::Vector2f& size, const float speed);
	~MoveableEntity();


protected:

	float m_speed;

private:

	sf::Vector2i m_movementDirection;

public:

	void setSpeed(const float speed);
	float getSpeed() const;
	void setMovementDirection(const sf::Vector2i& movementDirection);
	void setMovementX(const int direction);
	void setMovementY(const int direction);

	int getMovementX() const;
	int getMovementY() const;

	void move();
	void moveTo(const sf::Vector2f& offset);

};

