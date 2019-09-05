#pragma once
#include "Widget.h"
namespace gui
{
	class GUI : public sf::Drawable
	{
	public:
		GUI();
		~GUI();
		void addWidget(widget::Ptr widget);
		void removeWidgets();
		void handleWidgetEvents(const sf::Event &event);
		void updateWidgets(sf::Time dt);

	private:
		void draw(sf::RenderTarget &target, sf::RenderStates states);
		std::vector<widget::Ptr> widgets;
	};

}

