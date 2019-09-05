#pragma once
#include "Widget.h"

namespace gui
{
	class Label : public widget
	{
	public:
		Label();
		void handleEvent(const sf::Event & event) override;
		void update(sf::Time dt) override;

		void setText(const sf::Text &text);
		void setTexture(const sf::Texture &texture);
		void setFont(const sf::Font & font);
		bool isMouseOver(const sf::Vector2i &mouse);

	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates &states) const;
		void centreText();

		sf::Sprite sprite;
		sf::Text text;


	};

}


