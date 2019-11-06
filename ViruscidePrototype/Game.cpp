//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: Game.cpp
// Description	: Main gameplay logic is done inside here
// Author		: Lorenzo Zemp, Jeremy Bungard, Daniel Joosten
// Mail			: lorenzo.zem8065@mediadesign.school.nz, Jeremy.bun8227.@mediadesign.school.nz, Daniel.joo8189@mediadesign.school.nz
//

#include "Game.h"

/***********************
* loadFont: Loads font from file
* Parameters: NULL
* Return: NULL
********************/
void Game::loadFont()
{
	//if (!font.loadFromFile("Resources/Fonts/galaxymonkey.ttf"))
	if (!font.loadFromFile("Resources/Fonts/OpenSans-Regular.ttf"))
	{
		std::cout << "Font loading Error " << std::endl;
	}
}

/***********************
* MakeGUI: Adds towers to the GUI
* Parameters: NULL
* Return: NULL
********************/
void Game::MakeGUI()
{
	gui.push_back(new Tower(50, 200, TowerType::basic));
	gui.push_back(new Tower(50, 300, TowerType::rapid));
	gui.push_back(new Tower(50, 400, TowerType::ultimate));
}

int Game::GetMoney()
{
	return money;
}

void Game::UpdateEnemies()
{
	for (int i = 0; i < enemyList.size(); i++)
	{
		Enemy* enemyPtr = enemyList[i];
		if (enemyPtr->GetHasWon())
		{
			coreHealth--;
			enemyList.erase(enemyList.begin() + i);
		}
		if (enemyPtr->isAtDestination == true)
		{
			if (!enemyPtr->currentPath)
			{
				enemyPtr->nextPath = map[ENTRY_POINT_INDEX];
			}
			else
			{
				Grid* lastTile = enemyPtr->previousPath;
				Grid* currentTile = enemyPtr->currentPath;
				int currentIndex = GetGridIndex(currentTile);
				Grid* left = nullptr;
				Grid* right = nullptr;
				Grid* up = nullptr;
				Grid* down = nullptr;

				if (!(currentIndex%BOARD_WIDTH == 0))
				{
					left = map[currentIndex - 1];
				}
				if (!((currentIndex + 1) % BOARD_WIDTH == 0))
				{
					right = map[currentIndex + 1];
				}
				if (!(currentIndex < BOARD_WIDTH))
				{
					up = map[currentIndex - BOARD_WIDTH];
				}
				if (!(currentIndex > (BOARD_HEIGHT*BOARD_WIDTH - BOARD_WIDTH)))
				{
					down = map[currentIndex + BOARD_WIDTH];
				}

				if (left && (left->GetTileType() == GridType::path) && (left != lastTile))
				{
					enemyPtr->nextPath = left;
					enemyPtr->isAtDestination = false;
				}
				if (right && (right->GetTileType() == GridType::path) && (right != lastTile))
				{
					enemyPtr->nextPath = right;
					enemyPtr->isAtDestination = false;
				}
				if (up && (up->GetTileType() == GridType::path) && (up != lastTile))
				{
					enemyPtr->nextPath = up;
					enemyPtr->isAtDestination = false;
				}
				if (down && (down->GetTileType() == GridType::path) && (down != lastTile))
				{
					enemyPtr->nextPath = down;
					enemyPtr->isAtDestination = false;
				}

			}
		}
		if (enemyList.size() > 0)
		{
			enemyList[i]->Update();
		}
	}
}

void Game::UpdatePlayer(sf::Event &event)
{
	// PLAYER ONE / WASD MOVEMENT
	// Only enable player movement if not occupying a tower
	if (playerList.at(0)->m_OccupyingTower == false)
	{
		Player1Movement();
	}

	// PLAYER TWO / ARROW KEY MOVMENT
	// Only allow movement if occupying a tower
	if (playerList.back()->m_OccupyingTower == false)
	{
		Player2Movement();
	}

	// Player Collision With ITEMS
	for (int i = 0; i < itemList.size(); i++)
	{
		// Player 1
		if (playerList.at(0)->getGlobalBounds().intersects(itemList.at(i)->getGlobalBounds()))
		{
			std::cout << " Item Pickup \n";
			itemList.erase(itemList.begin() + i);
			GiveMoney(50);
		}
		// Player 2
		else if (playerList.at(1)->getGlobalBounds().intersects(itemList.at(i)->getGlobalBounds()))
		{
			std::cout << " Item Pickup \n";
			itemList.erase(itemList.begin() + i);
			GiveMoney(50);
		}
	}

}

void Game::UpdateTowers(sf::RenderWindow & window)
{
	for (int i = 0; i < towerList.size(); i++)
	{
		towerList[i]->Update(window);

		if (towerList.at(i)->isOccupiedP1 == true)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				// DEBUG
				//std::cout << "Rotation Angle: " << towerList.at(i)->rotationAngle << std::endl;
				towerList.at(i)->rotationAngle -= 2;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				// DEBUG
				//std::cout << "Rotation Angle: " << towerList.at(i)->rotationAngle << std::endl;
				towerList.at(i)->rotationAngle += 2;
			}

		}
		if (towerList.at(i)->isOccupiedP2 == true)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				towerList.at(i)->rotationAngle -= 2;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				towerList.at(i)->rotationAngle += 2;
			}
		}

	}
}

void Game::RenderGameOver(sf::RenderWindow & window)
{
	gameOverTxt.setString("game over press space to start again? ");
	gameOverTxt.setFont(font);
	gameOverTxt.setOrigin(gameOverTxt.getGlobalBounds().width / 2.0f, gameOverTxt.getGlobalBounds().height / 2.0f);
	gameOverTxt.setPosition(SCREEN_WIDTH / 2.0f, SCREEN_WIDTH / 2.0f);
	gameOverTxt.setFillColor(sf::Color::Red);
	window.draw(gameOverTxt);
}

void Game::ResetLevel()
{
	Level = 1;
	killCounter = 0;
}

void Game::UpdateBullets()
{
	for (int i = 0; i < bulletList.size(); i++)
	{
		bulletList[i]->Update();
	}

	for (int j = 0; j < playerBulletList.size(); j++)
	{
		playerBulletList[j]->Update();
	}

}

int Game::GetCoreHealth()
{
	return coreHealth;
}

void Game::RestartGame(sf::RenderWindow& _window)
{
	towerList.clear();
	enemyList.clear();
	bulletList.clear();
	itemList.clear();
	playerList.clear();
	playerBulletList.clear();
	for (int i = 0; i < map.size(); i++)
	{
		if (!map[i]->GetIsEmpty())
		{
			map[i]->SetIsEmpty(true);
		}
	}
	ResetLevel();
	coreHealth = 30;
	isGameOver = false;
	money = 1000;
	killCounter = 0;
	// Add the players
	// Player 1
	playerList.push_back(new Player(SCREEN_WIDTH / 2 + 100, SCREEN_HEIGHT / 2, 1, _window));
	// Player 2
	playerList.push_back(new Player(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2, 2, _window));
	
}

bool Game::HasMoney()
{
	if (underConstruction->GetPrice() <= money)
	{
		return true;
	}
	return false;
}

bool Game::GetIsGameOver()
{
	return isGameOver;
}

bool Game::ContainsMouse(sf::Vector2i & position)
{
	if (position.x < map[0]->getPosition().x)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::Construction(sf::Vector2i pos)
{
	for (int i = 0; i < gui.size(); i++)
	{
		Tower* guiPtr = gui[i];
		if (guiPtr->getGlobalBounds().contains(pos.x, pos.y))
		{

			underConstruction = guiPtr;
			if (HasMoney())
			{
				soundManager.playConstructTower();
				return true;
			}
		}
	}
	return false;
}

bool Game::CheckPlacement(sf::Vector2i placement)
{
	for (int i = 0; i < map.size(); i++)
	{
		Grid* groundPtr = map[i];
		if (groundPtr->getGlobalBounds().contains(placement.x, placement.y) && groundPtr->GetIsEmpty() && groundPtr->GetTileType() != GridType::path)
		{
			Tower* ptr = towerList.back();
			ptr->setPosition(sf::Vector2f(map[i]->getPosition()));
			ptr->SetState();
			groundPtr->SetIsEmpty(false);
			SpendMoney(ptr->GetPrice());
			if (!ptr)
			{
				continue;
			}
			ptr->SetState();
			
			return true;
		}
	}
	return false;
}

void Game::EPressed()
{
	// Get the TOWER list
	for (int i = 0; i < towerList.size(); i++)
	{
		// Check player ONE collisions against the tower list
		if (playerList.at(0)->getGlobalBounds().intersects(towerList.at(i)->getGlobalBounds()))
		{
			// When the player releases E
			// Toggle occupy tower based on state
			switch (playerList.at(0)->m_OccupyingTower)
			{
				// If we are in a tower, EXIT the tower
			case true:
			{
				std::cout << "Player 1 Occupying tower = FALSE\n";
				soundManager.playEnterTower();
				playerList.at(0)->m_OccupyingTower = false;
				towerList.at(i)->autoShoot = true;
				towerList.at(i)->isOccupiedP1 = false;
				break;
			}
			// If we are not in a tower, ENTER the tower
			case false:
			{
				std::cout << "Player 1 Occupying tower = TRUE\n";
				soundManager.playEnterTower();
				playerList.at(0)->m_OccupyingTower = true;
				towerList.at(i)->autoShoot = false;
				towerList.at(i)->isOccupiedP1 = true;
				break;
			}
			default:
				break;
			}
		}
	}
}

void Game::Numpad0Pressed()
{
	 // Get the TOWER list
	for (int i = 0; i < towerList.size(); i++)
	{
		// Check player TWO collisions against the tower list
		if (playerList.back()->getGlobalBounds().intersects(towerList.at(i)->getGlobalBounds()))
		{
			// Toggle occupy tower based on state
			switch (playerList.back()->m_OccupyingTower)
			{
				// If we are in a tower, EXIT the tower
			case true:
			{
				std::cout << "Player 2 Occupying tower = FALSE\n";
				soundManager.playEnterTower();
				playerList.back()->m_OccupyingTower = false;
				towerList.at(i)->autoShoot = true;
				towerList.at(i)->isOccupiedP2 = false;
				break;
			}
			// If we are not in a tower, ENTER the tower
			case false:
			{
				std::cout << "Player 2 Occupying tower = TRUE\n";
				soundManager.playEnterTower();
				playerList.back()->m_OccupyingTower = true;
				towerList.at(i)->autoShoot = false;
				towerList.at(i)->isOccupiedP2 = true;
				break;
			}
			default:
				break;
			}
		}
	}
}

void Game::WPressed()
{
	for (int i = 0; i < towerList.size(); i++)
	{
		if (towerList.at(i)->isOccupiedP1 == true)
		{
			// bulletList.push_back(new Bullet(towerList[i], enemyList[j]));
			// Add a bullet to the list
			playerBulletList.push_back(new PlayerBullet(towerList.at(i)->rotationAngle, towerList.at(i)));
			// DEBUG
			//std::cout << "Spawning bullet at rotation angle: " << towerList.at(i)->rotationAngle std::endl;
			// Play shooting sound
			soundManager.playPew();
			// Set the shooting cooldown
			towerList[i]->SetIsReadyToFire(false);
		}
	}
}

void Game::UpPressed()
{
	for (int i = 0; i < towerList.size(); i++)
	{
		if (towerList.at(i)->isOccupiedP2 == true)
			{
				// bulletList.push_back(new Bullet(towerList[i], enemyList[j]));
				// Add a bullet to the list
				playerBulletList.push_back(new PlayerBullet(towerList.at(i)->rotationAngle, towerList.at(i)));
				// Play shooting sound
				soundManager.playPew();
				// Set the shooting cooldown
				towerList[i]->SetIsReadyToFire(false);
			}
	}
}

void Game::Render(sf::RenderWindow &window, Flags flag)
{
	//render game plain background 
	window.draw(gameBackgroundSprite);

	UpdateGUI();

	for (int i = 0; i < map.size(); i++)
	{
		if (flag == Flags::towerUnderConstruction && map[i]->GetIsEmpty())
		{
			if (map[i]->GetTileType() == GridType::hill)
			{
				map[i]->setFillColor(sf::Color::Green);
			}
			else if (map[i]->GetTileType() == GridType::core)
			{
				map[i]->setFillColor(sf::Color::Magenta);
			}
			else
			{
				//map[i]->setFillColor(sf::Color::Red);
			}

		}
		else
		{
			if (map[i]->GetTileType() == GridType::hill)
			{
				map[i]->setFillColor(sf::Color(229, 107, 112));
			}
			else if (map[i]->GetTileType() == GridType::core)
			{
				map[i]->setFillColor(sf::Color::Magenta);
			}
			else //Path
			{
				map[i]->setFillColor(sf::Color(136, 13, 30));
			}
		}
		window.draw(*map[i]);
	}

	// Render Towers
	for (int j = 0; j < towerList.size(); j++)
	{
		// Draw tower range radius
		if (!towerList[j]->GetIsBuilt())
		{
			window.draw(*towerList[j]->DrawPlacementAssist(window));
		}
		// Draw shooting indicator
		else if (!towerList[j]->autoShoot)
		{
			window.draw(*towerList[j]->DrawShootingIndicator(window));
		}
		//window.draw(*towerList[j]);
		towerList[j]->draw(window);
	}

	// Render GUI
	for (int m = 0; m < gui.size(); m++)
	{
		//window.draw(*gui[m]);
		gui[m]->draw(window);
	}

	// Render Players
	for (int l = 0; l < playerList.size(); l++)
	{
		//window.draw(*playerList[l]);
		playerList[l]->drawPlayer(window);
	}

	// Render Bullets
	for (int n = 0; n < bulletList.size(); n++)
	{
		window.draw(*bulletList[n]);
	}

	// Render Items
	for (int p = 0; p < itemList.size(); p++)
	{
		window.draw(itemList[p]->getSprite());
	}

	// Render Enemies
	for (int k = 0; k < enemyList.size(); k++)
	{
		window.draw(enemyList[k]->getSprite());
	}

	// Render PlayerBullets
	for (int e = 0; e < playerBulletList.size(); e++)
	{
		window.draw(*playerBulletList[e]);
	}

	// Render Window
	DrawText(window);
}

void Game::UpdateGUI()
{
	
	/// TEXT - Tower Label
	towerLabelTxt.setCharacterSize(20);
	towerLabelTxt.setFont(font);
	towerLabelTxt.setFillColor(sf::Color::White);
	towerLabelTxt.setString("Click to select a tower:");
	towerLabelTxt.setPosition(SCREEN_WIDTH / 2 - 925, SCREEN_HEIGHT / 2 - 425);

	/// TEXT - Tower Prices
	// tower1PriceTxt.setFillColor(sf::Color::Red);
	tower1PriceTxt.setCharacterSize(15);
	tower2PriceTxt.setCharacterSize(15);
	tower3PriceTxt.setCharacterSize(15);
	tower1PriceTxt.setString("Basic: " + std::to_string(gui[0]->GetPrice()));
	tower2PriceTxt.setString("Rapid: " + std::to_string(gui[1]->GetPrice()));
	tower3PriceTxt.setString("Ultimate: " + std::to_string(gui[2]->GetPrice()));

	tower1PriceTxt.setPosition(gui[0]->getPosition().x + 50, gui[0]->getPosition().y);
	tower2PriceTxt.setPosition(gui[1]->getPosition().x + 50, gui[1]->getPosition().y);
	tower3PriceTxt.setPosition(gui[2]->getPosition().x + 50, gui[2]->getPosition().y);

	tower1PriceTxt.setFont(font);
	tower2PriceTxt.setFont(font);
	tower3PriceTxt.setFont(font);

	/// TEXT - Core
	CoreTxt.setFont(font);
	CoreTxt.setString("Core Health: ");
	CoreTxt.setPosition(SCREEN_WIDTH / 2 + 680, SCREEN_HEIGHT / 2 - 500);
	CoreTxt.setFillColor(sf::Color::White);
	/// TEXT - Core Health
	coreHealthTxt.setString(std::to_string(GetCoreHealth()));
	coreHealthTxt.setFont(font);
	/// Change the core health colour based on remaining lives
	if (coreHealth > 20)
	{
		coreHealthTxt.setFillColor(sf::Color::Green);
	}
	else if (coreHealth >= 10 && coreHealth <= 20)
	{
		coreHealthTxt.setFillColor(sf::Color::Yellow);
	}
	else
	{
		coreHealthTxt.setFillColor(sf::Color::Red);
	}

	coreHealthTxt.setPosition(SCREEN_WIDTH / 2 + 875, SCREEN_HEIGHT / 2 - 500);
	/// TEXT - Money
	MoneyTxt.setStyle(sf::Text::Bold);
	MoneyTxt.setString("Money: " + std::to_string(GetMoney()));
	MoneyTxt.setFont(font);
	MoneyTxt.setPosition(SCREEN_WIDTH / 2 - 925, SCREEN_HEIGHT / 2 - 500);
	MoneyTxt.setFont(font);
	MoneyTxt.setFillColor(sf::Color::Yellow);
	/// TEXT - Kill Counter
	killCounterLabelTxt.setFont(font);
	killCounterLabelTxt.setPosition(SCREEN_WIDTH / 2 + 680, SCREEN_HEIGHT / 2 - 450);
	killCounterLabelTxt.setFillColor(sf::Color::White);
	killCounterLabelTxt.setString("Total Kills: ");
	killCounterTxt.setFont(font);
	killCounterTxt.setPosition(SCREEN_WIDTH / 2 + 850, SCREEN_HEIGHT / 2 - 450);
	killCounterTxt.setFillColor(sf::Color::Red);
	killCounterTxt.setString(std::to_string(killCounter));
	
}

void Game::CancelTower()
{
	if (towerList.size())
	{
		towerList.pop_back();
	}
}

void Game::WaveGeneration(int difficulty)
{

	enemyList.clear();
	

	for (int j = 0; j < difficulty*ENEMIES_PER_WAVE; j++)
	{
		if (difficulty == WaveDifficulty::easy)
		{
			enemyList.push_back(new Enemy(map[ENTRY_POINT_INDEX]->getPosition().x + +100 + TILE_SIZE * j, map[ENTRY_POINT_INDEX]->getPosition().y, EnemyType::fat));
		}
		
		else
		{
			if (difficulty == WaveDifficulty::medium)
			{
				enemyList.push_back(new Enemy(map[ENTRY_POINT_INDEX]->getPosition().x + +100 + TILE_SIZE * j, map[ENTRY_POINT_INDEX]->getPosition().y, EnemyType::fast));
			}
			if (difficulty == WaveDifficulty::veryhard)
			{
				enemyList.push_back(new Enemy(map[ENTRY_POINT_INDEX]->getPosition().x + +100 + TILE_SIZE * j, map[ENTRY_POINT_INDEX]->getPosition().y, EnemyType::normal));
			}

			if (difficulty == WaveDifficulty::insane)
			{
				enemyList.push_back(new Enemy(map[ENTRY_POINT_INDEX]->getPosition().x + +100 + TILE_SIZE * j, map[ENTRY_POINT_INDEX]->getPosition().y, EnemyType::fat));
			}
			else
			{
				enemyList.push_back(new Enemy(map[ENTRY_POINT_INDEX]->getPosition().x + +100 + TILE_SIZE * j, map[ENTRY_POINT_INDEX]->getPosition().y, EnemyType::fat));
			}
		}

	}
}

void Game::SpendMoney(int amount)
{
	money -= amount;
}

void Game::ActivateTowerPlacement()
{
	towerList.push_back(new Tower(underConstruction->getPosition().x, underConstruction->getPosition().y, underConstruction->GetType()));
	underConstruction = nullptr;
}

void Game::ManageShooting()
{
	// First the list of TOWERS
	for (int i = 0; i < towerList.size(); i++)
	{
		// Check if the tower is built and it is ready to fire
		if (towerList[i]->GetIsBuilt() && towerList[i]->GetIsReadyToFire())
		{
			// If we are not occupied
			if (towerList.at(i)->autoShoot == true)
			// Get the list of ENEMIES
			for (int j = 0; j < enemyList.size(); j++)
			{
				// Check if an ENEMY is within a TOWER range and it is ready to fire
				if (towerList[i]->GetRange()->getGlobalBounds().contains(enemyList[j]->getPosition()) && towerList[i]->GetIsReadyToFire())
				{
					// Add a bullet to the list
					bulletList.push_back(new Bullet(towerList[i], enemyList[j]));
					// Play shooting sound
					soundManager.playPew();
					// Set the shooting cooldown
					towerList[i]->SetIsReadyToFire(false);
				}
			}
		}
	}
}

void Game::ManageDamage()
{
	// Get the ENEMY list
	for (int i = 0; i < enemyList.size(); i++)
	{
		// Get the BULLET list
		for (int j = 0; j < bulletList.size(); j++)
		{
			// First check if the bullet has expired
			if (bulletList.at(j)->ExpiredBullet == true)
			{
				bulletList.erase(bulletList.begin() + j);
			}

			// Get the enemy and see if the bullet is inside it
			else if (enemyList[i]->getGlobalBounds().contains(bulletList[j]->getPosition()))// crash
			{
				// Apply damage to the enemy
				enemyList[i]->GiveDamage(bulletList[j]);
				// Erase the bullet
				bulletList.erase(bulletList.begin() + j);
			}
		}

		// Get the PLAYER BULLET list
		for (int p = 0; p < playerBulletList.size(); p++)
		{
			// First check if the bullet has expired
			if (playerBulletList.at(p)->ExpiredBullet == true)
			{
				playerBulletList.erase(playerBulletList.begin() + p);
			}

			// Get the enemy and see if the bullet is inside it
			else if (enemyList[i]->getGlobalBounds().intersects(playerBulletList[p]->getGlobalBounds()))
			{
				// Apply damage
				enemyList[i]->GiveDamage(playerBulletList[p]);

				// Erase the bullet
				playerBulletList.erase(playerBulletList.begin() + p);
			}
		}

		if (enemyList[i]->GetHP() <= 0)
		{
			
			// Play kill count
			soundManager.playSplat();
			// Iterate the Kill Counter
			killCounter++;
			std::cout << "Enemy Kill Counter: " << killCounter << std::endl;
			// If % 10 then spawn an item drop
			if (killCounter % 10 == 0)
			{
				itemList.push_back(new ItemDrop(enemyList.at(i)->getPosition().x, enemyList.at(i)->getPosition().y, 1));
			}
			// Add money 
			GiveMoney(enemyList[i]->GetValue());
			// Finally remove the enemy
			enemyList.erase(enemyList.begin() + i);
		}
	}
}


Flags Game::GameManager(Flags flag)
{

	if (coreHealth > 0)
	{
		if (Level < WaveDifficulty::insane && enemyList.empty())
		{
			
			WaveGeneration(Level);
			Level++;
			return Flags::gameInProgress;
		}
		else if (Level > WaveDifficulty::insane)
		{
			return Flags::gameWon;
		}
		else

			return Flags::waiting;
	}
	else
	{
		isGameOver = true;
		return Flags::gameOver;
	}
}

void Game::GameCycle(sf::RenderWindow& window, Flags flag, sf::Event& _event, sf::Clock& _clock)
{
	if (firstRun)
	{
		RestartGame(window);
		_clock.restart();
		GameManager(Flags::gameInProgress);
		firstRun = false;
		
	}
	if (flag == Flags::restartGame)
	{
		RestartGame(window);
	}

	if (GameManager(flag) != Flags::waiting)
	{
		if (GameManager(flag) == Flags::gameWon)
		{

		}
		else if (GameManager(flag) == Flags::gameOver)
		{

		}
	}
	else
	{
		
		ManageDamage();
		ManageShooting();
		UpdateAllStates(window, _event);
		Render(window, flag);
	}

}

void Game::UpdateAllStates(sf::RenderWindow& window, sf::Event& _event)
{
	
	UpdatePlayer(_event);
	UpdateTowers(window);
	UpdateEnemies();
	UpdateBullets();
	UpdateGUI();
}

void Game::GiveMoney(int amount)
{
	money += amount;
}

int Game::GetGridIndex(Grid * gridTile)
{
	for (int i = 0; i < map.size(); i++)
	{
		if (map[i] == gridTile)
		{
			return i;
		}
	}
	return -1;
}

void Game::DrawText(sf::RenderWindow & window)
{
	window.draw(MoneyTxt);
	window.draw(CoreTxt);
	window.draw(coreHealthTxt);
	window.draw(towerLabelTxt);
	window.draw(tower1PriceTxt);
	window.draw(tower2PriceTxt);
	window.draw(tower3PriceTxt);
	window.draw(killCounterTxt);
	window.draw(killCounterLabelTxt);
}

Game::Game(std::vector<Grid*> worldMap, sf::RenderWindow& _window, sf::Event& _event) :map{ worldMap }, money{ 200 }, coreHealth{ 30 }, isGameOver{ false }, Level{ 1 }
{
	// Add the players
	// Player 1
	playerList.push_back(new Player(SCREEN_WIDTH / 2 + 100, SCREEN_HEIGHT / 2, 1, _window));
	// Player 2
	playerList.push_back(new Player(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2, 2, _window));
	loadFont();
	MakeGUI();
	_window.setKeyRepeatEnabled(false);
	//load audio
	soundManager = SoundManager();
	soundManager.loadFiles();
	soundManager.playBackgroundMusic();

	if (!gameBackgroundTexture.loadFromFile("Resources/Images/ViruscideGameBackround.png"))
	{
		std::cout << "error loading game background" << std::endl;
	}

	gameBackgroundSprite.setTexture(gameBackgroundTexture);
	gameBackgroundSprite.setOrigin(gameBackgroundSprite.getGlobalBounds().width / 2, gameBackgroundSprite.getGlobalBounds().height / 2);
	gameBackgroundSprite.setPosition(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
	
}

//void Game::ControlTower()
//{
//	if (m_OverlappingTower = true && (sf::Keyboard::isKeyPressed(sf::Keyboard::E)))
//	{
//
//	}
//}

void Game::UpdateInput(const float & dt)
{

}

void Game::Player1Movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		playerList.at(0)->xPos -= playerList.at(0)->moveSpeed;
		playerList.at(0)->setPosition(playerList.at(0)->xPos, playerList.at(0)->yPos);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		playerList.at(0)->yPos -= playerList.at(0)->moveSpeed;
		playerList.at(0)->setPosition(playerList.at(0)->xPos, playerList.at(0)->yPos);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		playerList.at(0)->yPos += playerList.at(0)->moveSpeed;
		playerList.at(0)->setPosition(playerList.at(0)->xPos, playerList.at(0)->yPos);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		playerList.at(0)->xPos += playerList.at(0)->moveSpeed;
		playerList.at(0)->setPosition(playerList.at(0)->xPos, playerList.at(0)->yPos);
	}
}

void Game::Player2Movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		playerList.at(1)->xPos -= playerList.at(1)->moveSpeed;
		playerList.at(1)->setPosition(playerList.at(1)->xPos, playerList.at(1)->yPos);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		playerList.at(1)->yPos -= playerList.at(1)->moveSpeed;
		playerList.at(1)->setPosition(playerList.at(1)->xPos, playerList.at(1)->yPos);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		playerList.at(1)->yPos += playerList.at(1)->moveSpeed;
		playerList.at(1)->setPosition(playerList.at(1)->xPos, playerList.at(1)->yPos);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		playerList.at(1)->xPos += playerList.at(1)->moveSpeed;
		playerList.at(1)->setPosition(playerList.at(1)->xPos, playerList.at(1)->yPos);
	}
}
Game::Game()
{

}

Game::~Game()
{
}
