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
	bool isHit;
	float OTDamage;
	int value;


public:

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

