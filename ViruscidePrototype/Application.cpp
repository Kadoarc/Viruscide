#include "Application.h"
#include"MainMenu.h"

#include "../Logging/Logging.h"
#include<fstream>


Application *Application::instance = nullptr;

Application::Application(const std::string& name, const int32_t x, const int32_t y)
	: window(sf::VideoMode(x, y), name)
{
	/* Point towards the application */
	if (instance == nullptr)
		instance = this;

	/* TODO: Switch our state to the Menu instead of Game */
	stateController = std::make_unique<MainMenu>();

	Logger logger(std::cout);
	logger.log("Started application", Logger::Level::Info);

	/* Run at 60fps - Actually it runs at the refresh rate of the monitor */
	window.setVerticalSyncEnabled(true);
}

Application::~Application()
{
	instance = nullptr;
}

void Application::operator()()
{
	/* Notify that we are indeed running the game now */
	isRunning = true;

	/* Run the game loop */
	gameLoop();

}

void Application::gameLoop()
{

	/* Used for restricting the Update Loop to a fixed frame rate */
	sf::Clock updateClock;
	updateClock.restart();

	/* Update */
	while (isRunning && window.isOpen())
	{
		/* Elapsed time between frames */
		sf::Time elapsedTime = updateClock.getElapsedTime();

		/* Fixed Update */
		if (elapsedTime > this->frameTime)
		{
			/* Let the state do it's updating */
			stateController->update(window);

			/* Reset our timer */
			updateClock.restart();

			/* Handling of events should be done as fast as the graphics card allows */
			handleEvent();

			/* Clear previous frame */
			window.clear(Globals::Color::backgroundColor);

			/* Draw what the state has to draw */
			stateController->draw(window);

			/* Display the new frame */
			window.display();
		}
	}
}

void Application::setState(std::unique_ptr<IStateClass> newState)
{
	this->stateController = std::move(newState);
}

Application * Application::getInstance()
{
	return instance;
}

sf::Vector2u Application::getSize()
{
	return this->window.getSize();
}

void Application::setTitle(const std::string & newTitle)
{
	this->window.setTitle(newTitle);
}

void Application::setSize(const int32_t x, const int32_t y)
{
	this->window.setSize(sf::Vector2u(x, y));
}

void Application::handleEvent()
{
	while (window.pollEvent(this->event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
