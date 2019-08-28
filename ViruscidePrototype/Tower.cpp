#include "Tower.h"




void Tower::SetRange()
{
	range += range / 5;
}


void Tower::SetTowerTraits(TowerType type)
{

	switch (type)
	{
	case normal:
		
		Price = 200;
		break;

	case rapid:
		Price = 300;
		break;

	case ultimate:
		Price = 400;
		break;

	default:
		break;
	}
}
Tower::Tower()
{
}

Tower::Tower(int xPos, int yPos, TowerType type) :damage{ 10 }, range{ 120 }, Price{ 100 }, fireRate{ 2 }
{
	this->setPointCount(3);
	this->setPoint(0, sf::Vector2f(TILE_SIZE / 2, TILE_SIZE / 4));
	this->setPoint(1, sf::Vector2f(TILE_SIZE*0.75, TILE_SIZE*0.75));
	this->setPoint(2, sf::Vector2f(TILE_SIZE*0.25, TILE_SIZE*0.75));
	this->setOrigin(sf::Vector2f(TILE_SIZE / 2, TILE_SIZE / 2));
	this->setPosition(sf::Vector2f(xPos, yPos));

	if (type == TowerType::basic)
	{
		this->setFillColor(sf::Color(128, 128, 128));
	}

	else if (type == TowerType::rapid)
	{
		this->setFillColor(sf::Color(128, 128, 0));
	}
	else if (type == TowerType::ultimate)
	{
		this->setFillColor(sf::Color(0, 128, 128));
	}
	
	rangeHelper = new sf::CircleShape(range);
	SetTowerTraits(type);
}


Tower::~Tower()
{
}

TowerType Tower::GetType()
{
	return type;
}

std::string Tower::GetName()
{
	return name;
}

sf::CircleShape * Tower::GetRange()
{
	return rangeHelper;
}

sf::CircleShape * Tower::DrawPlacementAssist(sf::RenderWindow & window)
{
	rangeHelper->setRadius(range);
	rangeHelper->setFillColor(sf::Color::Transparent);
	rangeHelper->setOutlineColor(this->getFillColor());
	rangeHelper->setOutlineThickness(3);
	rangeHelper->setOrigin(sf::Vector2f(120, 120));
	rangeHelper->setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	return rangeHelper;
}


int Tower::GetPrice()
{
	return Price;
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

void Tower::Update(sf::RenderWindow & window)
{
	if (isBuilt)
	{
		if (collector < sf::seconds(1))
		{
			collector += TIME_PASED;
		}
		else
		{
			collector = clock.restart();
	
		}

	}
	else
	{
		this->setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	}

}
