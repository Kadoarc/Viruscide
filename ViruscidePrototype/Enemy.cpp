//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Enemy.cpp
// Description	: Handles creating and managing enemies
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#include "Enemy.h"
#include "Game.h"
#include "Bullet.h"


void Enemy::DrawEnemy(sf::RenderWindow& _window)
{		
	_window.draw(enemySprite);
}

sf::Rect<float> Enemy::getHitbox()
{
	return hitbox;
}

Enemy::Enemy(int xPos, int yPos, EnemyType type) :Health{ 20 }, Speed{ 4 }, value{ 10 }, previousPath{ nullptr }, nextPath{ nullptr }, isAtDestination{ true }, currentPath{ nullptr }, IsAtCore{ false }, hasWon{ false }, OTDamage{ 0 }
{
	if (!enemyTexture.loadFromFile("Resources/Images/Enemy1.png"))
	{
		std::cout << "enemy texture failed loading" << std::endl;
	}
	
	if (!enemyTexture1.loadFromFile("Resources/Images/Enemy2.png"))
	{
		std::cout << "enemy texture failed loading" << std::endl;
	}

	if (!enemyTexture2.loadFromFile("Resources/Images/Enemy3.png"))
	{
		std::cout << "enemy texture failed loading" << std::endl;
	}
	

	switch (type)
	{
	case normal:
		enemySprite.setTexture(enemyTexture);
		enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
		enemySprite.setPosition(sf::Vector2f(xPos, yPos));
		break;
	case fat:
		Speed = 2;
		Health *= 5;
		enemySprite.setTexture(enemyTexture1);
		enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
		enemySprite.setPosition(sf::Vector2f(xPos, yPos));
	case fast:
		Health = 100;
		Speed = 6;
		enemySprite.setTexture(enemyTexture2);
		enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
		enemySprite.setPosition(sf::Vector2f(xPos, yPos));

	}
	//this->setPosition(xPos, yPos);
	//this->setOrigin(TILE_SIZE / 2, TILE_SIZE / 2);
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



void Enemy::GiveDamage(Bullet* bullet)
{
	this->Health -= bullet->GetDamage();

	if (bullet->GetElementalDamage() > 0 && !this->isHit)
	{
		
		if (bullet->GetElement() == TowerType::basic && EnemyType::normal)
		{
			this->Health -= bullet->GetElementalDamage();
			isHit = true;
			OTDamage = bullet->GetElementalDamage();
			
		}
		else if (bullet->GetDamage() == TowerType::basic && EnemyType::fast)
		{
			this->Health -= bullet->GetDamage();
			isHit = true;
			OTDamage = bullet->GetDamage();;
		}
		else if (bullet->GetElement() == TowerType::basic && EnemyType::fat)
		{
			this->Health -= bullet->GetDamage();
			isHit = true;
			OTDamage = bullet->GetDamage();;
		}
		}
		if (bullet->GetElement() == TowerType::rapid && EnemyType::fast)
		{
			isHit = true;
			OTDamage = bullet->GetElementalDamage();
		}
		else
		{
			
		}
	}



bool Enemy::GetHasWon()
{
	return hasWon;
}

void Enemy::Update()
{
	Health -= OTDamage;

	if (nextPath)
	{
		sf::Vector2f direction = nextPath->getPosition() - enemySprite.getPosition();
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
		enemySprite.setPosition(enemySprite.getPosition() + direction);
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

sf::Sprite Enemy::getSprite()
{
	return (enemySprite);
}

sf::Vector2f Enemy::getPosition()
{
	return (enemySprite.getPosition());
}

sf::FloatRect Enemy::getGlobalBounds()
{
	return (enemySprite.getGlobalBounds());
}

sf::Vector2f Enemy::getLocation() const
{
	return pos;
}


