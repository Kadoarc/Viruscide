#pragma once
#include <SFML/Audio.hpp>
#include "Utils.h"

#include <map>
#include <list>

class SoundManager
{
public:
	SoundManager();

	
	void loadFromFile(const std::string &name, const std::string& filename);
	void play(const std::string &name);

	void loadFiles();
	void playSplat();
	void playPew();
private:
	std::map<std::string, sf::SoundBuffer> soundBuffers;
	std::list<sf::Sound> sounds;

	sf::SoundBuffer soundBufferPew;
	sf::SoundBuffer soundBufferSplat;

	sf::Sound soundPew;
	sf::Sound soundSplat;
};

