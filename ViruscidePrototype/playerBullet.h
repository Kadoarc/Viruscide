//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: playerBullet.h
// Description	: Class definition for playerBullet
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include <math.h>
#include "Tower.h"
#define PI 3.1415926535
class PlayerBullet : public sf::CircleShape
{
	TowerType element;
	float damage;
	float elementalDamage;
	float speed;
	float destination;
	float currentRotation;
	float angle2 = (currentRotation);

	bool missed;

public:
	
	PlayerBullet(float rotationAngle, Tower* origin);
	~PlayerBullet();

	void Update();
	void SetDamage(float damage);
	void SetElement(TowerType type);
	TowerType GetElement();
	void SetElementalDamage(float damage);

	float GetElementalDamage();
	bool CollisionDetect();
	bool DestinationIsDead();
	float GetDamage();
	bool ExpiredBullet;
};
