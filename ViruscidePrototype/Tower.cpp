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
		towerSprite.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	}

}

sf::Color Tower::getFillColor()
{
	return(sf::Color::Cyan);
}

sf::FloatRect Tower::getGlobalBounds()
{
	return(towerSprite.getGlobalBounds());
}

sf::FloatRect Tower::getLocalBounds()
{
	return(towerSprite.getLocalBounds());
}

sf::Vector2f Tower::getPosition()
{
	return(towerSprite.getPosition());
}

void Tower::setOrigin(sf::Vector2f _vec)
{
	towerSprite.setPosition(_vec);
}

void Tower::setPosition(sf::Vector2f _vec)
{
	towerSprite.setOrigin(_vec);
}

void Tower::draw(sf::RenderWindow & _window)
{
	_window.draw(towerSprite);
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
	rangeHelper->setOutlineColor(sf::Color::Cyan);
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
	if (type == TowerType::basic)
	{	
		if (!towerTexture.loadFromFile("Resources/Images/Tower1.png"))
		{
			std::cout << "Tower1 texture not loaded";
		}
		
		towerSprite.setTexture(towerTexture);
		towerSprite.setOrigin(towerSprite.getGlobalBounds().width / 2, towerSprite.getGlobalBounds().height / 2);
		towerSprite.setPosition(sf::Vector2f(xPos, yPos));
	}
	else if (type == TowerType::rapid)
	{
		if (!towerTexture.loadFromFile("Resources/Images/Tower2.png"))
		{
			std::cout << "Tower2 texture not loaded";
		}

		towerSprite.setTexture(towerTexture);
		towerSprite.setOrigin(towerSprite.getGlobalBounds().width / 2, towerSprite.getGlobalBounds().height / 2);
		towerSprite.setPosition(sf::Vector2f(xPos, yPos));
	}
	else if (type == TowerType::ultimate)
	{
		if (!towerTexture.loadFromFile("Resources/Images/Tower3.png"))
		{
			std::cout << "Tower3 texture not loaded";
		}

		towerSprite.setTexture(towerTexture);
		towerSprite.setOrigin(towerSprite.getGlobalBounds().width / 2, towerSprite.getGlobalBounds().height / 2);
		towerSprite.setPosition(sf::Vector2f(xPos, yPos));
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
	rangeHelper->setOutlineColor(sf::Color::Cyan);
	rangeHelper->setOutlineThickness(3);
	rangeHelper->setOrigin(sf::Vector2f(120, 120));
	rangeHelper->setPosition(towerSprite.getPosition().x, towerSprite.getPosition().y);
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