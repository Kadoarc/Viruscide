//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Button.h
// Description	: Class definition for Button
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#pragma once

#include "Utils.h"

enum ButtonStates
{
	normalButton = 0,
	hoverButton = 1,
	clickedButton = 2
};

class ButtonClass
{
public:
	ButtonClass();
	ButtonClass(sf::Vector2f _position, sf::Vector2f _size, std::string _textureNormalPath, std::string _textureHoverPath, std::string _textureClickedPath);
	~ButtonClass();

	void update(sf::Event _event, sf::RenderWindow& _window);
	void render(sf::RenderWindow& _window);

	void loadTextures(std::string _textureNormalPath, std::string _textureHoverPath, std::string _textureClickedPath);

	void setPosition(sf::Vector2f _position);
	void setTextureNormal(sf::Color _normalTexture);
	void setTextureHover(sf::Color _hoverTexture);
	void setTextureClicked(sf::Color _clickedTexture);

	sf::Vector2f getPosition();
	sf::Vector2f getDimensions();

	ButtonStates getButtonState();

private:
	sf::RectangleShape button;

	sf::Texture textureNormal;
	sf::Texture textureHover;
	sf::Texture textureClicked;

	sf::Vector2f position;

	ButtonStates buttonState;
};