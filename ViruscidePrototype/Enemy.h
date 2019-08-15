#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "Utils.h"
#include "Grid.h"
#include <math.h>


class Enemy : public sf::ConvexShape
{
	int Health;
	double Speed;
	bool IsAtCore;
	bool hasWon;
	bool isHit;
	void DrawEnemy();
	float OTDamage;
	int value;


public:
	Grid* nextPath;
	Grid* previousPath;
	Grid* currentPath;
	bool isAtDestination;
	Enemy(int xPos, int yPos);
	Enemy();
	~Enemy();
	bool GetIsAtCore();
	void SetIsAtCore();
	void Draw();
	bool GetHasWon();
	void Update();
	int GetHP();
	int GetValue();
	int GetSpeed();
};

