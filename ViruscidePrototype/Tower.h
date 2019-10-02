#pragma once
#include "UnMoveableEntity.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"


class Tower : public UnMoveableEntity
{
public:
	Tower();
	Tower(const sf::Vector2f& position, const sf::Vector2f& size, const float damage);
	~Tower();

	void setCenterPosition(const sf::Vector2f & newPosition);
	void setPosition(const sf::Vector2f& newPosition);

private:

	int16_t m_damage;
	sf::Vector2f m_bulletSize = Globals::defaultBulletSize;

	bool m_isAttacking = false;
	bool m_isOccupied = true;

	Entity m_mainTower;

	/* Remember to delete all bullet objects once we are done with the bulletArray */
	std::vector<Bullet> m_bulletArray;

	/* Pointer towards the intruder(enemy) */
	std::shared_ptr<Enemy> m_intruder = nullptr;
	std::shared_ptr<Player> m_player = nullptr;
	//std::shared_ptr<Enemy> m_intruder = nullptr;

	/* Fire Rate */
	sf::Time m_fireRate = sf::seconds(Globals::defaultTowerFireRate);
	sf::Clock m_updateClock;

private:
	void fireBullet();
	void setFillColor();

protected:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

public:
	bool isAttacking() const;
	float getDamage() const;
	bool isMainTowerVisible() const;

	void setBulletSize(const sf::Vector2f& newSize);
	void setDamage(const int16_t newDamage);
	void setMainTowerVisible(const bool visible);
	void setFireRate(float fireRate);
	void setIntruder(std::shared_ptr<Enemy> intruder);
	void setPlayerCollide(std::shared_ptr<Player> player);
	void update();

	void setMainColour(const sf::Color& newColor);

	sf::RectangleShape getMainHitbox() const;
};

