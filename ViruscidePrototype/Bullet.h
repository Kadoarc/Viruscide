#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include <memory>
#include <string>
#include "Tower.h"
#include "Game.h"
#include "Enemy.h"

/*

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
	void moveBulletTowardsEnemy(sf::Vector2f enemyPosition);
	float distanceFromEnemy(sf::Vector2f enemy);
	bool bulletEnemyCollision(sf::Vector2f enemy);
	sf::Vector2f normalise(sf::Vector2f v);
	void setTarget(Enemy* target);
	bool checkCollision();

	inline bool hasTarget() { return (m_target != NULL); }
	inline bool hasHit() { return m_hit; }
	Tower* getTower() { return m_source; }



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
	void updateMovementDirections();
	sf::Vector2f unitVector;

};


*/
#include "Enemy.h"
class  Bullet
{
public:
	 Bullet(const sf::Vector2f startLoc, const sf::Vector2f dest);
	 sf::Vector2f getPos();
	 bool InstersectsWith(Enemy* enemy);
	 void update(const float dt);
	~ Bullet();
	bool targetReached();
	sf::Rect<float> getHitBox();

private:

protected:
		sf::Vector2f pos;
		 sf::Sprite sprite;
		 sf::Rect<float> hitbox;
		 float speed;
		 float size;
		 float radius;
		 float damage;
		 sf::Vector2f dir;
		 sf::Vector2f destination;

};

