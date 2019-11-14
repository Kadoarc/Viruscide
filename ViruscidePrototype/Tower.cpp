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
#include "Utils.h"

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
		shootingDirection->setRotation(rotationAngle);
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

int Tower::getCooldown()
{
	return this->currentCooldown;
}

void Tower::decreaseCooldown()
{
	this->currentCooldown--;
}

void Tower::resetCooldown()
{
	this->currentCooldown = this->baseCooldown;
}

bool Tower::isInRadius(const sf::Vector2f tarLoc)
{
	if ((tarLoc.x - pos.x)*(tarLoc.x - pos.x) + (tarLoc.y - pos.y)*(tarLoc.y - pos.y) <= range * range)
	{
		return true;
	}
	else
		return false;
}

int Tower::getTargetIndex()
{
	return targetIndex;
}

void Tower::setTarget(int index, Enemy * tar)
{
	targetIndex = index;
	target = tar;
}

sf::Vector2f Tower::getLoc() const
{
	return pos;
}

sf::Vector2f Tower::getTargetLoc() const
{
	return target->getLocation();
}

void Tower::setTarget(Enemy * enemyPtr)
{
	target = enemyPtr;
}

void Tower::RotateTower()
{
	
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
* DrawShootingIndicator: draws where a tower can shoot
* Parameters: sf::RenderWindow
* Return: sf::RectangleShape*
********************/
sf::RectangleShape* Tower::DrawShootingIndicator(sf::RenderWindow &window)
{
	shootingDirection->setPosition(this->getPosition().x,this->getPosition().y);
	shootingDirection->setSize(sf::Vector2f(50, 5));
	shootingDirection->setFillColor(sf::Color::Red);
	shootingDirection->setOutlineColor(sf::Color::Black);
	return shootingDirection;
}

sf::CircleShape* Tower::DrawRangeTowerHelper(sf::RenderWindow &window)
{
	rangeTowerHelper->setRadius(range);
	
	rangeTowerHelper->setFillColor(sf::Color::Transparent);
	rangeTowerHelper->setOutlineColor(sf::Color::Cyan);
	rangeTowerHelper->setOutlineThickness(3);
	rangeTowerHelper->setOrigin(sf::Vector2f(120, 120));
	rangeTowerHelper->setPosition(this->getPosition().x, this->getPosition().y);
	return rangeTowerHelper;
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
Tower::Tower(int xPos, int yPos, TowerType type) : damage{ 2 }, range{ 120 }, price{ 100 }, fireRate{ 10 }, level{ 1 }, elementalDamge{ 0 }
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->type = type;
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

	towerSprite.setScale(sf::Vector2f(2.0f, 2.0f));

	rangeHelper = new sf::CircleShape(range);
	shootingDirection = new sf::RectangleShape;
	rangeTowerHelper = new sf::CircleShape(range);
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
		TowerTypeNum = 0;
		damage = 7.5;
		elementalDamge = 0;
		price = 100;
		break;
	case rapid:
		TowerTypeNum = 1;
		damage = 5;
		fireRate = 500;
		elementalDamge = 0;
		price = 250;
		break;
	case ultimate:
		TowerTypeNum = 2;
		damage = 10;
		elementalDamge = 0;
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

/***********************
* getFillColor: Gets and returns the color based on tower type
* Parameters: Tower*
* Return: sf::Color
********************/
sf::Color Tower::getFillColor(Tower& originTower)
{
	// Green
	sf::Color color(0, 250, 0, 255); 

	switch (this->TowerTypeNum)
	{
		// Tower Type 1 - GREEN
	case 0:
		color.r = 0;
		color.g = 255;
		color.b = 0;
		return color;
		break;
		
	case 1: // Tower Type 2 - ORANGE
		color.r = 255;
		color.g = 129;
		color.b = 0;
		return color;
		break;
		
	case 2: // Tower Type 3 - RED
		color.r = 255;
		color.g = 43;
		color.b = 0;
		return color;
		break;
		
	default: // Default
		break;
	}
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
	towerSprite.setOrigin(_vec);
}

void Tower::setPosition(sf::Vector2f _vec)
{
	towerSprite.setPosition(_vec);
}

void Tower::draw(sf::RenderWindow & _window)
{
	_window.draw(towerSprite);
}