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

	if (!soundBufferEnterTower.loadFromFile("Resources/Audio/EnterTower.wav"))
	{
		std::cout << "Error loading Enter Tower.wav" << std::endl;
	}
	if (!soundBufferBackground.loadFromFile("Resources/Audio/BackgroundMusic.wav"))
	{
		std::cout << "Error loading backgroundmusic.wav" << std::endl;
	}
	if (!soundBufferConstructTower.loadFromFile("Resources/Audio/BuildTower.wav"))
	{
		std::cout << "Error loading BuildTower.wav" << std::endl;
	}
	soundPew.setBuffer(soundBufferPew);
	soundSplat.setBuffer(soundBufferSplat);
	soundEnter.setBuffer(soundBufferEnterTower);
	soundConsTower.setBuffer(soundBufferConstructTower);
	soundBackG.setBuffer(soundBufferBackground);
}

void SoundManager::playSplat()
{
	soundSplat.play();
}

void SoundManager::playPew()
{
	soundPew.play();
}

void SoundManager::playEnterTower()
{
	soundEnter.play();
}

void SoundManager::playBackgroundMusic()
{
	soundBackG.play();
}

void SoundManager::playConstructTower()
{
	soundConsTower.play();
}


