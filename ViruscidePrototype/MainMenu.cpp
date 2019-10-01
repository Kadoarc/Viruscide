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

	BackButton = ButtonClass(sf::Vector2f(SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 306.0f), sf::Vector2f(425.0f, 133.0f), std::string("Resources/Images/ViruscideBackButton.png"),
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

	if (PlayButton.getButtonState() == clickedButton)
	{
		menuOpen = false;
	}
	if (ControlsButton.getButtonState() == clickedButton)
	{
		controlsOpen = true;
	}
	if (QuitButton.getButtonState() == clickedButton)
	{
		_window.close();
	}
	if (BackButton.getButtonState() == clickedButton)
	{
		controlsOpen = false;
	}
	
	_window.draw(menuBackground);
	
	PlayButton.render(_window);
	ControlsButton.render(_window);
	QuitButton.render(_window);

	if (controlsOpen)
	{
		renderControls(_window);
		BackButton.render(_window);
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
