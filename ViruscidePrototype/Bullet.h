#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include "Tower.h"
#include "Game.h"

class Bullet : public sf::CircleShape
{
	float damage;
	TowerType element;
	float elementalDamage;
	float speed;
	Enemy* destination;
	bool missed;

public:
	void Update();
	Bullet(Tower* t, Enemy* destination);
	Bullet(float damage, std::string element, float elementalDamage);
	~Bullet();
	void SetDamage(float damage);
	float GetDamage();
	void SetElement(TowerType type);
	TowerType GetElement();
	void SetElementalDamage(float damage);
	float GetElementalDamage();
	bool CollisionDetect();
};
