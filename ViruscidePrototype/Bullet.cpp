#include "Bullet.h"



void Bullet::Update()
{

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

}

Bullet::Bullet(Tower* originTower, Enemy* destination) : speed{ 4 }, elementalDamage{ 0 }, missed{ false }
{
	this->destination = destination;
	this->setRadius(10);
	this->setPosition(originTower->getPosition());
	this->setOrigin(TILE_SIZE / 4, TILE_SIZE / 4);
	this->setFillColor(originTower->getFillColor());
	this->SetDamage(originTower->GetDamage());
	this->SetElementalDamage(originTower->GetElementalDamage());
	this->SetElement(originTower->GetType());
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

