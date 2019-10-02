#pragma once
#include"MoveableEntity.h" 

class Enemy : public MoveableEntity
{
public:

	Enemy(const sf::Vector2f& position, const sf::Vector2f& size, const float speed, const sf::Vector2i& movementDirection, const uint16_t health);
	Enemy();
	~Enemy();

private:

	int16_t m_health;
	bool m_alive = true;
	bool m_isDuringCollision = false;
	int16_t m_startingHealth;
	sf::Color m_startingColor;

public:

	int16_t getHealth() const;
	int16_t getStartingHealth() const;
	bool isAlive() const;
	bool isInCollision() const;

	void setColour(const sf::Color & newColor);
	void setHealth(const int16_t health);
	void setAlive(const bool alive);
	void setIsDuringCollision(const bool isCollision);

};

