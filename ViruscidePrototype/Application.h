#pragma once
#include <SFML\Graphics.hpp>
#include "IStateClass.h"
#include "Game.h"
#include "LevelSelector.h"

class Application
{
public:
	Application(const std::string& title, const int32_t x, const int32_t y);
	~Application();

	/* The operator starts the game loop basically */
	void operator () ();

private:

	/* Can only have one instance of the application at the same time */
	static Application* instance;


	std::unique_ptr<IStateClass> stateController;

	sf::RenderWindow window;
	sf::Event event;

	bool isRunning;

	/* Time to render a frame - Unties the game from the graphics card */
	const sf::Time frameTime = sf::seconds(Globals::frameRate);

public:
	/* Event handling */
	void handleEvent();
	void gameLoop();
	void setState(std::unique_ptr<IStateClass> newState);

public:

	/* Getters */
	static Application* getInstance();
	sf::Vector2u getSize();

	/* Setters */
	void setTitle(const std::string& newTitle);
	void setSize(const int32_t x, const int32_t y);

};


