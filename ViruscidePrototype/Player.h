#pragma once
#include "Utils.h"
class Player
{
public:
	Player();
	~Player();
	sf::CircleShape shape;

	void movePlayer(char direction, float moveSpeed)
	{
		if (direction == 'u')
		{
			shape.move(0, -moveSpeed);
		}
		else if (direction == 'd') {
			shape.move(0, moveSpeed);
		}
		else if (direction == 'l') {
			shape.move(-moveSpeed, 0);
		}
		else if (direction == 'r') {
			shape.move(moveSpeed, 0);
		}
	}

};


