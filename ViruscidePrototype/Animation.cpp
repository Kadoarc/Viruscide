#include "Animation.h"

Animation::Animation(sf::Texture& texture, sf::Vector2u & noOfFrames, float frameTime)
	: noOfFrames(noOfFrames), frameTime(frameTime), totalTime(0)
{
	frameSize.width = texture.getSize().x / float(noOfFrames.x);
	frameSize.height = texture.getSize().y / float(noOfFrames.y);
}


Animation::~Animation()
{
}

void Animation::update(int row, float deltaTime)
{
	currentFrame.y = row;
	totalTime += deltaTime;

	/* Assure we have a smooth, persistent, constant animation */
	if (totalTime >= frameTime)
	{
		totalTime -= frameTime;
		currentFrame.x++;

		/* Loop our animation */
		if (currentFrame.x >= noOfFrames.x)
			currentFrame.x = 0;
	}

	frameSize.left = currentFrame.x * frameSize.width;
	frameSize.top = currentFrame.y * frameSize.height;

}
