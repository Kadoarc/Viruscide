//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: TextureManager.h
// Description	: Class definition for TextureManager
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

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

