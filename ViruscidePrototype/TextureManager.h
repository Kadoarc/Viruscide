#pragma once
#include "Utils.h"
#include <map>

class TextureManager
{
public:
	TextureManager();
	void loadFromFile(const std::string &name, const std::string& filename);
	~TextureManager();

	sf::Texture &getTexture(const std::string &name);

private:
	std::map<std::string, sf::Texture> textures;
};

