#include "playerBullet.h"

PlayerBullet::PlayerBullet(float rotationAngle, Tower* origin)
{
	currentRotation = rotationAngle;
	this->speed = 1.0f;
	this->setRadius(10);
	this->setPosition(origin->getPosition());
	//this->setPosition(sf::Vector2f(100,100));
	this->setOrigin(TILE_SIZE / 4, TILE_SIZE / 4);
	this->setFillColor(origin->getFillColor());
	//this->SetDamage(origin->GetDamage());
	//this->SetElementalDamage(origin->GetElementalDamage());
	//this->SetElement(origin->GetType());
}

PlayerBullet::~PlayerBullet()
{

}

void PlayerBullet::Update()
{
	this->move(speed * std::cos(currentRotation), speed * std::sin(currentRotation));
}