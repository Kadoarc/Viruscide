//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Enemy.h
// Description	: Class definition for Enemy
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "Utils.h"
#include "Grid.h"
#include <math.h>
class Bullet;


class Enemy
{
	sf::Vector2f pos;
	sf::Sprite enemySprite;
	sf::Texture enemyTexture;
	sf::Rect<float> hitbox;
	int Health;
	double Speed;
	bool IsAtCore;
	bool hasWon;

	float OTDamage;
	int value;


public:

	bool isHit;
	Grid* nextPath;
	Grid* previousPath;
	Grid* currentPath;
	sf::Rect<float> getHitbox();
	bool isAtDestination;

	Enemy(int xPos, int yPos);
	Enemy();
	~Enemy();

	bool GetIsAtCore();
	void SetIsAtCore();
	void Draw();
	void DrawEnemy(sf::RenderWindow& _window);
	void GiveDamage(Bullet* bullet);
	bool GetHasWon();
	void Update();
	int GetHP();
	int GetValue();
	int GetSpeed();

	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getLocation() const;
};

