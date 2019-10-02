#pragma once
#include "SFML/Graphics.hpp"

class Animation
{
public:
	Animation(sf::Texture& texture, sf::Vector2u& noOfFrames, float frameTime);

	~Animation();

	void update(int row, float deltaTime);

public:
	sf::IntRect frameSize;

private:
	sf::Vector2u noOfFrames;
	sf::Vector2u currentFrame;

	float frameTime;
	float totalTime;
};

