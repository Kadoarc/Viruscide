//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: MainMenu.cpp
// Description	: Class for the Menu system
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#include "MainMenu.h"

MainMenuClass::MainMenuClass()
{
}

MainMenuClass::MainMenuClass(sf::Vector2f _position, sf::Vector2f _size, std::string _texturePath, std::string _controlScreenPath)
{
	if (!texture.loadFromFile(_texturePath))
	{
		std::cout << "Error Loading Main Menu Background Image" << std::endl;
	}

	if (!controlsTexture.loadFromFile(_controlScreenPath))
	{
		std::cout << "Error Loading Main Menu Background Image" << std::endl;
	}

	menuBackground = sf::RectangleShape(_size);
	menuBackground.setTexture(&texture);
	menuBackground.setOrigin(menuBackground.getGlobalBounds().width / 2, menuBackground.getGlobalBounds().height / 2);
	menuBackground.setPosition(_position);

	controlsBackground = sf::RectangleShape(_size);
	controlsBackground.setTexture(&controlsTexture);
	controlsBackground.setOrigin(controlsBackground.getGlobalBounds().width / 2, controlsBackground.getGlobalBounds().height / 2);
	controlsBackground.setPosition(_position);

	PlayButton = ButtonClass(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), sf::Vector2f(425.0f, 133.0f), std::string("Resources/Images/ViruscideMenuPlayButton.png"),
		std::string("Resources/Images/ViruscideMenuPlayButtonHover.png"), std::string("Resources/Images/ViruscideMenuPlayButtonClicked.png"));
	ControlsButton = ButtonClass(sf::Vector2f(SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 153.0f), sf::Vector2f(425.0f, 133.0f), std::string("Resources/Images/ViruscideControlsButtons.png"),
		std::string("Resources/Images/ViruscideControlsButtonsHover.png"), std::string("Resources/Images/ViruscideControlsButtonsClicked.png"));
	QuitButton = ButtonClass(sf::Vector2f(SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 306.0f), sf::Vector2f(425.0f, 133.0f), std::string("Resources/Images/ViruscideMenuQuitButton.png"),
		std::string("Resources/Images/ViruscideMenuQuitButtonHover.png"), std::string("Resources/Images/ViruscideMenuQuitButtonClicked.png"));

	BackButton = ButtonClass(sf::Vector2f((SCREEN_WIDTH / 2) - 700.0f, (SCREEN_HEIGHT / 2) + 450.0f), sf::Vector2f(425.0f, 133.0f), std::string("Resources/Images/ViruscideBackButton.png"),
		std::string("Resources/Images/ViruscideBackButtonHover.png"), std::string("Resources/Images/ViruscideBackButtonClicked.png"));
}

MainMenuClass::~MainMenuClass()
{
}

void MainMenuClass::updateRenderButtons(sf::Event _event, sf::RenderWindow & _window)
{
	PlayButton.update(_event, _window);
	ControlsButton.update(_event, _window);
	QuitButton.update(_event, _window);

	BackButton.update(_event, _window);

	if (PlayButton.getButtonState() == clickedButton && onControls == false)
	{
		menuOpen = false;
	}
	if (ControlsButton.getButtonState() == clickedButton && onControls == false)
	{
		controlsOpen = true;
		onControls = true;
	}
	if (QuitButton.getButtonState() == clickedButton && onControls == false)
	{
		_window.close();
	}
	if (BackButton.getButtonState() == clickedButton)
	{
		controlsOpen = false;
		onControls = false;
	}
	
	_window.draw(menuBackground);
	

	if (controlsOpen)
	{
		renderControls(_window);
		BackButton.render(_window);
	}
	else
	{
		PlayButton.render(_window);
		ControlsButton.render(_window);
		QuitButton.render(_window);
	}
}

void MainMenuClass::renderControls(sf::RenderWindow& _window)
{
	_window.draw(controlsBackground);
}

bool MainMenuClass::getMenuOpen()
{
	return (menuOpen);
}
