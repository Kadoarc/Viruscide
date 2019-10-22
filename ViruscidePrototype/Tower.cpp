//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Tower.cpp
// Description	: Class implementation for the tower
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#include "Tower.h"
#include "Bullet.h"

/***********************
* UpgradeLevel: Increments the (int) level by 1
* Parameters: NULL
* Return: NULL
********************/
void Tower::UpgradeLevel()
{
	level++;
}

/***********************
* GetLevel: Returns the (int) level of a tower
* Parameters: NULL
* Return: INT
********************/
int Tower::GetLevel()
{
	return level;
}


/***********************
* SetDamage: Sets the (float) damage of a tower based
			 on its DAMAGE divded by its LEVEL.
* Parameters: NULL
* Return: NULL
********************/
void Tower::SetDamage()
{
	damage += GetDamage() / level;
}


/***********************
* GetDamage: returns the (float) damage of a tower
* Parameters: NULL
* Return: float
********************/
float Tower::GetDamage()
{
	return damage;
}

/***********************
* SetRange: Sets the range of a tower to equal its
			own range += range divided by five
* Parameters: NULL
* Return: NULL
********************/
void Tower::SetRange()
{
	range += range / 5;
}

/***********************
* GetRange: get the range value of a tower
* Parameters: NULL
* Return: CircleShape* 
********************/
sf::CircleShape* Tower::GetRange()
{
	return rangeHelper;
}

/***********************
* SetFireRate: Sets the tower fire rate to a passed in value
* Parameters: float
* Return: NULL
********************/
void Tower::SetFireRate(float rate)
{
	fireRate = rate;
}

/***********************
* GetFireRate: get the fire rate of a tower
* Parameters: NULL
* Return: float
********************/
float Tower::GetFireRate()
{
	return fireRate;
}

/***********************
* Update: Check if a tower is built, handle tower shooting cooldowns & placement
* Parameters: NULL
* Return: NULL
********************/
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

/***********************
* GetIsReadyToFire: Check if a tower is ready to fire again
* Parameters: NULL
* Return: bool
********************/
bool Tower::GetIsReadyToFire()
{
	return isReadyToFire;
}

/***********************
* SetIsReadyToFire: Set if a tower is ready to fire or not
* Parameters: bool
* Return: NULL
********************/
void Tower::SetIsReadyToFire(bool ready)
{
	isReadyToFire = ready;
}

/***********************
* DrawPlacementAssist: draws where a tower can be placed 
* Parameters: sf::RenderWindow
* Return: sf::CircleShape*
********************/
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

/***********************
* GetName: returns the name of a tower
* Parameters: NULL
* Return: std::string
********************/
std::string Tower::GetName()
{
	return name;
}

/***********************
* Tower: Constructor for a tower
* Parameters: Int xPos, int yPos, towerType type
* Return: a tower object
********************/
Tower::Tower(int xPos, int yPos, TowerType type) : damage{ 10 }, range{ 120 }, price{ 100 }, fireRate{ 2 }, level{ 1 }, elementalDamge{ 0 }
{
	if (type == TowerType::basic)
	{
		sf::Texture Tow1Tex;
		Tow1Tex.loadFromFile("Resources/Images/Tower1.png");

		if (!Tow1Tex.loadFromFile("Tower1.png"))
		{
			std::cout << "Tower1 texture not loaded";
		}

		this->setFillColor(sf::Color(128, 128, 128));
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

/***********************
* GetElementalDamage: returns a towers elemental damage type
* Parameters: NULL
* Return: NULL
********************/
float Tower::GetElementalDamage()
{
	return elementalDamge;
}

/***********************
* SetTowerTraits: sets the damage and price of a tower based on its type
* Parameters: TowerType 
* Return: NULL
********************/
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
		price = 250;
		break;
	case ultimate:
		elementalDamge = 70;
		price = 500;
		break;
	default:
		break;
	}
}

/***********************
* GetType: Returns the type of a tower
* Parameters: NULL
* Return: TowerType
********************/
TowerType Tower::GetType()
{
	return type;
}

/***********************
* GetPrice: returns the price of a tower
* Parameters: NULL
* Return: int
********************/
int Tower::GetPrice()
{
	return price;
}

/***********************
* SetState: sets if a tower has been built
* Parameters: NULL
* Return: NULL
********************/
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

/***********************
* GetIsBuilt: Check if a tower has been built
* Parameters: NULL
* Return: bool
********************/
bool Tower::GetIsBuilt()
{
	return isBuilt;
}

/***********************
* Tower: Constructor
* Parameters: NULL
* Return: NULL
********************/
Tower::Tower()
{

}

/***********************
* ~Tower: Destructor
* Parameters: NULL
* Return: NULL
********************/
Tower::~Tower()
{
}