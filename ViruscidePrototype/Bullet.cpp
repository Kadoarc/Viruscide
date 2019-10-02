#include "Bullet.h"


Bullet::Bullet(const sf::Vector2f& position, const Enemy& destination, const float speed)
	: MoveableEntity(position, Globals::defaultBulletSize, speed, sf::Vector2i(0, 0)), m_isDestinationAchieved(false)
{
	this->m_destination = destination;
}

Bullet::Bullet()
	: MoveableEntity(sf::Vector2f(0, 0), Globals::defaultBulletSize, Globals::defaultBulletSpeed, sf::Vector2i(0, 0)), m_isDestinationAchieved(false)
{}

Bullet::~Bullet()
{}

void Bullet::update()
{
	if (this->m_isDestinationAchieved)
		return;

	if (this->isCollision(m_destination))//this->isCollisionWithRect(m_destination.getHitbox()))
	{
		this->m_isDestinationAchieved = true;
		return;
	}

	/* Do the movement */
	updateMovementDirections();
	this->moveTo(unitVector * Globals::defaultBulletSpeed);

}

void Bullet::setDestination(const Enemy& destination)
{
	this->m_destination = destination;
}

bool Bullet::isDestinationAchieved() const
{
	return this->m_isDestinationAchieved;
}

void Bullet::updateMovementDirections()
{
	sf::Vector2f distance;

	/* Calculate the distance between our bullet and the center of our destination */
	//distance.x = fabs(this->getPosition().x - m_destination.getCenter().x);
	//distance.y = fabs(this->getPosition().y - m_destination.getCenter().y);
	distance = this->getPosition() - m_destination.getPosition();
	float magnitude = sqrt((distance.x * distance.x) + (distance.y*distance.y));
	/* Calculate the degree we have to move at */
	unitVector = sf::Vector2f(distance.x*(-1) / magnitude, distance.y*(-1) / magnitude);

	//this->m_degree = degree;

}


