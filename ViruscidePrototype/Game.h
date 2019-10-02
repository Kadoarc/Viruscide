#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Tower.h"
#include <iostream>
#include <string>
#include "Enemy.h"
#include "Grid.h"
#include "Player.h"
#include "Bullet.h"



class Game
{
public:
	Game();
	~Game();
	std::vector<Tower*> towerList;
	std::vector<Enemy*> enemyList;
	std::vector<Tower*> gui;
	std::vector<Player*> playerList;
	std::vector<Bullet*> bulletList;
	int money;
	int coreHealth;
	int Level;
	sf::Font font;
	void loadFont();
	void MakeGUI();
	sf::Text coreHealthTxt;
	sf::Text MoneyTxt;
	sf::Text gameOverTxt;
	sf::Text tower1PriceTxt;
	sf::Text tower2PriceTxt;
	sf::Text tower3PriceTxt;
	bool isGameOver;
	int GetMoney();
	Tower* underConstruction;
	void UpdateEnemies();
	void UpdatePlayer();
	void UpdateTowers(sf::RenderWindow &window);
	void RenderGameOver(sf::RenderWindow &window);
	void ResetLevel();
	void UpdateBullets();
	int GetCoreHealth();
	void RestartGame();
	std::vector<Grid*> map;
	bool HasMoney();
	bool GetIsGameOver();
	bool ContainsMouse(sf::Vector2i &position);
	bool Construction(sf::Vector2i pos);
	bool CheckPlacement(sf::Vector2i placement);
	void Render(sf::RenderWindow &window, Flags flag);
	void UpdateGUI();
	void CancelTower();
	void WaveGeneration(int difficulty);
	void SpendMoney(int amount);
	void ActivateTowerPlacement();
	void ManageShooting();
	void ManageDamage();
	Flags GameManager(Flags flag);
	void GameCycle(sf::RenderWindow &window, Flags flag);
	void UpdateAllStates(sf::RenderWindow &window);
	void GiveMoney(int amount);
	int GetGridIndex(Grid* gridTile);
	void DrawText(sf::RenderWindow &window);
	Game(std::vector<Grid*> worldMap);
	
	void UpdateInput(const float &dt);
private:

};

