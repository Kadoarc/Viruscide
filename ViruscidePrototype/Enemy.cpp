#include "Enemy.h"


Enemy::Enemy(const sf::Vector2f& position,
	const sf::Vector2f& size,
	const float speed,
	const sf::Vector2i& movementDirection,
	const uint16_t health)

	: MoveableEntity(position, size, speed, movementDirection), m_health(health)
{
	this->setColour(Globals::Color::enemyColor);
	m_startingHealth = this->m_health;
}

Enemy::Enemy()
	: MoveableEntity(sf::Vector2f(0, 0), Globals::enemySize,
		Globals::EnemyTypes::enemyObjects[Globals::enemyType::defaultType].moveSpeed,
		sf::Vector2i(0, 0)),
	m_health(Globals::EnemyTypes::enemyObjects[Globals::enemyType::defaultType].hp)
{
	this->setColour(Globals::Color::enemyColor);
	m_startingHealth = this->m_health;
}

Enemy::~Enemy()
{
}

int16_t Enemy::getHealth() const
{
	return this->m_health;
}

int16_t Enemy::getStartingHealth() const
{
	return m_startingHealth;
}

bool Enemy::isAlive() const
{
	return this->m_alive;
}

bool Enemy::isInCollision() const
{
	return this->m_isDuringCollision;
}

void Enemy::setColour(const sf::Color & newColor)
{
	Entity::setColour(newColor);
	m_startingColor = newColor;
}

void Enemy::setHealth(const int16_t health)
{
	this->m_health = health;
	sf::Color color = m_startingColor;
	color.a = (this->m_health*color.a) / m_startingHealth;

	Entity::setColour(color);
}

void Enemy::setAlive(const bool alive)
{
	this->m_alive = alive;
}

void Enemy::setIsDuringCollision(const bool isDuringCollision)
{
	this->m_isDuringCollision = isDuringCollision;
}

