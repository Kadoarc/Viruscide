#pragma once
#include "MoveableEntity.h"
#include <math.h>
#include "Enemy.h"

class Bullet :
	public MoveableEntity
{
public:
	Bullet(const sf::Vector2f& position, const Enemy& destination, const float speed);
	Bullet();
	~Bullet();

private:
	Enemy m_destination;
	bool m_isDestinationAchieved;
	float m_degree;
	sf::Vector2f unitVector;

	void updateMovementDirections();

public:

	void update();
	void setDestination(const Enemy& destination);
	bool isDestinationAchieved() const;
};

