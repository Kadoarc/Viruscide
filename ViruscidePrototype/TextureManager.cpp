//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: TextureManager.cpp
// Description	: Class implementation for the texture manager
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#include "TextureManager.h"

TextureManager::TextureManager()
	:textures()
{
}

void TextureManager::loadFromFile(const std::string &name, const std::string &filename)
{
	sf::Texture texture;
	texture.loadFromFile(filename);
	textures[name] = texture;
}


TextureManager::~TextureManager()
{
}

sf::Texture & TextureManager::getTexture(const std::string &name)
{
	return  textures.at(name);
}
