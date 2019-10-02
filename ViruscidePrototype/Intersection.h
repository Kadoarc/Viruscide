#pragma once
#include "UnMoveableEntity.h"

class Intersection :
	public UnMoveableEntity
{

public:

	Intersection(const sf::Vector2f& position, const sf::Vector2f& size, const short exit);
	Intersection(const sf::Vector2f& position, const short exit);
	Intersection();
	~Intersection();

	short getExit() const;
	void setExit(const short cardinal);

private:

	short m_exit;

};

