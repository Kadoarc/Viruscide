//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Button.cpp
// Description	: Mouse handling for buttons
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#include "Button.h"

ButtonClass::ButtonClass()
{
	pressed = false;
}

ButtonClass::ButtonClass(sf::Vector2f _position, sf::Vector2f _size , std::string _textureNormalPath, 
	std::string _textureHoverPath, std::string _textureClickedPath)
{
	pressed = false;

	//set position var
	position = _position;

	//set button state
	buttonState = normalButton;

	//load button texture
	loadTextures(_textureNormalPath, _textureHoverPath, _textureClickedPath);

	button = sf::RectangleShape(_size);
	button.setTexture(&textureNormal);
	button.setOrigin(button.getGlobalBounds().width / 2, button.getGlobalBounds().height / 2);
	button.setPosition(position);
}

ButtonClass::~ButtonClass()
{
}

void ButtonClass::update(sf::Event _event, sf::RenderWindow & _window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(_window);

	bool mouseOnButton = mousePosition.x >= button.getPosition().x - button.getGlobalBounds().width / 2
		&& mousePosition.x <= button.getPosition().x + button.getGlobalBounds().width / 2
		&& mousePosition.y >= button.getPosition().y - button.getGlobalBounds().height / 2
		&& mousePosition.y <= button.getPosition().y + button.getGlobalBounds().height / 2;

	if (_event.type == sf::Event::MouseMoved)
	{
		if (mouseOnButton)
		{
			buttonState = hoverButton;
		}
		else
		{
			buttonState = normalButton;
		}
	}

	if (_event.type == sf::Event::MouseButtonPressed)
	{
		
			switch (_event.mouseButton.button)
			{
			case sf::Mouse::Left:
			{
				if (mouseOnButton /*&& !pressed*/)
				{
					buttonState = clickedButton;
				}
				else if (!mouseOnButton)
				{
					buttonState = normalButton;
				}
			}
			break;
			}

			/*if (pressed == false && mouseOnButton)
			{
				pressed = true;
			}*/
		
	}	

	if (_event.type == sf::Event::MouseButtonReleased)
	{
		//if (pressed == true && mouseOnButton)
		//{
		//	pressed = false;
		//}
			switch (_event.mouseButton.button)
			{
			case sf::Mouse::Left:
			{
				if (mouseOnButton)
				{
					buttonState = hoverButton;
				}
				else
				{
					buttonState = normalButton;
				}
			}
			break;
			}
		
	}

	switch (buttonState)
	{
	case normalButton:
	{
		button.setTexture(&textureNormal);
	}
	break;
	case hoverButton:
	{
		button.setTexture(&textureHover);
	}
	break;
	case clickedButton:
	{
		button.setTexture(&textureClicked);
	}
	break;
	}
}

void ButtonClass::render(sf::RenderWindow & _window)
{
	_window.draw(button);
}

void ButtonClass::loadTextures(std::string _textureNormalPath, std::string _textureHoverPath, std::string _textureClickedPath)
{
	if (!textureNormal.loadFromFile(_textureNormalPath))
	{
		std::cout << "Error loading normal button texture" << std::endl;
	}

	if (!textureHover.loadFromFile(_textureHoverPath))
	{
		std::cout << "Error loading Hover button texture" << std::endl;
	}

	if (!textureClicked.loadFromFile(_textureClickedPath))
	{
		std::cout << "Error loading Clicked button texture" << std::endl;
	}
}

void ButtonClass::setPosition(sf::Vector2f _position)
{
	position = _position;
}

void ButtonClass::setTextureNormal(sf::Color _normalTexture)
{

	button.setTexture(&textureNormal);
}

void ButtonClass::setTextureHover(sf::Color _hoverTexture)
{

	button.setTexture(&textureHover);
}

void ButtonClass::setTextureClicked(sf::Color _clickedTexture)
{

	button.setTexture(&textureClicked);
}

sf::Vector2f ButtonClass::getPosition()
{
	return (position);
}

sf::Vector2f ButtonClass::getDimensions()
{
	return sf::Vector2f();
}

ButtonStates ButtonClass::getButtonState()
{
	return (buttonState);
}
