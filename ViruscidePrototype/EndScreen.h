#pragma once
#include "IStateClass.h"
#include "Button.h"
#include "Application.h"
#include "MainMenu.h"

class EndScreen : public IStateClass
{
public:
	EndScreen(const bool condition);
	~EndScreen();

public:
	void update(sf::RenderWindow &window) override;
	void draw(sf::RenderWindow &window) override;
	void handleEvent(sf::RenderWindow &window) override;

private:

	Button m_endButton;

	enum condition
	{
		Loss,
		Win
	};

};

