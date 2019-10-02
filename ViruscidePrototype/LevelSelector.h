#pragma once
#include "IStateClass.h"
#include "Game.h"
#include "Button.h"
#include "Application.h"
class LevelSelector :
	public IStateClass
{
public:
	LevelSelector();
	~LevelSelector();
private:
	Button m_instructions;
	Button newButton;
	std::vector<Button> m_levelButtonsArray;
	void choseLevel(const sf::Vector2f& mousePosition);



public:
	void update(sf::RenderWindow &window) override;
	void draw(sf::RenderWindow &window) override;
	void handleEvent(sf::RenderWindow &window) override;





};

