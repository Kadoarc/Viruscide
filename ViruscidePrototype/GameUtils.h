#pragma once
namespace sf
{
	class RenderWindow;
	class Sprite;
	class Font;
}

class TextureManager;
class SoundManager;

namespace GameWorld
{
	struct LevelData
	{

	};

	struct GameData
	{

	};
}

namespace States
{
	struct Context
	{
		explicit Context(sf::RenderWindow &window
			, sf::Font &font
			, TextureManager &textureManager
			, SoundManager &soundManager
			, sf::Sprite &cursor
			, Score &score)

			: window(&window)
			, font(&font)
			, textureManager(&textureManager)
			, soundManager(&soundManager)
			, cursor(&cursor)
			, score(&score)
		{};

		sf::RenderWindow *window;
		sf::Font *font;
		TextureManager *textureManager;
		SoundManager *soundManager;
		sf::Sprite *cursor;
		Score *score;
	};
}