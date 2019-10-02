#include "Tower.h"
#include "Bullet.h"

void Tower::UpgradeLevel()
{
	level++;
}

int Tower::GetLevel()
{
	return level;
}

void Tower::SetDamage()
{
	damage += GetDamage() / level;
}

float Tower::GetDamage()
{
	return damage;
}

void Tower::SetRange()
{
	range += range / 5;
}

sf::CircleShape* Tower::GetRange()
{
	return rangeHelper;
}

void Tower::SetFireRate(float rate)
{
	fireRate = rate;
}
float Tower::GetFireRate()
{
	return fireRate;
}
void Tower::Update(sf::RenderWindow &window)
{
	if (isBuilt)
	{
		if (!this->GetIsReadyToFire() && collector < sf::seconds(1))
		{
			collector += TIME_PASED;
		}
		else
		{
			collector = clock.restart();
			this->SetIsReadyToFire(true);
		}

	}
	else
	{
		this->setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	}

}

bool Tower::GetIsReadyToFire()
{
	return isReadyToFire;
}

void Tower::SetIsReadyToFire(bool ready)
{
	isReadyToFire = ready;
}

sf::CircleShape* Tower::DrawPlacementAssist(sf::RenderWindow &window)
{
	rangeHelper->setRadius(range);
	rangeHelper->setFillColor(sf::Color::Transparent);
	rangeHelper->setOutlineColor(this->getFillColor());
	rangeHelper->setOutlineThickness(3);
	rangeHelper->setOrigin(sf::Vector2f(120, 120));
	rangeHelper->setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	return rangeHelper;
}

std::string Tower::GetName()
{
	return name;
}

Tower::Tower(int xPos, int yPos, TowerType type) : damage{ 10 }, range{ 120 }, price{ 100 }, fireRate{ 2 }, level{ 1 }, elementalDamge{ 0 }
{
	this->setPointCount(3);
	this->setPoint(0, sf::Vector2f(TILE_SIZE / 2, TILE_SIZE / 4));
	this->setPoint(1, sf::Vector2f(TILE_SIZE*0.75, TILE_SIZE*0.75));
	this->setPoint(2, sf::Vector2f(TILE_SIZE*0.25, TILE_SIZE*0.75));
	this->setOrigin(sf::Vector2f(TILE_SIZE / 2, TILE_SIZE / 2));
	this->setPosition(sf::Vector2f(xPos, yPos));
	this->type = type;
	if (type == TowerType::basic)
	{
		sf::Texture Tow1Tex;
		Tow1Tex.loadFromFile("Resources/Images/Tower1.png");
		
		if (!Tow1Tex.loadFromFile("Tower1.png"))
		{
			std::cout << "Not Loaded";
		}
		
		this->setFillColor(sf::Color(128, 128, 128));
	}
	else
	{
		this->setFillColor(type == TowerType::rapid ? sf::Color(255, 0, 0) : sf::Color(0, 0, 255));
	}
	rangeHelper = new sf::CircleShape(range);
	SetTowerTraits(type);

}

float Tower::GetElementalDamage()
{
	return elementalDamge;
}

void Tower::SetTowerTraits(TowerType type)
{
	switch (type)
	{
	case basic:
		elementalDamge = 50;
		price = 100;
		break;
	case rapid:
		elementalDamge = 20;
		price = 100;
		break;
	default:
		break;
	}
}
TowerType Tower::GetType()
{
	return type;
}

int Tower::GetPrice()
{
	return price;
}

void Tower::SetState()
{
	isBuilt = true;
	rangeHelper->setRadius(range);
	rangeHelper->setFillColor(sf::Color::Transparent);
	rangeHelper->setOutlineColor(this->getFillColor());
	rangeHelper->setOutlineThickness(3);
	rangeHelper->setOrigin(sf::Vector2f(120, 120));
	rangeHelper->setPosition(this->getPosition().x, this->getPosition().y);
}

bool Tower::GetIsBuilt()
{
	return isBuilt;
}
Tower::Tower()
{

}

Tower::~Tower()
{
}