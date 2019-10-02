#include "EndScreen.h"

EndScreen::EndScreen(const bool condition)
{
	if (condition == condition::Loss)
		this->m_endButton.setText(Globals::Strings::lostGame + Globals::Strings::backToMenu);
	else if (condition == condition::Win)
		this->m_endButton.setText(Globals::Strings::wonGame + Globals::Strings::backToMenu);

	m_endButton.setSize(Globals::windowSize);
	m_endButton.setPosition({ 0,0 });
	m_endButton.setTextSize(100);

}

EndScreen::~EndScreen()
{
}

void EndScreen::update(sf::RenderWindow & window)
{
	handleEvent(window);
}

void EndScreen::draw(sf::RenderWindow & window)
{
	window.draw(this->m_endButton);
}

void EndScreen::handleEvent(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		/* If any key was pressed, go back to the main menu */
		if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::KeyPressed)
			Application::getInstance()->setState(std::make_unique<MainMenu>());
	}
}
