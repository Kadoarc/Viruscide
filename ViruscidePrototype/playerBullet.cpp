#include "playerBullet.h"

PlayerBullet::PlayerBullet(float rotationAngle, Tower* origin)
{
	currentRotation = rotationAngle;
	this->speed = 5.0f;
	this->setRadius(10);
	this->setPosition(origin->getPosition());
	//this->setPosition(sf::Vector2f(100,100));
	this->setOrigin(TILE_SIZE / 4, TILE_SIZE / 4);
	this->setFillColor(origin->getFillColor());
	this->SetDamage(origin->GetDamage());
	this->SetElementalDamage(origin->GetElementalDamage());
	this->SetElement(origin->GetType());
	this->ElementTypeNum = origin->TowerTypeNum;
}

PlayerBullet::~PlayerBullet()
{

}

void PlayerBullet::Update()
{
	//this->move(speed * std::cos(currentRotation), speed * std::sin(currentRotation));
	this->move(cos((double)currentRotation*3.14159 / 180.0)*speed, sin((double)currentRotation*3.14159 / 180.0)*speed);
}

void PlayerBullet::SetDamage(float damage)
{
	this->damage = damage;
}

float PlayerBullet::GetDamage()
{
	return damage;
}

void PlayerBullet::SetElement(TowerType element)
{
	this->element = element;
}

TowerType PlayerBullet::GetElement()
{
	return element;
}

void PlayerBullet::SetElementalDamage(float damage)
{
	elementalDamage = damage;
}

float PlayerBullet::GetElementalDamage()
{
	return elementalDamage;
}