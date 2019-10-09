#pragma once
#include "Utils.h"
class Player
{
public:
	// Initialise X,Y Coordinates
	float xPos;
	float yPos;
	float moveSpeed;
	int playerNumber;


	Player(float start_xPos, float start_yPos, int i_playerNumber, sf::RenderWindow& _window);
	Player();
	~Player();
	void drawPlayer(sf::RenderWindow& _window);

	void setPosition(float _x, float _y);
	sf::FloatRect getLocalBounds();
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getPosition();

	/*void movePlayer(char direction, float moveSpeed)
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
	}*/

private:
	sf::Sprite player1Sprite;
	sf::Sprite player2Sprite;
	sf::Texture player1Texture;
	sf::Texture player2Texture;

};


