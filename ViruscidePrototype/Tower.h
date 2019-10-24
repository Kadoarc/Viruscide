//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Tower.h
// Description	: Class definition for Tower
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Utils.h"
#include <string>
#include <iostream>
#include "TextureManager.h"
#include "Enemy.h"


class Tower : public sf::ConvexShape
{
	std::string name = "Basic Tower";
	sf::CircleShape* rangeHelper;
	sf::RectangleShape* shootingDirection;
	int level;
	float damage;
	float elementalDamge;
	float range;
	float fireRate;
	bool isReadyToFire = true;
	bool isSelected = false;
	bool isBuilt = false;

	int price;
	TowerType type;
	sf::Clock clock;
	sf::Time collector = sf::Time::Zero;
	void SetDamage();
	void SetRange();
	void SetFireRate(float rate);
	void SetTowerTraits(TowerType type);
	TextureManager texMan;

public:
	sf::CircleShape* GetRange();
	TowerType GetType();
	Tower();
	Tower(int xPos, int yPos, TowerType type);
	~Tower();
	std::string GetName();
	sf::CircleShape* DrawPlacementAssist(sf::RenderWindow &window);
	sf::RectangleShape* DrawShootingIndicator(sf::RenderWindow &window);
	bool GetIsReadyToFire();
	void SetIsReadyToFire(bool ready);
	int GetPrice();
	void UpgradeLevel();
	int GetLevel();
	float GetElementalDamage();
	float GetDamage();
	float GetFireRate();
	void SetState();
	bool GetIsBuilt();
	void Update(sf::RenderWindow &window);
	bool isOccupiedP1 = false;
	bool isOccupiedP2 = false;
	bool autoShoot = true;
	int xPos;
	int yPos;
	//virtual void ReadyToFire();
	int getCooldown();
	void decreaseCooldown();
	void resetCooldown();
	bool isInRadius(const sf::Vector2f tarLoc);
	int getTargetIndex();
	void setTarget(int index, Enemy * tar);
	sf::Vector2f getLoc() const;
	sf::Vector2f getTargetLoc() const;
	void setTarget(Enemy *enemyPtr);
	void RotateTower();
	float rotationAngle;

private:
	int currentCooldown;
	int baseCooldown;

protected:
	Enemy* target = nullptr;
	int targetIndex = -1;
	sf::Vector2f pos;
};
