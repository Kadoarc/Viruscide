#include "GUI.h"

using namespace gui;

void gui::GUI::addWidget(widget::Ptr widget)
{
	widgets.push_back(widget);
}

void gui::GUI::removeWidgets()
{
	widgets.clear();
}

void gui::GUI::handleWidgetEvents(const sf::Event & event)
{
}

void gui::GUI::updateWidgets(sf::Time dt)
{
}

void gui::GUI::draw(sf::RenderTarget & target, sf::RenderStates states)
{
}
