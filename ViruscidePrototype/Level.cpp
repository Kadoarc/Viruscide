#include "Level.h"

Level::Level()
{
}

Level::Level(std::string path)
{
	readThisFromFile(path);
}


Level::~Level()
{
}

void Level::readThisFromFile(const std::string & file)
{
	std::ifstream myFile(file);

	sf::Vector2f position;
	std::string delimiter = " ";

	std::string line;
	while (std::getline(myFile, line))
	{
		std::replace(line.begin(), line.end(), ',', ' ');
		std::stringstream iss(line);

		std::string item;
		std::vector<std::string> splittedStrings;

		while (iss >> item)
			splittedStrings.push_back(item);

		if (splittedStrings[0] == "I")
			intersectionArray.push_back(Intersection(sf::Vector2f(std::stoi(splittedStrings[1]), std::stoi(splittedStrings[2])), std::stoi(splittedStrings[3])));
		else if (splittedStrings[0] == "D")
		{
			drawableZoneArray.push_back(Entity(sf::Vector2f(std::stoi(splittedStrings[1]), std::stoi(splittedStrings[2])), sf::Vector2f(std::stoi(splittedStrings[3]), std::stoi(splittedStrings[4]))));
			drawableZoneArray.back().setColour(Globals::Color::drawableZoneColor);
		}
		else if (splittedStrings[0] == "S")
			startingPoint = Intersection(sf::Vector2f(std::stoi(splittedStrings[1]), std::stoi(splittedStrings[2])), std::stoi(splittedStrings[3]));
		else if (splittedStrings[0] == "E")
			endingPoint = Intersection(sf::Vector2f(std::stoi(splittedStrings[1]), std::stoi(splittedStrings[2])), std::stoi(splittedStrings[3]));
		else
		{
			/* Not handled */ // should throw error here
		}
	}
}
