//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Game.h
// Description	: Class definition for Game
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Tower.h"
#include <iostream>
#include <string>
#include "Enemy.h"
#include "Grid.h"
#include "Player.h"
#include "Label.h"
#include "Bullet.h"
#include "SoundManager.h"
#include "ItemDrop.h"
#include "Projectile.h"
#include "playerBullet.h"
#include "Clock.h"

class Game
{
public:
	// Constructors&Destructors
	Game(std::vector<Grid*> worldMap, sf::RenderWindow& _window, sf::Event& _event);
	Game();
	~Game();

	// Declare vectors
	std::vector<Tower*> towerList;
	std::vector<Enemy*> enemyList;
	std::vector<Tower*> gui;
	std::vector<Player*> playerList;
	std::vector<Bullet*> bulletList;
	std::vector<ItemDrop*> itemList;
	std::vector<Grid*> map;
	std::vector<Projectile*> projList;
	std::vector<PlayerBullet*> playerBulletList;
	// Sound 
	SoundManager soundManager;
	
	// Declare public variables
	bool firstRun = true;
	bool isGameOver;
	int money;
	int coreHealth;
	int Level;
	int killCounter;

	// Declare public functions
	void loadFont();
	void MakeGUI();
	void RestartGame();
	bool HasMoney();
	bool GetIsGameOver();
	bool ContainsMouse(sf::Vector2i & position);
	bool Construction(sf::Vector2i pos);
	void UpdateEnemies();
	void UpdatePlayer(sf::Event &event);
	void Player1Movement();
	void Player2Movement();
	void Player1TowerMovement();
	void Player2TowerMovement();
	void UpdateTowers(sf::RenderWindow &window);
	void RenderGameOver(sf::RenderWindow &window);
	void ResetLevel();
	void UpdateBullets();
	void Render(sf::RenderWindow &window, Flags flag);
	void UpdateGUI();
	void CancelTower();
	void WaveGeneration(int difficulty);
	void SpendMoney(int amount);
	void ActivateTowerPlacement();
	void ManageShooting();
	void ManageDamage();
	void deleteBullet(Bullet* bullet);
	void GameCycle(sf::RenderWindow &window, Flags flag, sf::Event& _event, sf::Clock& _clock);
	void UpdateAllStates(sf::RenderWindow &window, sf::Event &event);
	void GiveMoney(int amount);
	int GetCoreHealth();
	int GetMoney();
	int GetGridIndex(Grid* gridTile);
	void DrawText(sf::RenderWindow &window);
	void UpdateInput(const float &dt);
	bool CheckPlacement(sf::Vector2i placement);
	void spawnProjectile(Tower* towerPtr);
	void ManageTowers(const float &dt);
	void ManageProjectiles(const float &dt);
	void EPressed();
	void Numpad0Pressed();
	void WPressed();
	void UpPressed();


	// Text variables
	sf::Font font;
	sf::Text CoreTxt;
	sf::Text moneyLabel;
	sf::Text coreHealthTxt;
	sf::Text MoneyTxt;
	sf::Text gameOverTxt;
	sf::Text towerLabelTxt;
	sf::Text tower1PriceTxt;
	sf::Text tower2PriceTxt;
	sf::Text tower3PriceTxt;
	sf::Text killCounterLabelTxt;
	sf::Text killCounterTxt;

	// Pointers
	Tower* underConstruction;
	Tower* SearchInTowers(sf::Vector2f pos);
	Flags GameManager(Flags flag);

private:

};

