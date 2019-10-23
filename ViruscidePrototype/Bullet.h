//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Bullet.h
// Description	: Class definition for Bullet
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

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
	bool ExpiredBullet;
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
	bool DestinationIsDead();
};
