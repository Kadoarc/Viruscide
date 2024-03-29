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

/***********************
* Update: moves the bullet towards its destination.
* Parameters: NULL
* Return: NULL
********************/
void Bullet::Update()
{
	// If the destination x is < current x position
	if (destination->getPosition().x < this->getPosition().x)
	{
		if (destination->getPosition().y < this->getPosition().y)
		{
			this->setPosition(this->getPosition().x - speed, this->getPosition().y - speed);
		}
		else
		{
			this->setPosition(this->getPosition().x - speed, this->getPosition().y + speed);
		}
	}
	else if (destination->getPosition().y < this->getPosition().y)
	{
		this->setPosition(this->getPosition().x + speed, this->getPosition().y - speed);
	}
	else
	{
		this->setPosition(this->getPosition().x + speed, this->getPosition().y + speed);
	}

	if (this->DestinationIsDead())
	{
		ExpiredBullet = true;
	}

}

Bullet::Bullet(Tower* originTower, Enemy* destination) : speed{ 8 }, elementalDamage{ 0 }, missed{ false }
{
	this->destination = destination;
	this->setRadius(10);
	this->setPosition(originTower->getPosition());
	this->setOrigin(TILE_SIZE / 4, TILE_SIZE / 4);
	this->setFillColor(originTower->getFillColor(*originTower));
	this->SetDamage(originTower->GetDamage());
	this->SetElementalDamage(originTower->GetElementalDamage());
	this->SetElement(originTower->GetType());
	this->ElementTypeNum = originTower->TowerTypeNum;
}
Bullet::Bullet(float damage, std::string element, float elementalDamage)
{
	this->damage = damage;
}

Bullet::~Bullet()
{
}

void Bullet::SetDamage(float damage)
{
	this->damage = damage;
}

float Bullet::GetDamage()
{
	return damage;
}

void Bullet::SetElement(TowerType element)
{
	this->element = element;
}

TowerType Bullet::GetElement()
{
	return element;
}

void Bullet::SetElementalDamage(float damage)
{
	elementalDamage = damage;
}

float Bullet::GetElementalDamage()
{
	return elementalDamage;
}

bool Bullet::CollisionDetect()
{
	return false;
}

bool Bullet::DestinationIsDead()
{
	if (destination->GetHP() <= 0)
	{
		return true;
	}

	else return false;
}

