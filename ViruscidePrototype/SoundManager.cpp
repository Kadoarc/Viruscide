//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: SoundManager.cpp
// Description	: Class implementation for the sound manager 
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#include "SoundManager.h"

SoundManager::SoundManager()
{
}

void SoundManager::loadFromFile(const std::string & name, const std::string & filename)
{
	sf::SoundBuffer buffer;
	buffer.loadFromFile(filename);

	soundBuffers[name] = buffer;
}

void SoundManager::play(const std::string & name)
{
	sounds.push_back(sf::Sound());
	sf::Sound &sound = sounds.back();
	sound.play();
}

void SoundManager::loadFiles()
{
	if (!soundBufferPew.loadFromFile("Resources/Audio/Pew.wav"))
	{
		std::cout << "Error loading Pew.wav" << std::endl;
	}

	if (!soundBufferSplat.loadFromFile("Resources/Audio/Splat.wav"))
	{
		std::cout << "Error loading Splate.wav" << std::endl;
	}

	soundPew.setBuffer(soundBufferPew);
	soundSplat.setBuffer(soundBufferSplat);
}

void SoundManager::playSplat()
{
	soundSplat.play();
}

void SoundManager::playPew()
{
	soundPew.play();
}
