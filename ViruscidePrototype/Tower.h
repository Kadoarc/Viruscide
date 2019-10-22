#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Utils.h"
#include <string>
#include <iostream>
#include "TextureManager.h"


class Tower : public sf::ConvexShape
{
	std::string name = "Basic Tower";
	sf::CircleShape *rangeHelper;
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
	//virtual void ReadyToFire();
	int getCooldown();
	void decreaseCooldown();
	void resetCooldown();
	bool isinRadius(const sf::Vector2f tarLoc);
	sf::Vector2f getLoc() const;
	sf::Vector2f getTargetLoc() const;
	void setTarget(Enemy* enemyPtr);
	int getTargetIndex();
	void setTarget(int index, Enemy* tar);
private:
	int currentCooldown;
	int baseCooldown;

protected:
	sf::Vector2f pos;
	float cooldown;
	float lastShoot = 0.0f;
	float range;
	Enemy* target = nullptr;
	float timeElapsed = 0.0f;
	int targetIndex = -1;

};
