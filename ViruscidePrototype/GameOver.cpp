#include "GameOver.h"

GameOverScreenClass::GameOverScreenClass()
{
	if (!backgroundTexture.loadFromFile("Resources/Images/ViruscidePlainBackground.png"))
	{
		std::cout << "error loading game over screen " << std::endl;
	}
	
	backgroundImage = sf::RectangleShape(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	backgroundImage.setOrigin(backgroundImage.getGlobalBounds().width / 2, backgroundImage.getGlobalBounds().height / 2);
	backgroundImage.setTexture(&backgroundTexture);
	backgroundImage.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	text = LabelClass(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), 50.0f, "GAME OVER", sf::Color::White, "Resources/Fonts/galaxymonkey.ttf");
}

GameOverScreenClass::~GameOverScreenClass()
{
}

void GameOverScreenClass::render(sf::RenderWindow & _window)
{
	text.render(_window);
	_window.draw(backgroundImage);
}
