#pragma once

#include <functional>

#include "Widget.h"
#include "SoundManager.h"

namespace gui
{
	class Button : public widget
	{
	public:
		using Callback = std::function<void()>;

		enum Type
		{
			Normal = 0,
			Selected,
			Pressed
		};

		explicit Button(SoundManager &soundManager);

		void setCallback(Callback callback);
		void setTexture(const sf::Texture &texture);
		void setText(const std::string &text);
		void setFont(const sf::Font &font);

		void handleEvent(const sf::Event &event) override;
		void update(sf::Time dt) override;

	private:
		void select();
		void deselect();
		void activate();
		void deactivate();

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
		void changeTexture(Type type);
		void centerText();

		SoundManager &soundManager;

		Callback   callback;
		sf::Sprite sprite;
		sf::Text   text;

		bool selected;
		bool toggle;
	};
}