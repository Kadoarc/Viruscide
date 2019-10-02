#include "UnMoveableEntity.h"



UnMoveableEntity::UnMoveableEntity(const sf::Vector2f& position, const sf::Vector2f& size)
	: Entity(position, size)
{}

UnMoveableEntity::~UnMoveableEntity()
{
}

