#include "LevelSelector.h"


LevelSelector::LevelSelector()
{
	m_instructions.setSize(Globals::levelSelectorButtonSize);
	m_instructions.setColour(sf::Color::Transparent);
	m_instructions.setPosition(sf::Vector2f(Globals::windowSize.x / 4, Globals::rasterTop));
	m_instructions.setTextPosition(m_instructions.getPosition());
	m_instructions.setText("Select a level");
	m_instructions.setTextSize(Globals::TextSize::big);

	newButton.setSize(Globals::levelSelectorButtonSize);
	newButton.setCenterPosition(sf::Vector2f(((Globals::windowSize.x / 2) - Globals::levelSelectorButtonSize.x), (Globals::windowSize.y / 2) - 1 * Globals::levelSelectorButtonSize.y));
	newButton.setTextPosition(newButton.getPosition());
	newButton.setText(" LEVEL \n 1");
	newButton.setTextSize(Globals::TextSize::normal);
	m_levelButtonsArray.push_back(newButton);


	newButton.setCenterPosition(sf::Vector2f(((Globals::windowSize.x / 2) + Globals::levelSelectorButtonSize.x), (Globals::windowSize.y / 2) - 1 * Globals::levelSelectorButtonSize.y));
	newButton.setTextPosition(newButton.getPosition());
	newButton.setText(" Level \n 2");
	newButton.setTextSize(Globals::TextSize::normal);
	m_levelButtonsArray.push_back(newButton);

	newButton.setCenterPosition(sf::Vector2f(((Globals::windowSize.x / 2) - Globals::levelSelectorButtonSize.x), (Globals::windowSize.y / 2) + 1 * Globals::levelSelectorButtonSize.y));
	newButton.setTextPosition(newButton.getPosition());
	newButton.setText(" Level \n 3");
	newButton.setTextSize(Globals::TextSize::normal);
	m_levelButtonsArray.push_back(newButton);

	newButton.setCenterPosition(sf::Vector2f(((Globals::windowSize.x / 2) + Globals::levelSelectorButtonSize.x), (Globals::windowSize.y / 2) + 1 * Globals::levelSelectorButtonSize.y));
	newButton.setTextPosition(newButton.getPosition());
	newButton.setText(" Level \n 4");
	newButton.setTextSize(Globals::TextSize::normal);
	m_levelButtonsArray.push_back(newButton);

}


LevelSelector::~LevelSelector()
{
}

void LevelSelector::choseLevel(const sf::Vector2f & mousePosition)
{
	for (int i = 0; i < m_levelButtonsArray.size(); i++)
	{
		if (m_levelButtonsArray[i].isCollisonWithPoint(mousePosition))
		{
			Application::getInstance()->setState(std::make_unique<Game>("..\\Levels\\" + std::to_string(i + 1)));
		}
	}
}

void LevelSelector::update(sf::RenderWindow & window)
{
	handleEvent(window);
}

void LevelSelector::draw(sf::RenderWindow & window)
{
	window.draw(m_instructions);
	for (Button &button : m_levelButtonsArray)
	{
		window.draw(button);
	}
}

void LevelSelector::handleEvent(sf::RenderWindow & window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		choseLevel((sf::Vector2f)sf::Mouse::getPosition(window));
}
