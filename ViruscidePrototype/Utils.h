#pragma once
#include <SFML/Window.hpp>
#include<iostream>
#include"SFML\Window.hpp"
#include<cstdlib>
#include <SFML\Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>


#define MAP_WIDTH 26
#define MAP_HEIGHT 31
#define TILE_SIZE 32
#define TILEWORLDSIZE 32

const int TILE_OFFSET = 3;
const int GUI_OFFSET = 320;
//const int TILE_SIZE = 80;
const float ENEMY_SIZE = 30;
const int BOARD_HEIGHT = 13;
const int BOARD_WIDTH = 16;
const int FPS = 60;
const int ENEMIES_PER_WAVE = 10;
const int ENRTY_OFFSET = 640;
const sf::Time TIME_PASED = sf::seconds(1.f / 60.f);
const int ENTRY_POINT_INDEX = 47;
using namespace sf;

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
	path
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
	basic = 0,
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