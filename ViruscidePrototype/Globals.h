#pragma once

namespace Globals
{
	/* Intersection Stuff*/
	const int intersectionSize = 40;
	const bool intersectionBorder = true;
	const int intersectionOutLineThickness = 2;


	namespace Strings
	{
		const std::string lostGame = "You lost :(\n";
		const std::string wonGame = "You won!\n";
		const std::string backToMenu = "Press any key to continue!\n";
	}

	namespace Color
	{
		const sf::Color towerColor = sf::Color(255, 255, 255, 50);
		const sf::Color bulletColor = sf::Color(255, 255, 255);
		const sf::Color shadowColorOn = sf::Color(210, 210, 210, 100);
		const sf::Color shadowColorOff = sf::Color(244, 66, 66, 100);
		const sf::Color drawableZoneColor = sf::Color(244, 50, 50, 60);
		const sf::Color enemyColor = sf::Color(255, 0, 0, 255);
		const sf::Color speedyEnemyColor = sf::Color(255, 100, 0, 255);
		const sf::Color buffEnemyColor = sf::Color(255, 60, 0, 255);
		const sf::Color tankEnemyColor = sf::Color(80, 0, 0, 255);
		const sf::Color playerColor = sf::Color(80, 0, 0, 255);
		const sf::Color player2Color = sf::Color(80, 80, 0, 255);
		//const sf::Color defaultButtonColor = sf::Color(244, 50, 50, 200);
		const sf::Color defaultButtonColor = sf::Color(28, 124, 84, 200);
		const sf::Color intersectionColor = sf::Color(70, 160, 100, 60);
		const sf::Color backgroundColor = sf::Color(31, 44, 56, 255);
		const sf::Color panelColor = sf::Color(185, 177, 158, 10);

	}

	const enum Cardinals {

		North,
		South,
		East,
		West
	};


	const sf::Vector2f playerSize(50, 50);
	/* Enemy stuff */
	const sf::Vector2f enemySize(40, 40);
	const int defaultEnemySpawnRate = 8;
	const float enemySpawnCurve = 0.05f;
	const float minSpawnRate = 1.0f;
	const int defaultGoldRewardAmount = 5;

	namespace MovementDirections
	{
		const sf::Vector2i North(0, -1);
		const sf::Vector2i South(0, 1);
		const sf::Vector2i East(1, 0);
		const sf::Vector2i West(-1, 0);
	}

	namespace EnemyTypes
	{
		const int noOfEnemyTypes = 4;

		struct EnemyObject
		{
			EnemyObject(const int hp, const float moveSpeed, const int chanceToSpawn, const sf::Color color)
				: moveSpeed(moveSpeed), hp(hp), chanceToSpawn(chanceToSpawn), color(color)
			{}

			const float moveSpeed;
			const int hp;
			const int chanceToSpawn;
			const sf::Color color;
		};

		const EnemyObject enemyObjects[noOfEnemyTypes] =
		{
			{100, 0.8f, 60, Color::enemyColor},
			{80, 1.0f, 5, Color::speedyEnemyColor},
			{200, 0.8f, 40, Color::buffEnemyColor},
			{400, 0.6f, 10, Color::tankEnemyColor}
		};
	}

	const enum enemyType {

		defaultType,
		speedType,
		buffType,
		tankType
	};


	/* Bullet Stuff */
	const float defaultBulletSpeed = 10.0;
	const sf::Vector2f defaultBulletSize(5, 5);


	/* Tower Stuff */
	const sf::Vector2f towerSize(240, 240);
	const sf::Vector2f towerMainSize(40, 40);
	const bool enableTowerRange = false;
	const unsigned int defaultTowerPrice = 40;
	const unsigned int speedyTowerPrice = 60;
	const unsigned int powerfullTowerPrice = 120;
	const sf::Vector2f powerfullTowerBulletSize(8, 8);

	const int defaultTowerDamage = 10;
	const int powerfullTowerDamage = 20;
	const int speedyTowerDamage = 10;
	const float defaultTowerFireRate = 1.0f;
	const float towerSpeedyFireRate = 0.5f;
	const float powerfullTowerFireRate = 0.5f;

	/* Shop Stuff */
	const sf::Vector2f shopItemSize(200, 100);
	const int startingGoldAmount = 100;

	const int rasterLeft = 10;
	const int rasterTop = 80;
	const int itemSpacingHeight = 5;

	/* Shadow Stuff */

	const int32_t enemyDamage = 1;
	const int32_t startingPlayerHp = 10;
	const float frameRate = 1.0f / 60.f;


	/* Panel stuff */
	const sf::Vector2f panelSize = sf::Vector2f(200, 1000);
	const sf::Vector2f panelCenterPosition = sf::Vector2f(1100, 500);
	const sf::Vector2f panelIntersectionSize = sf::Vector2f(60, 60);
	const sf::Vector2f panelButtonSize = sf::Vector2f(80, 30);
	const sf::Vector2f panelButtonDefaultOffset = sf::Vector2f(0, 45);
	const std::int8_t panelIntersectionDefaultOffset = -20;
	const std::int16_t panelDefaultTextXOffset = -100;
	const std::int16_t panelDefaultTextYOffset = -200;



	/* Aplication stuff */
	const uint32_t winConditionEnemyKillCount = 5;
	const sf::Vector2f windowSize = sf::Vector2f(1200, 1000);


	/*Main menu stuff*/

	const sf::Vector2f mainMenuButtonSize = sf::Vector2f(250, 40);

	/*Level selector stuff*/
	const sf::Vector2f levelSelectorButtonSize = sf::Vector2f(400, 100);


	/* Button Stuff */
	namespace Fonts
	{
		const std::string arial = "..\\Res\\Fonts\\arial.ttf";
		const std::string kenVector = "..\\Res\\Fonts\\kenvector_future.ttf";
		const std::string kenVector_thin = "..\\Res\\Fonts\\kenvector_future_thin.ttf";

		const std::string defaultFont = kenVector;
	}

	namespace TextSize
	{
		const uint32_t small = 16;
		const uint32_t big = 60;
		const uint32_t normal = 24;
	}

}