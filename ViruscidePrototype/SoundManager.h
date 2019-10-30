//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: SoundManager.h
// Description	: Class definition for SoundManager
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

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
	void playEnterTower();
private:
	std::map<std::string, sf::SoundBuffer> soundBuffers;
	std::list<sf::Sound> sounds;

	sf::SoundBuffer soundBufferPew;
	sf::SoundBuffer soundBufferSplat;
	sf::SoundBuffer soundBufferEnterTower;

	sf::Sound soundPew;
	sf::Sound soundSplat;
	sf::Sound soundEnter;
};

