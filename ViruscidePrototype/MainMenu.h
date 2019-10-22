//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: MainMenu.h
// Description	: Class definition for MainMenu
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#pragma once

#include "Utils.h"
#include "Button.h"

enum MainMenuState
{
	onMenu = 1
};

class MainMenuClass
{
public:
	MainMenuClass();
	MainMenuClass(sf::Vector2f _position, sf::Vector2f _size, std::string _texturePath, std::string _controlsPath);
	~MainMenuClass();

	void updateRenderButtons(sf::Event _event, sf::RenderWindow& _window);
	void renderControls(sf::RenderWindow& _window);
	bool getMenuOpen();

	ButtonClass PlayButton;
	ButtonClass ControlsButton;
	ButtonClass QuitButton;
	ButtonClass BackButton;

private:
	sf::RectangleShape menuBackground;
	sf::Texture texture;

	sf::RectangleShape controlsBackground;
	sf::Texture controlsTexture;
	
	MainMenuState menuState;
	
	bool menuOpen = true;
	bool controlsOpen = false;
};