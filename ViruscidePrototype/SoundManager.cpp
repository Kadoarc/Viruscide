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

