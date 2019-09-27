#pragma once

#include "Widget.h"

namespace gui
{
	class Gui : public sf::Drawable
	{
	public:
		Gui();

		void addWidget(widget::Ptr widget);

		void removeWidgets();

		void handleWidgetsEvent(const sf::Event &event);
		void updateWidgets(sf::Time dt);

	private:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		std::vector<Widget::Ptr> widgets;
	};
}