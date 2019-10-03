#include "Player.h"


Player::Player(float start_xPos, float start_yPos, int i_playerNumber, sf::RenderWindow& _window)
{
	if (!player1Texture.loadFromFile("Resources/Images/Player1.png"))
	{
		std::cout << "Error loading player 1 png" << std::endl;
	}

	if (!player2Texture.loadFromFile("Resources/Images/Player2.png"))
	{
		std::cout << "Error loading player 2 png" << std::endl;
	}

	// Assign passed in variables
	playerNumber = i_playerNumber;
	xPos = start_xPos;
	yPos = start_yPos;

	//player1Sprite.setTexture(player1Texture);
	//player2Sprite.setTexture(player2Texture);

	player1Sprite.setOrigin(player1Sprite.getGlobalBounds().width / 2, player1Sprite.getGlobalBounds().height / 2);
	//player2Sprite.setOrigin(player2Sprite.getGlobalBounds().width / 2, player2Sprite.getGlobalBounds().height / 2);

	player1Sprite.setPosition(sf::Vector2f(xPos, yPos));
	//player2Sprite.setPosition(sf::Vector2f(xPos, yPos));

	// Draw Calls
	drawPlayer(_window);

	moveSpeed = 5;
}


Player::Player()
{

}


Player::~Player()
{
}

void Player::drawPlayer(sf::RenderWindow& _window)
{


	/*this->setPointCount(6);
	this->setPoint(0, sf::Vector2f(TILE_SIZE / 2, 25));
	this->setPoint(1, sf::Vector2f(TILE_SIZE - 30, TILE_SIZE / 4));
	this->setPoint(2, sf::Vector2f(TILE_SIZE - 30, TILE_SIZE*0.75));
	this->setPoint(3, sf::Vector2f(TILE_SIZE / 2, TILE_SIZE - 25));
	this->setPoint(4, sf::Vector2f(15, TILE_SIZE*0.75));
	this->setPoint(5, sf::Vector2f(15, TILE_SIZE / 4));
	this->setOutlineThickness(5);

	if (playerNumber == 1)
	{
		this->setOutlineColor(sf::Color::Black);
		this->setFillColor(sf::Color::Blue);
	}
	if (playerNumber == 2)
	{
		this->setOutlineColor(sf::Color::Black);
		this->setFillColor(sf::Color::Magenta);
	}*/
	if (playerNumber == 1)
	{
		player1Sprite.setTexture(player1Texture);
	}
	if (playerNumber == 2)
	{
		player1Sprite.setTexture(player2Texture);
	}
	_window.draw(player1Sprite);
}

void Player::setPosition(float _x, float _y)
{
	player1Sprite.setPosition(sf::Vector2f(_x, _y));
}

sf::FloatRect Player::getLocalBounds()
{
	return (player1Sprite.getLocalBounds());
}

sf::FloatRect Player::getGlobalBounds()
{
	return (player1Sprite.getGlobalBounds());
}
