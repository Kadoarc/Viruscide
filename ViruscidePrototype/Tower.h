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


class Tower
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

	sf::Sprite towerSprite;
	sf::Texture towerTexture;

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

	//new sprite stuff
	sf::Color getFillColor();
	sf::FloatRect getGlobalBounds();
	sf::FloatRect getLocalBounds();
	sf::Vector2f getPosition();

	void setOrigin(sf::Vector2f _vec);
	void setPosition(sf::Vector2f _vec);

	void draw(sf::RenderWindow& _window);
};
