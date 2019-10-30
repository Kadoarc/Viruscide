#pragma once

#include "Enemy.h"
#include <math.h>
#define PI 3.14159f
class Projectile : sf::CircleShape
{
protected:
	sf::Vector2f pos;
	std::shared_ptr<sf::Texture> texture;
	sf::Sprite sprite;
	sf::Rect<float> hitbox;
	float speed;
	float size;
	float radius;
	float damage;
	sf::Vector2f dir;
	sf::Vector2f destination;
public:
	virtual void draw(sf::RenderTarget &wnd) const;
	virtual void dealDamage(Enemy* tarPtr) = 0;
	virtual void update(const float dt);
	Projectile(const sf::Vector2f startLoc, const sf::Vector2f dest);
	bool targetReached();
	sf::Rect<float> getHitbox();
	sf::Vector2f getPos();
	bool IntersectsWith(Enemy *enemy);
};