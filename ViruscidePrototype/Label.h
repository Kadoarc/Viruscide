#pragma once

#include "Widget.h"

namespace gui
{
	class Label : public widget
	{
	public:
		Label();

		void handleEvent(const sf::Event &event) override;
		void update(sf::Time dt) override;

		void setTexture(const sf::Texture &texture);
		void setText(const std::string &text);
		void setFont(const sf::Font &font);

		bool isMouseOver(const sf::Vector2i &mouse) const;
	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
		void centerText();

		sf::Sprite sprite;
		sf::Text text;
	};
}