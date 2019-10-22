//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Bullet.cpp
// Description	: Creating and managing bullets
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#include "Bullet.h"


/*

*/



Bullet::Bullet(const sf::Vector2f startLoc, const sf::Vector2f dest) : pos(startLoc), destination(dest)
{
	auto delta = dest - startLoc;
	float length = sqrt(delta.x*delta.x + delta.y*delta.y);
	dir = (delta / length);
}

sf::Rect<float> Bullet::getHitBox()
{
	return hitbox;
}

sf::Vector2f Bullet::getPos()
{
	return sf::Vector2f();
}

bool Bullet::InstersectsWith(Enemy * enemy)
{
	return false;
}

sf::Vector2f Bullet::getPos()
{
	return pos;
}

bool Bullet::IntersectsWith(Enemy* enemy)
{
	if (hitbox.intersects(enemy->getHitbox()))
		return true;
	else
		return false;
}

void Bullet::update(const float dt)
{
	pos += dir * dt*speed;
	sprite.setPosition(pos);
	hitbox = { pos.x - size / 2, pos.y - size / 2, size, size };
}

Bullet::~Bullet()
{
}

bool Bullet::targetReached()
{
	{

		if (dir.x > 0 && pos.x >= destination.x)
		{
			hitbox = { pos.x - radius / 2,pos.y - radius / 2 , radius , radius };
			return true;
		}
		if (dir.y < 0 && pos.y <= destination.y)
		{
			hitbox = { pos.x - radius / 2,pos.y - radius / 2 , radius , radius };
			return true;
		}
		if (dir.x < 0 && pos.x <= destination.x)
		{
			hitbox = { pos.x - radius / 2,pos.y - radius / 2 , radius , radius };
			return true;
		}
		if (dir.y > 0 && pos.y >= destination.y)
		{
			hitbox = { pos.x - radius / 2,pos.y - radius / 2 , radius , radius };
			return true;
		}

		return false;
	}
}

