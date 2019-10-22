//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Bullet.h
// Description	: Class definition for Bullet
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include <memory>
#include <string>
#include "Tower.h"
#include "Game.h"
#include "Enemy.h"




using std::string;
using std::weak_ptr;
using std::shared_ptr;

class Bullet : public sf::CircleShape
{
	float damage;
	TowerType element;
	float elementalDamage;
	Enemy* destination;
	Enemy* m_target;
	bool missed;
	bool destroyed = false;
	unsigned int p_maxLifeTime;
	unsigned int p_currentLifeTime;

public:

	void Update();
	Bullet(Tower* t, Enemy* destination);
	Bullet(float damage, std::string element, float elementalDamage);
	~Bullet();
	Bullet(const sf::Vector2f& position, const Enemy& destination, const float speed);
	void SetDamage(float damage);
	float GetDamage();
	void SetElement(TowerType type);
	TowerType GetElement();
	void SetElementalDamage(float damage);
	float GetElementalDamage();
	bool CollisionDetect();


private:
	Enemy m_destination;
	Tower* m_source;
	float m_speed;
	bool m_hit;
	bool m_targetdead;
	sf::Texture projectileTexture;
	sf::CircleShape bulletShape;
	sf::Vector2f bulletPosition;
	sf::Vector2f bulletCentre;
	float speed = 8;
	weak_ptr<Enemy> target_ptr;
	
	sf::Vector2f unitVector;

};



