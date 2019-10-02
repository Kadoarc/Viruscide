#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include <SFML\Graphics.hpp>
#include "Intersection.h"

class Level
{
public:
	Level();
	Level(std::string path);
	~Level();

	std::vector<Intersection> intersectionArray;
	std::vector<Entity> drawableZoneArray;
	Intersection startingPoint;
	Intersection endingPoint;

private:

	void readThisFromFile(const std::string &file);
	Intersection m_genericIntersection;
	Entity m_genericRectangleShape;

};

