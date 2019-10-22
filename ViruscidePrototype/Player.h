//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Player.h
// Description	: Class definition for Player
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

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
	bool m_OverlappingTower = false;
	bool m_OccupyingTower = false;

	Player(float start_xPos, float start_yPos, int i_playerNumber, sf::RenderWindow& _window);
	Player();
	~Player();
	void drawPlayer(sf::RenderWindow& _window);

	void setPosition(float _x, float _y);
	sf::FloatRect getLocalBounds();
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getPosition();

private:
	sf::Sprite player1Sprite;
	sf::Sprite player2Sprite;
	sf::Texture player1Texture;
	sf::Texture player2Texture;

};


