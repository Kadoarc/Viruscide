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

	if (!enemyTexture3.loadFromFile("Resources/Images/Enemy4.png"))
	{
		std::cout << "enemy texture failed loading" << std::endl;
	}


	switch (type)
	{
	case normal:
		EnemyTypeNum = 0;
		Health = 10;
		Speed = 3;
		enemySprite.setTexture(enemyTexture);
		enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
		enemySprite.setPosition(sf::Vector2f(xPos, yPos));
		break;
	case fat:
		EnemyTypeNum = 1;
		Speed = 2;
		Health = 30;
		enemySprite.setTexture(enemyTexture1);
		enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
		enemySprite.setPosition(sf::Vector2f(xPos, yPos));
		break;
	case fast:
		EnemyTypeNum = 2;
		Health = 15;
		Speed = 3;
		enemySprite.setTexture(enemyTexture2);
		enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
		enemySprite.setPosition(sf::Vector2f(xPos, yPos));
		break;
	case yellow:
		EnemyTypeNum = 3;
		Health = 15;
		Speed = 3;
		enemySprite.setTexture(enemyTexture3);
		enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
		enemySprite.setPosition(sf::Vector2f(xPos, yPos));
		break;
	}
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

void Enemy::GiveDamage(Bullet* bullet)
{
	//this->Health -= bullet->GetDamage();

	if (bullet->GetDamage() > 0)
	{
		if (EnemyTypeNum == 0)
		{
			if (bullet->ElementTypeNum == 0)
			{
				std::cout << bullet->GetDamage()/4 << std::endl;
				this->Health -= bullet->GetDamage()/4;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}

			if (bullet->ElementTypeNum == 1)
			{
				std::cout << bullet->GetDamage() / 2 << std::endl;
				this->Health -= bullet->GetDamage() / 2;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}
			if (bullet->ElementTypeNum == 2)
			{
				std::cout << bullet->GetDamage() * 2 << std::endl;
				this->Health -= bullet->GetDamage() * 2;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}
		}
		if (EnemyTypeNum == 1)
		{
			if (bullet->ElementTypeNum == 0)
			{
				std::cout << bullet->GetDamage() / 3 << std::endl;
				this->Health -= bullet->GetDamage() / 3;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}

			if (bullet->ElementTypeNum == 1)
			{
				std::cout << bullet->GetDamage() / 2 << std::endl;
				this->Health -= bullet->GetDamage() / 2;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}
			if (bullet->ElementTypeNum == 2)
			{
				std::cout << bullet->GetDamage() * 2 << std::endl;
				this->Health -= bullet->GetDamage() * 2;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}
		}
		if (EnemyTypeNum == 2)
		{
			if (bullet->ElementTypeNum == 0)
			{
				std::cout << bullet->GetDamage() / 4 << std::endl;
				this->Health -= bullet->GetDamage() / 4;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}

			if (bullet->ElementTypeNum == 1)
			{
				std::cout << bullet->GetDamage() / 2 << std::endl;
				this->Health -= bullet->GetDamage() / 2;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}
			if (bullet->ElementTypeNum == 2)
			{
				std::cout << bullet->GetDamage() * 3 << std::endl;
				this->Health -= bullet->GetDamage() * 3;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}
		}
		if (EnemyTypeNum == 3)
		{
			if (bullet->ElementTypeNum == 0)
			{
				std::cout << bullet->GetDamage() / 4 << std::endl;
				this->Health -= bullet->GetDamage() / 4;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}

			if (bullet->ElementTypeNum == 1)
			{
				std::cout << bullet->GetDamage() / 2 << std::endl;
				this->Health -= bullet->GetDamage() / 2;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}
			if (bullet->ElementTypeNum == 2)
			{
				std::cout << bullet->GetDamage() * 2 << std::endl;
				this->Health -= bullet->GetDamage() * 2;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}
		}
	}
}

void Enemy::GiveDamage(PlayerBullet* bullet)
{
	if (bullet->GetDamage() >0)
	{
		if (EnemyTypeNum == 0)
		{
			if (bullet->ElementTypeNum == 0)
			{
				std::cout << bullet->GetDamage() * 1 << std::endl;
				this->Health -= bullet->GetDamage() * 1;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}

			if (bullet->ElementTypeNum == 1)
			{
				std::cout << bullet->GetDamage() * 1.5 << std::endl;
				this->Health -= bullet->GetDamage() * 1.5;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}
			if (bullet->ElementTypeNum == 2)
			{
				std::cout << bullet->GetDamage() * 3 << std::endl;
				this->Health -= bullet->GetDamage() * 3;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}
		}
		if (EnemyTypeNum == 1)
		{
			if (bullet->ElementTypeNum == 0)
			{
				std::cout << bullet->GetDamage() * 2 << std::endl;
				this->Health -= bullet->GetDamage() * 2;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}

			if (bullet->ElementTypeNum == 1)
			{
				std::cout << bullet->GetDamage() * 1.5 << std::endl;
				this->Health -= bullet->GetDamage() * 1.5;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}
			if (bullet->ElementTypeNum == 2)
			{
				std::cout << bullet->GetDamage() * 3 << std::endl;
				this->Health -= bullet->GetDamage() * 3;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}
		}
		if (EnemyTypeNum == 2)
		{
			if (bullet->ElementTypeNum == 0)
			{
				std::cout << bullet->GetDamage() * 2 << std::endl;
				this->Health -= bullet->GetDamage() * 2;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}

			if (bullet->ElementTypeNum == 1)
			{
				std::cout << bullet->GetDamage() * 1.5 << std::endl;
				this->Health -= bullet->GetDamage() * 1.5;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}
			if (bullet->ElementTypeNum == 2)
			{
				std::cout << bullet->GetDamage() * 3 << std::endl;
				this->Health -= bullet->GetDamage() * 3;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}
		}
		if (EnemyTypeNum == 3)
		{
			if (bullet->ElementTypeNum == 0)
			{
				std::cout << bullet->GetDamage() * 2 << std::endl;
				this->Health -= bullet->GetDamage() * 2;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}

			if (bullet->ElementTypeNum == 1)
			{
				std::cout << bullet->GetDamage() * 1.5 << std::endl;
				this->Health -= bullet->GetDamage() * 1.5;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}
			if (bullet->ElementTypeNum == 2)
			{
				std::cout << bullet->GetDamage() * 2.5 << std::endl;
				this->Health -= bullet->GetDamage() * 2.5;
				isHit = true;
				OTDamage = bullet->GetDamage();
			}
		}
	}
}

bool Enemy::GetHasWon()
{
	return hasWon;
}

void Enemy::Update()
{
	//Health -= OTDamage;

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


