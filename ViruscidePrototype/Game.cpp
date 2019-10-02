#include "Game.h"
#include "Application.h"
#include "MainMenu.h"
#include"../Logging/Logging.h"

Game::Game(const std::string &path)
{
	/* Random seed */
	srand(time(nullptr));

	/* Set our initial gold value */
	m_shop.setGold(m_gold);

	/* Set our initial life value */
	m_shop.setLifePoints(m_lifePoints);

	/* Shadow thingy */
	m_shadowEntity.setVisible(false);
	m_shadowEntity.setMainTowerVisible(false);

	//Level defaultLevel();
	//m_currentLevel = &defaultLevel;
	m_currentLevel = Level(path);
	Logger logger(std::cout);
	logger.log("Started game", Logger::Level::Info);

	player1.drawPlayer();
}
Game::~Game()
{}

void Game::update(sf::RenderWindow &window)
{
	/* If we reached the end, then stop everything else from working */
	if (checkWinLossConditions()) return;
	updatePlayer();
	updateTowers();
	updateShadowEntity();
	updateEnemies();
	handleEvent(window);
}
void Game::draw(sf::RenderWindow & window)
{
	///
	for (const Entity& zone : m_currentLevel.drawableZoneArray)
		window.draw(zone);

	/* Draw our beautiful enemies */
	for (int i = 0; i < m_enemyArray.size(); ++i)
		window.draw(*m_enemyArray[i]);

	/* Draw the intersections */
	for (Intersection i : m_currentLevel.intersectionArray)
		window.draw(i);

	for (Tower i : m_towerArray)
		window.draw(i);

	window.draw(player1);
	window.draw(player2);

	/* Draw our Shop overlay */
	window.draw(m_shop);

	/* Our mouse shadow thing */
	window.draw(m_shadowEntity);

}
void Game::handleEvent(sf::RenderWindow &window)
{
	sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);

	/* If right clicked pressed */
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		/* Cancel any shadow thingy */
		m_shop.isSelected = false;
		m_shadowEntity.setVisible(false);
		m_shadowEntity.setMainTowerVisible(false);

		return;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

		if (!m_shop.isSelected)
			m_shop.update(mousePos);
		else if (m_canPlaceShadowEntity && m_shop.isSelected && !m_shop.isCollisonWithPoint(mousePos))
		{
			/* Handle the shop button that was pressed */
			handleShopPressed(mousePos);
			m_shop.isSelected = false;
			m_shadowEntity.setVisible(false);
			m_shadowEntity.setMainTowerVisible(false);

		}

	}

	if (m_shop.isSelected && !m_shop.isCollisonWithPoint(mousePos))
	{
		/* Draw our little shadow thingy */
		if (!m_shadowEntity.isMainTowerVisible())
		{
			m_shadowEntity.setVisible(true);
			m_shadowEntity.setMainTowerVisible(true);
		}

		/* Update it's position on the mouse */
		m_shadowEntity.setCenterPosition(mousePos);
	}

	/* Cheat code to add money */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		m_gold += 50;
		m_shop.setGold(m_gold);
	}

	/*Exit to main menu*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		Application::getInstance()->setState(std::make_unique<MainMenu>());
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player1.moveWest();

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player1.moveNorth();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player1.moveSouth();

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player1.moveEast();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		std::cout << "E pressed \n";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player2.moveEast();

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		player2.moveNorth();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		player2.moveSouth();

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		player2.moveWest();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
	{
		std::cout << "RControl pressed \n";
	}
}
void Game::updateTowers()
{
	/* Go through all of our towers and check if any enemy entered in their collision */
	for (int i = 0; i < m_towerArray.size(); ++i)
	{
		/* Go through each enemy and check if it's colliding with any */
		if (!m_towerArray[i].isAttacking())
		{
			for (int j = 0; j < m_enemyArray.size(); ++j)
				if (m_towerArray[i].isCollision(*m_enemyArray[j]))
					m_towerArray[i].setIntruder(m_enemyArray[j]);
		}
		else
		{
			m_towerArray[i].update();
		}
	}

}
void Game::updateEnemiesPositions()
{
	for (int i = 0; i < m_enemyArray.size(); ++i)
		m_enemyArray[i]->move();
}
bool Game::checkWinLossConditions()
{
	if (m_gameIsWon)
	{
		Application::getInstance()->setState(std::make_unique<EndScreen>(m_gameIsWon));
		return true;
	}
	else if (m_lifePoints <= 0)
	{
		Application::getInstance()->setState(std::make_unique<EndScreen>(m_gameIsWon));
		return true;
	}

	return false;
}
void Game::updatePlayer()
{
	for (const Tower& tower : m_towerArray)
	{
		if (tower.isCollision(player1))
		{
			{
				Player mainHitboxToEntity;
				mainHitboxToEntity.setPosition(player1.getMainHitbox().getPosition());
				mainHitboxToEntity.setSize(player1.getMainHitbox().getSize());

				sf::RectangleShape pos = tower.getCollision(mainHitboxToEntity);

				Tower collisionToEntity;
				collisionToEntity.setPosition(pos.getPosition());
				collisionToEntity.setSize(pos.getSize());
				if (mainHitboxToEntity == collisionToEntity)
				{
					m_towerOccupied = true;
					cout << "Tower occupied" << endl;
				}

			}
		}

	}


}

void Game::updateShadowEntity()
{
	/* Only update the entity if m_shop.isSelected */
	if (!m_shop.isSelected)
		return;

	/* Go through all of the zones and see if we collide with any */
	for (const Entity& zone : m_currentLevel.drawableZoneArray)
	{
		if (zone.isCollisionWithRect(m_shadowEntity.getMainHitbox()))
		{
			/* Have to do it this way beacause the RectangleShape doens't have == operator overloaded */
			Entity mainHitboxToEntity;
			mainHitboxToEntity.setPosition(m_shadowEntity.getMainHitbox().getPosition());
			mainHitboxToEntity.setSize(m_shadowEntity.getMainHitbox().getSize());

			sf::RectangleShape pos = zone.getCollision(mainHitboxToEntity);

			Entity collisionToEntity;
			collisionToEntity.setPosition(pos.getPosition());
			collisionToEntity.setSize(pos.getSize());

			if (mainHitboxToEntity == collisionToEntity)
			{
				/* Now check that we are not colliding with any other towers */
				for (const Tower& tower : m_towerArray)
					if (mainHitboxToEntity.isCollisionWithRect(tower.getMainHitbox()))
					{
						m_canPlaceShadowEntity = false;
						m_shadowEntity.setMainColour(Globals::Color::shadowColorOff);
						return;
					}

				m_canPlaceShadowEntity = true;
				m_shadowEntity.setMainColour(Globals::Color::shadowColorOn);
				return;
			}
		}
	}

	m_canPlaceShadowEntity = false;
	m_shadowEntity.setMainColour(Globals::Color::shadowColorOff);

}
void Game::updateEnemies()
{
	sf::Time elapsedTime = m_updateClock.getElapsedTime();

	/* Check if we should spawn 1 more enemy */
	if (elapsedTime > m_spawnRate)
	{
		/* Update our spawn rate */
		float spawnRate = Globals::defaultEnemySpawnRate - (Globals::enemySpawnCurve * m_noOfEnemiesKilled);
		if (spawnRate < Globals::minSpawnRate)
			spawnRate = 1;

		m_spawnRate = sf::seconds(spawnRate);


		/* Reset our timer */
		m_updateClock.restart();

		/* Get the type of enemy */
		bool shouldSpawn;
		int16_t enemyType;

		do
		{
			/* Get a random type of enemy */
			enemyType = rand() % Globals::EnemyTypes::noOfEnemyTypes;

			/* Should it spawn? If not, keep looking */
			shouldSpawn = rand() % 100 / Globals::EnemyTypes::enemyObjects[enemyType].chanceToSpawn + 1 == 1 ? true : false;

		} while (!shouldSpawn);

		/* Spawn the enemy and set it's starting movement direction and position, health, color */
		Enemy newEnemy(m_currentLevel.startingPoint.getCenter(), Globals::enemySize, Globals::EnemyTypes::enemyObjects[enemyType].moveSpeed, sf::Vector2i(0, 0), Globals::EnemyTypes::enemyObjects[enemyType].hp);
		newEnemy.setMovementDirection(getMovementDirection(m_currentLevel.startingPoint.getExit()));
		newEnemy.setColour(Globals::EnemyTypes::enemyObjects[enemyType].color);

		Logger logger(std::cout);
		logger.log("Spawn enemy", Logger::Level::Info);

		/* Push our enemy into the array */
		m_enemyArray.push_back(std::make_shared<Enemy>(newEnemy));
	}

	updateEnemiesPositions();
	updateEnemiesMovements();
}
void Game::updateEnemiesMovements()
{
	/* Go through the enemyArray and update the movement of each of them according with what intersections they collide with */
	for (int i = 0; i < m_enemyArray.size(); ++i)
	{
		/* Check if our enemy is dead */
		if (m_enemyArray[i]->getHealth() <= 0)
		{
			/* Reward the player based on how powerful the enemy was */
			m_gold += (Globals::defaultGoldRewardAmount * m_enemyArray[i]->getStartingHealth()) / Globals::EnemyTypes::enemyObjects[Globals::enemyType::defaultType].hp;
			m_shop.setGold(m_gold);

			/* Remove the enemy from the array */
			m_enemyArray.erase(m_enemyArray.begin() + i);
			m_noOfEnemiesKilled++;

			if (m_noOfEnemiesKilled >= Globals::winConditionEnemyKillCount)
				m_gameIsWon = true;

			break;
		}

		/* Check if our is in the center of our intersection - and at the same time upate the collision */
		if (updateEnemyCollision(m_enemyArray[i]))
		{
			/* Check if it's actually the ending point */
			if (m_enemyArray[i]->isCollision(m_currentLevel.endingPoint))
			{
				/* Remove the enemy from the array */
				m_enemyArray.erase(m_enemyArray.begin() + i);

				/* Substract damage from our hp */
				m_lifePoints -= Globals::enemyDamage;
				m_shop.setLifePoints(m_lifePoints);
			}
		}

	}
}
bool Game::updateEnemyCollision(std::shared_ptr<Enemy> enemy)
{
	/* Check for a collision */
	for (int i = 0; i < m_currentLevel.intersectionArray.size(); ++i)
	{
		/* Check if it's already collided or not */
		if (enemy->isCollision(m_currentLevel.intersectionArray[i]) && !enemy->isInCollision())
		{
			enemy->setIsDuringCollision(true);
		}
		else if (enemy->isCollision(m_currentLevel.intersectionArray[i]))
		{
			/* If the enemy is in the center of the intersection */
			if (m_currentLevel.intersectionArray[i].getICenter().x == enemy->getICenter().x
				&&  m_currentLevel.intersectionArray[i].getICenter().y == enemy->getICenter().y)
			{
				enemy->setMovementDirection(getMovementDirection(m_currentLevel.intersectionArray[i].getExit()));
				enemy->setIsDuringCollision(false);
				return true;
			}
		}
	}

	return false;
}
void Game::OccupyTower()
{
	if (m_towerOccupied = true && (sf::Keyboard::isKeyPressed(sf::Keyboard::E)))
	{

	}
}
sf::Vector2i Game::getMovementDirection(const short entrance) const
{
	/* North */
	if (entrance == Globals::Cardinals::North)
		return Globals::MovementDirections::North;
	/* South */
	else if (entrance == Globals::Cardinals::South)
		return Globals::MovementDirections::South;
	/* East */
	else if (entrance == Globals::Cardinals::East)
		return Globals::MovementDirections::East;
	/* West */
	else if (entrance == Globals::Cardinals::West)
		return Globals::MovementDirections::West;
}
void Game::handleShopPressed(const sf::Vector2f& mousePos)
{

	switch (m_shop.selectedItem)
	{
	case Shop::item::towerItem:
	{
		/* Buy the tower if we can */
		if (!buyTower(Globals::defaultTowerPrice))
			return;

		Tower newTower(mousePos, Globals::towerSize, Globals::defaultTowerDamage);
		m_towerArray.push_back(newTower);

		break;
	}
	case Shop::item::speedyTowerItem:
	{
		/* Buy the tower if we can */
		if (!buyTower(Globals::speedyTowerPrice))
			return;

		Tower newTower(mousePos, Globals::towerSize, Globals::defaultTowerDamage);
		newTower.setFireRate(Globals::towerSpeedyFireRate);

		m_towerArray.push_back(newTower);

		break;
	}
	case Shop::item::powerfullTowerItem:
	{
		/* Buy the tower if we can */
		if (!buyTower(Globals::powerfullTowerPrice))
			return;

		Tower newTower(mousePos, Globals::towerSize, Globals::powerfullTowerDamage);
		newTower.setBulletSize(Globals::powerfullTowerBulletSize);
		m_towerArray.push_back(newTower);

		break;
	}
	default:
		break;
	}
}
void Game::readLevel(const std::string& level)
{
	//Level newLevel(level);
	//m_currentLevel = &newLevel;
}

bool Game::buyTower(const int price)
{
	/* Make sure we can afford the item */
	if (m_gold < price)
	{
		m_shop.isSelected = false;
		Logger logger(std::cout);
		logger.log("You can't afford to pay for that", Logger::Level::Warning);
		return false;
	}

	m_gold -= price;
	m_shop.setGold(m_gold);
	return true;


}