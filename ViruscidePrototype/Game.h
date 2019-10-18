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


class Game
{
public:
	// Constructors&Destructors
	Game(std::vector<Grid*> worldMap, sf::RenderWindow& _window);
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

	// Sound 
	SoundManager soundManager;

	// Declare public variables
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
	void UpdatePlayer();
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
	void GameCycle(sf::RenderWindow &window, Flags flag);
	void UpdateAllStates(sf::RenderWindow &window);
	void GiveMoney(int amount);
	int GetCoreHealth();
	int GetMoney();
	int GetGridIndex(Grid* gridTile);
	void DrawText(sf::RenderWindow &window);
	void ControlTower();
	void UpdateInput(const float &dt);
	bool CheckPlacement(sf::Vector2i placement);

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

