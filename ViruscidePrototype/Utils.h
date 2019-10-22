//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Utils.h
// Description	: Constants to be used in the project
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#pragma once
#include <SFML/Window.hpp>
#include<iostream>
#include"SFML\Window.hpp"
#include<cstdlib>
#include <SFML\Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>

const int TILE_OFFSET = 3;
const int GUI_OFFSET = 320;
const int TILE_SIZE = 80;
const float ENEMY_SIZE = 30;
const int BOARD_HEIGHT = 13;
const int BOARD_WIDTH = 16;
const int FPS = 60;
const int ENEMIES_PER_WAVE = 10;
const int ENRTY_OFFSET = 640;
const sf::Time TIME_PASED = sf::seconds(1.f / 60.f);
const int ENTRY_POINT_INDEX = 47;
using namespace sf;

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

enum Flags
{
	gameInProgress = 0,
	towerUnderConstruction,
	waiting,
	levelOver,
	gameWon,
	gameOver,
	restartGame
};

enum GridType
{
	hill = 0,
	path, 
	core
};

enum FullHdresolution
{
	x = 1920,
	y = 1080
};

enum EnemyType
{
	normal = 0,
	fast,
	fat
};
enum TowerType
{
	basic =0,
	rapid,
	ultimate,
	
};

enum WaveDifficulty
{
	easy = 1,
	medium,
	hard,
	veryhard,
	insane

};