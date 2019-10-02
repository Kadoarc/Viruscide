#include "Intersection.h"


Intersection::Intersection(const sf::Vector2f& position, const sf::Vector2f& size, const short exit)
	: UnMoveableEntity(position, size), m_exit(exit)
{
	this->setColour(Globals::Color::intersectionColor);
}

Intersection::Intersection(const sf::Vector2f & position, const short exit)
	: UnMoveableEntity(position, sf::Vector2f(Globals::intersectionSize, Globals::intersectionSize)), m_exit(exit)
{
	this->setColour(Globals::Color::intersectionColor);
}

Intersection::Intersection()
	: UnMoveableEntity(sf::Vector2f(0, 0), sf::Vector2f(Globals::intersectionSize, Globals::intersectionSize)), m_exit(Globals::Cardinals::North)
{
	this->setColour(Globals::Color::intersectionColor);
}


Intersection::~Intersection()
{
}

short Intersection::getExit() const
{
	return this->m_exit;
}

void Intersection::setExit(const short cardinal)
{
	m_exit = cardinal;
}


