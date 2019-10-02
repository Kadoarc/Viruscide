#include "MoveableEntity.h"
#include <iostream>
using namespace std;


#pragma once
class Player2 : public MoveableEntity
{

public:
	float xPos;
	float yPos;
	Player2(const sf::Vector2f& position, const sf::Vector2f& size, const float speed, const sf::Vector2i& movementDirection);
	Player2();
	~Player2();
	void drawPlayer();
	void movePlayer();
	void moveNorth();
	void moveEast();
	void moveWest();
	void moveSouth();
private:
	sf::Color m_startingColor;
	bool m_OverlappingTower = false;
	Entity m_player2;


public:
	bool OverlapTower() const;
	void setOverlapTower(const bool isOverlapping);
	sf::RectangleShape getMainHitbox() const;
};

