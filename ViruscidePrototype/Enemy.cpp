#include "Enemy.h"
#include "Game.h"


void Enemy::DrawEnemy()
{
	/*
		sf::Texture texture;
	texture.loadFromFile("resources/images/Bacteria.png");
	sf::Sprite sprite(texture, sf::IntRect(0, 0, 10, 10));
	*/

	
	
	this->setPointCount(6);
		this->setPoint(0, sf::Vector2f(TILE_SIZE / 2, 25));
		this->setPoint(1, sf::Vector2f(TILE_SIZE - 30, TILE_SIZE / 4));
		this->setPoint(2, sf::Vector2f(TILE_SIZE - 30, TILE_SIZE*0.75));
		this->setPoint(3, sf::Vector2f(TILE_SIZE / 2, TILE_SIZE - 25));
		this->setPoint(4, sf::Vector2f(15, TILE_SIZE*0.75));
		this->setPoint(5, sf::Vector2f(15, TILE_SIZE / 4));
		this->setFillColor(sf::Color::Cyan);

		

}
Enemy::Enemy(int xPos, int yPos) :Health{ 20 }, Speed{ 4 }, value{ 50 }, previousPath{ nullptr }, nextPath{ nullptr }, isAtDestination{ true }, currentPath{ nullptr }, IsAtCore{ false }, hasWon{ false }, OTDamage{ 0 }
{
	DrawEnemy();
	this->setPosition(xPos, yPos);
	this->setOrigin(TILE_SIZE / 2, TILE_SIZE / 2);
	
}

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

bool Enemy::GetIsAtCore()
{
	return false;
}

void Enemy::SetIsAtCore()
{

}

void Enemy::Draw()
{
}

bool Enemy::GetHasWon()
{
	return hasWon;
}

void Enemy::Update()
{

	if (nextPath)
	{
		sf::Vector2f direction = nextPath->getPosition() - this->getPosition();
		float length = (float)sqrt(pow(direction.x, 2) + pow(direction.y, 2));
		if (length < 5)
		{
			isAtDestination = true;
			if (currentPath)
			{
				previousPath = currentPath;
			}

			currentPath = nextPath;
			nextPath = nullptr;
			return;
		}

		direction.x /= length;
		direction.y /= length;
		direction.x *= GetSpeed();
		direction.y *= GetSpeed();
		this->setPosition(this->getPosition() + direction);
	}
	else
	{
		this->hasWon = true;
	}
}

int Enemy::GetHP()
{
	return Health;
}

int Enemy::GetValue()
{
	return value;
}


int Enemy::GetSpeed()
{
	return Speed;
}
