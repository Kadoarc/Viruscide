#include "Enemy.h"
#include "Game.h"
#include "Bullet.h"


void Enemy::DrawEnemy(sf::RenderWindow& _window)
{		
	_window.draw(enemySprite);
}

Enemy::Enemy(int xPos, int yPos) :Health{ 20 }, Speed{ 4 }, value{ 10 }, previousPath{ nullptr }, nextPath{ nullptr }, isAtDestination{ true }, currentPath{ nullptr }, IsAtCore{ false }, hasWon{ false }, OTDamage{ 0 }
{
	if (!enemyTexture.loadFromFile("Resources/Images/Enemy1.png"))
	{
		std::cout << "enemy texture failed loading" << std::endl;
	}

	enemySprite.setTexture(enemyTexture);
	enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
	enemySprite.setPosition(sf::Vector2f(xPos, yPos));
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

void Enemy::Draw()
{
}

void Enemy::GiveDamage(Bullet* bullet)
{
	this ->Health -= bullet->GetDamage();

	if (bullet->GetElementalDamage() > 0 && !this->isHit)
	{
		this->Health -= bullet->GetElementalDamage();
		if (bullet->GetElement() == TowerType::basic)
		{
			isHit = true;
			OTDamage = bullet->GetElementalDamage();
		}
		else
		{
			isHit = true;
			Speed /= 2;
		}
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
