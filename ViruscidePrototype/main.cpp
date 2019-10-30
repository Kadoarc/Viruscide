//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Main.cpp
// Description	: Implementation of the Main file
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: [lorenzo.zem8065@mediadesign.school.nz], [Jeremy.bun8227.@mediadesign.school.nz], [Daniel.joo8189@mediadesign.school.nz]
//

//__________________
//
//	Dependencies
//__________________

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//#include <vld.h>

//__________________
//
//	Local Includes
//__________________


#include "Utils.h"
#include "Game.h"
#include "Grid.h"
#include "Tower.h"
#include "Level.h"
#include "Player.h"
#include "Button.h"
#include "Label.h"
#include "MainMenu.h"
#include "GameOver.h"

//__________________
//
//	Global Variables
//__________________

Player player;

/***********************
* main: main program function
* Parameters: NULL
* Return: NULL
********************/
int main()
{
	sf::RenderWindow window(sf::VideoMode(FullHdresolution::x, FullHdresolution::y), "Viruscide");;
	Level gameLevel;
	gameLevel.CreateLevel();
	sf::Event event;
	Game game(gameLevel.GetMap(), window, event);
	Flags eventFlag = Flags::gameInProgress;
	sf::Clock clock;
	sf::Time collector = sf::Time::Zero;
	float frameTime = 1.0f / 60.0f;

	MainMenuClass mainMenu(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), sf::Vector2f(1920.0, 1080.0f),
		"Resources/Images/ViruscideMenuScreen.png", "Resources/Images/ViruscideControlScreen.png");
	GameOverScreenClass gameOver;

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

			// Check if E has been pressed once
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::E)
				{
					std::cout << "E key Pressed\n";
					game.EPressed();
				}
			}

			// Check if NUMPAD 0 has been pressed once
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Numpad0)
				{
					std::cout << "Num0 key Pressed\n";
					game.Numpad0Pressed();
				}
			}

			// Check if W has been pressed once
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					std::cout << "W key Pressed\n";
					game.WPressed();
				}
			}

			// Check if Up has been pressed once
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					std::cout << "Up key Pressed\n";
					game.UpPressed();
				}
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				//ignore MouseButtonRealease
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

		if (mainMenu.getMenuOpen())
		{
			window.clear();
			mainMenu.updateRenderButtons(event, window);
			window.display();
			clock.restart();
			
		}
		else
		{
			while (collector > TIME_PASED)
			{
				if (game.GetIsGameOver())
				{
					collector -= TIME_PASED;
					window.clear(sf::Color::Black);
					//game.RenderGameOver(window);
					gameOver.render(window);
					window.display();
				}
				else
				{
					collector -= TIME_PASED;
					window.clear(sf::Color::Black);
					game.GameCycle(window, eventFlag, event, clock);
					window.display();
				}
			}

			collector += clock.restart();
		}
	}

	return(0);
}