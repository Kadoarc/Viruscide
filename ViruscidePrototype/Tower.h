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
	float damage;
	float fireRate;
	float range;
	bool isReadyToFire = true;
	bool isSelected = false;
	bool isBuilt = false;
	bool isOccupied = false;
	int Price;
	TowerType type;
	sf::Clock clock;
	sf::Time collector = sf::Time::Zero;


	void SetRange();
	void SetTowerTraits(TowerType type);
public:

	Tower();
	Tower(int xPos, int yPos, TowerType type);
	~Tower();
	TowerType GetType();
	std::string GetName();
	sf::CircleShape* GetRange();
	sf::CircleShape* DrawPlacementAssist(sf::RenderWindow &window);
	int GetPrice();
	void SetState();
	bool GetIsBuilt();
	void Update(sf::RenderWindow &window);

private:
	sf::Texture towerTexture;
	sf::Sprite  towerSprite;
};

