#pragma once
#include "Utils.h"
class Player : public sf::ConvexShape
{
public:
	float xPos = 1920/2;
	float yPos = 1080/2;

	Player(float xPos, float yPos);
	Player();
	~Player();
	void drawPlayer();

	void movePlayer(char direction, float moveSpeed)
	{
		if (direction == 'u')
		{
			move(0, -moveSpeed);
		}
		else if (direction == 'd') {
			move(0, moveSpeed);
		}
		else if (direction == 'l') {
			move(-moveSpeed, 0);
		}
		else if (direction == 'r') {
			move(moveSpeed, 0);
		}
	}

};


