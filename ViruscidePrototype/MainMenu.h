#pragma once
#include "IStateClass.h"
#include"Button.h"
#include"Enemy.h"
#include "Application.h"
#include "Game.h"

class MainMenu : public IStateClass
{
public:
	MainMenu();
	~MainMenu();

private:
	Button startButton, levelEditorButton, exitButton;
	Button gameName;

public:

	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void handleEvent(sf::RenderWindow &window);
};

