#pragma once
#include <SFML/Audio.hpp>

#include <map>
#include <list>

class SoundManager
{
public:
	SoundManager();
	
	void loadFromFile(const std::string &name, const std::string& filename);
	void play(const std::string &name);

private:

};

