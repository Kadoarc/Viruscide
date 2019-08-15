#include "Game.h"

void Game::loadFont()
{
	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "Font loading Error " << std::endl;
	}
}

void Game::MakeGUI()
{
	gui.push_back(new Tower(50, 89, TowerType::basic));

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


void Game::UpdatePlayer()
{

		
}

void Game::UpdateTowers(sf::RenderWindow & window)
{
	for (int i = 0; i < towerList.size(); i++)
	{
		towerList[i]->Update(window);
	}
}

void Game::RenderGameOver(sf::RenderWindow & window)
{
	gameOverTxt.setString("game over press space to start again? ");
	gameOverTxt.setFont(font);
	gameOverTxt.setPosition(FullHdresolution::x / 2, FullHdresolution::y / 2);
	gameOverTxt.setFillColor(sf::Color::Red);
	window.draw(gameOverTxt);
}

void Game::ResetLevel()
{
	Level = 1;
}

int Game::GetCoreHealth()
{
	return coreHealth;
}

void Game::RestartGame()
{
	towerList.clear();
	enemyList.clear();
	for (int i = 0; i < map.size(); i++)
	{
		if (!map[i]->GetIsEmpty())
		{
			map[i]->SetIsEmpty(true);
		}
	}
	ResetLevel();
	coreHealth = 11;
	isGameOver = false;
	money = 300;
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
			ptr->setOrigin(sf::Vector2f(TILE_SIZE / 2, TILE_SIZE / 2));
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

void Game::Render(sf::RenderWindow &window, Flags flag)
{
	UpdateGUI();

	for (int i = 0; i < map.size(); i++)
	{
		if (flag == Flags::towerUnderConstruction && map[i]->GetIsEmpty())
		{
			if (map[i]->GetTileType() == GridType::hill)
			{
				map[i]->setFillColor(sf::Color::Green);
			}
			else
			{
				map[i]->setFillColor(sf::Color::Red);
			}
		}
		else
		{
			if (map[i]->GetTileType() == GridType::hill)
			{
				map[i]->setFillColor(sf::Color::Yellow);
			}
			else
			{
				map[i]->setFillColor(sf::Color::White);
			}
		}
		window.draw(*map[i]);
	}

	for (int j = 0; j < towerList.size(); j++)
	{
		if (!towerList[j]->GetIsBuilt())
		{
			window.draw(*towerList[j]->DrawPlacementAssist(window));
		}
		window.draw(*towerList[j]);
	}
	for (int k = 0; k < enemyList.size(); k++)
	{
		window.draw(*enemyList[k]);
	}

	for (int m = 0; m < gui.size(); m++)
	{
		window.draw(*gui[m]);
	}

	
	DrawText(window);
}

void Game::UpdateGUI()
{
	tower1PriceTxt.setString(std::to_string(gui[0]->GetPrice()));
	coreHealthTxt.setString(std::to_string(GetCoreHealth()));
	MoneyTxt.setString(std::to_string(GetMoney()));
	tower1PriceTxt.setFont(font);
	coreHealthTxt.setFont(font);
	MoneyTxt.setFont(font);
	tower1PriceTxt.setPosition(gui[0]->getPosition().x + 100, gui[0]->getPosition().y);
	coreHealthTxt.setPosition(1674, 100);
	MoneyTxt.setPosition(1674, 6);
	MoneyTxt.setFont(font);
	tower1PriceTxt.setFillColor(sf::Color::Red);
	coreHealthTxt.setFillColor(sf::Color::Red);
	MoneyTxt.setFillColor(sf::Color::Red);
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
		if (difficulty % 2 == 0)
		{
			enemyList.push_back(new Enemy(map[ENTRY_POINT_INDEX]->getPosition().x + +100 + TILE_SIZE * j, map[ENTRY_POINT_INDEX]->getPosition().y));
		}
		else
		{
			if (difficulty == WaveDifficulty::insane)
			{
				enemyList.push_back(new Enemy(map[ENTRY_POINT_INDEX]->getPosition().x + +100 + TILE_SIZE * j, map[ENTRY_POINT_INDEX]->getPosition().y));
			}
			else
			{
				enemyList.push_back(new Enemy(map[ENTRY_POINT_INDEX]->getPosition().x + +100 + TILE_SIZE * j, map[ENTRY_POINT_INDEX]->getPosition().y));
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


void Game::GameCycle(sf::RenderWindow & window, Flags flag)
{
	if (flag == Flags::restartGame)
	{
		RestartGame();
		GameManager(Flags::gameInProgress);
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
	
		UpdateAllStates(window);
		Render(window, flag);
	}

}


void Game::UpdateAllStates(sf::RenderWindow & window)
{
	UpdateTowers(window);
	UpdateEnemies();
	UpdateGUI();
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
	window.draw(coreHealthTxt);
	window.draw(tower1PriceTxt);

}





Game::Game(std::vector<Grid*> worldMap) :map{ worldMap }, money{ 700 }, coreHealth{ 1 }, isGameOver{ false }, Level{ 1 }
{
	loadFont();
	MakeGUI();
}

void Game::UpdateInput(const float & dt)
{

}

Game::Game()
{

}

Game::~Game()
{
}
