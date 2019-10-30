#include "Projectile.h"


void Projectile::draw(sf::RenderTarget & wnd) const
{
	wnd.draw(sprite);
}

void Projectile::update(const float dt)
{
	pos += dir * dt*speed;
	sprite.setPosition(pos);
	hitbox = { pos.x - size / 2,pos.y - size / 2,size,size };

}

Projectile::Projectile(const sf::Vector2f startLoc, const sf::Vector2f dest)
	:
	pos(startLoc),
	destination(dest)
{
	auto delta = dest - startLoc;
	float length = sqrt(delta.x*delta.x + delta.y*delta.y);
	dir = (delta / length);

}

bool Projectile::targetReached()
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

sf::Rect<float> Projectile::getHitbox()
{
	return hitbox;
}

sf::Vector2f Projectile::getPos()
{
	return pos;
}

bool Projectile::IntersectsWith(Enemy * enemy)
{
	if (hitbox.intersects(enemy->getHitbox()))
		return true;
	else
		return false;
}
