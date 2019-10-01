#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Utils.h"
#include "Game.h"
#include "Grid.h"
#include "Tower.h"
#include "Level.h"
#include "Player.h"

#include "Button.h"
#include "Label.h"

Player player;



int main()
{
	sf::RenderWindow window(sf::VideoMode(FullHdresolution::x, FullHdresolution::y), "Viruscide");;
	Level gameLevel;
	gameLevel.CreateLevel();
	Game game(gameLevel.GetMap());
	sf::Event event;
	Flags eventFlag = Flags::gameInProgress;
	sf::Clock clock;
	sf::Time collector = sf::Time::Zero;
	float frameTime = 1.0f / 60.0f;

	/*
	ButtonClass testButton(sf::Vector2f(1280.0f, 720.0f), sf::Vector2f(425.0f, 133.0f), std::string("Resources/Images/ViruscideMenuPlayButton.png"),
			std::string("Resources/Images/ViruscideMenuPlayButtonHover.png"), std::string("Resources/Images/ViruscideMenuPlayButtonClicked.png"));;
	LabelClass testlabel(sf::Vector2f(500.0f, 500.0f), 42, "Test Label", sf::Text::Style::Regular, sf::Color::Red, "Resources/Fonts/galaxymonkey.ttf");*/

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (game.GetIsGameOver())
			{
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Space)
					{
						game.RestartGame();
					}

				
				}
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				//igonre MouseButtonRealease
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//Case: Player Clicker on the GUI
					if (sf::Mouse::getPosition(window).x < game.map[0]->getPosition().x)
					{
						if (game.Construction(sf::Mouse::getPosition(window)) && eventFlag != Flags::towerUnderConstruction)
						{
							game.ActivateTowerPlacement();
							eventFlag = Flags::towerUnderConstruction;
						}
					}
					//Case: Player clicked on the map
					else
					{
						if (eventFlag == Flags::towerUnderConstruction)
						{
							if (game.CheckPlacement(sf::Mouse::getPosition(window)))
							{
								eventFlag = Flags::gameInProgress;
							}

						}
						
					}


				}

				if (event.mouseButton.button == sf::Mouse::Right && eventFlag == Flags::towerUnderConstruction)
				{
					game.CancelTower();
					eventFlag = Flags::gameInProgress;
				}
			}

		}

		while (collector > TIME_PASED)
		{
			if (game.GetIsGameOver())
			{
				collector -= TIME_PASED;
				window.clear(sf::Color::Black);
				game.RenderGameOver(window);
				window.display();
			}
			else
			{
				collector -= TIME_PASED;
				window.clear(sf::Color::Black);
				game.GameCycle(window, eventFlag);
				//testButton.update(event, window);
				//testButton.render(window);
				//testlabel.render(window);
				window.display();

				/*if (testButton.getButtonState() == clickedButton)
				{
					window.close();
				}*/
			}

		}

		collector += clock.restart();
	}



	return(0);
}