#pragma once
#include "Utils.h"
class Player : public sf::ConvexShape
{
public:
	// Initialise X,Y Coordinates
	float xPos;
	float yPos;
	int playerNumber;


	Player(float start_xPos, float start_yPos, int i_playerNumber);
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


