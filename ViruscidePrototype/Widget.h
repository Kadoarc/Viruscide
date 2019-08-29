#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

namespace gui
{
	class widget : public  sf::Drawable, public sf::Transformable, private sf::NonCopyable
	{
	public:
		using Ptr = std::shared_ptr<widget>;

		widget() = default;
		virtual ~widget() = default;
		virtual void handleEvent(const sf::Event & event) = 0;
		virtual void update(sf::Time dt) = 0;
	};

}
