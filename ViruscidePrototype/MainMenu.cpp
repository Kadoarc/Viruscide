#include "MainMenu.h"
#include"Enemy.h"
#include<iostream>
#include"../Logging/Logging.h"

MainMenu::MainMenu()
{
	startButton.setText("Start");
	startButton.setSize(Globals::mainMenuButtonSize);
	startButton.setCenterPosition(sf::Vector2f(Globals::windowSize.x / 2, Globals::windowSize.y / 2 - Globals::mainMenuButtonSize.y * 4));
	startButton.setTextPosition(startButton.getPosition());

	exitButton.setText("Exit");
	exitButton.setSize(Globals::mainMenuButtonSize);
	exitButton.setCenterPosition(sf::Vector2f(startButton.getCenter().x, startButton.getCenter().y + Globals::mainMenuButtonSize.y * 1.5));
	exitButton.setTextPosition(exitButton.getPosition());

	gameName.setColour(sf::Color::Transparent);
	gameName.setText("VIRUSCIDE");
	gameName.setTextPosition(sf::Vector2f(Globals::windowSize.x / 4, Globals::rasterTop));
	gameName.setTextSize(Globals::TextSize::big);
}

MainMenu::~MainMenu()
{
}

void MainMenu::update(sf::RenderWindow & window)
{
	handleEvent(window);
}

void MainMenu::draw(sf::RenderWindow & window)
{
	window.draw(startButton);
	window.draw(exitButton);
	window.draw(gameName);

}

void MainMenu::handleEvent(sf::RenderWindow & window)
{
	sf::RectangleShape mouseRect;
	sf::Vector2f mousePositionOnWindow = mouseRect.getPosition();
	mousePositionOnWindow = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
	mouseRect.setPosition(mousePositionOnWindow);



	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		Logger logger(std::cout);

		if (startButton.isCollisonWithPoint(sf::Vector2f(sf::Mouse::getPosition(window))))
		{
			Application::getInstance()->setState(std::make_unique<LevelSelector>());

			logger.log("Start button is pressed!", Logger::Level::Info);
		}

		if (exitButton.isCollisonWithPoint(sf::Vector2f(sf::Mouse::getPosition(window))))
		{
			logger.log("Exit button is pressed!", Logger::Level::Info);

			window.close();
		}
	}
}
