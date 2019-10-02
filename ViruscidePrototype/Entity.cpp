#include "Entity.h"


bool Entity::operator==(const Entity & otherEntity)
{
	return this->hitbox.getPosition().x == otherEntity.hitbox.getPosition().x &&
		this->hitbox.getPosition().y == otherEntity.hitbox.getPosition().y &&
		this->hitbox.getSize().x == otherEntity.hitbox.getSize().x &&
		this->hitbox.getSize().y == otherEntity.hitbox.getSize().y;
}

Entity::Entity()
{
	//is empty
}

Entity::Entity(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Texture& texture, const sf::Vector2u& noOfFrames)
{
	setSize(size);
	setCenterPosition(position);
	setColour(sf::Color::Green);

	*this->texture = texture;
}

Entity::Entity(const sf::Vector2f& position, const sf::Vector2f& size)
{
	setSize(size);
	setCenterPosition(position);
	setColour(sf::Color::Green);

	this->texture = nullptr;
}

Entity::Entity(float xPos, float yPos, const sf::Vector2f & size, const float speed)
{

}



sf::RectangleShape Entity::getHitbox() const
{
	return this->hitbox;
}

sf::Sprite Entity::getSprite() const
{
	return this->sprite;
}

sf::Vector2f Entity::getPosition() const
{
	return this->hitbox.getPosition();
}

sf::Vector2i Entity::getICenter() const
{
	return sf::Vector2i(((int)getPosition().x * 2 + (int)getWidth()) / 2, ((int)getPosition().y * 2 + (int)getHeight()) / 2);
}

sf::Vector2f Entity::getCenter() const
{
	return { getPosition().x + getWidth() / 2, getPosition().y + getHeight() / 2 };
}





int32_t Entity::getWidth() const
{
	return this->hitbox.getSize().x;
}

int32_t Entity::getHeight() const
{
	return this->hitbox.getSize().y;
}

void Entity::setCenterPosition(const sf::Vector2f& newPosition)
{
	this->hitbox.setPosition(sf::Vector2f(newPosition.x - getWidth() / 2, newPosition.y - getHeight() / 2));
}

void Entity::setPosition(const sf::Vector2f & newPosition)
{
	this->hitbox.setPosition(newPosition);
}

void Entity::setXYPosition(float x, float y)
{
	this->hitbox.setPosition(x, y);

}



void Entity::setSize(const sf::Vector2f& size)
{
	hitbox.setSize(size);
}

void Entity::setColour(const sf::Color & newColor)
{
	this->hitbox.setFillColor(newColor);
}



bool Entity::isCollision(const Entity & otherEntity) const
{
	return isCollisionWithRect(otherEntity.getHitbox());
}

bool Entity::isCollisionWithRect(const sf::RectangleShape & hitBox) const
{
	/* AABB Collision: true = there is a collision */

	if (this->getPosition().x < hitBox.getPosition().x + hitBox.getSize().x &&
		this->getPosition().x + this->getWidth() > hitBox.getPosition().x &&
		this->getPosition().y < hitBox.getPosition().y + hitBox.getSize().y &&
		this->getPosition().y + this->getHeight() > hitBox.getPosition().y)
	{
		return true;
	}
	return false;
}




void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (visible)
		target.draw(this->hitbox);
}

sf::RectangleShape Entity::getCollision(const Entity & otherEntity) const
{
	/* Returns the collision area of 2 rects */
	sf::RectangleShape collision;
	collision.setSize(sf::Vector2f(0, 0));
	collision.setPosition(sf::Vector2f(0, 0));

	int32_t x1 = std::min(this->getWidth() + this->getPosition().x, otherEntity.getWidth() + otherEntity.getPosition().x);
	int32_t x2 = std::max(this->getPosition().x, otherEntity.getPosition().x);
	int32_t y1 = std::min(this->getHeight() + this->getPosition().y, otherEntity.getHeight() + otherEntity.getPosition().y);
	int32_t y2 = std::max(this->getPosition().y, otherEntity.getPosition().y);

	collision.setPosition(sf::Vector2f(std::min(x1, x2), std::min(y1, y2)));
	collision.setSize(sf::Vector2f(std::max(0, x1 - x2), std::max(0, y1 - y2)));

	return collision;
}


bool Entity::isCollisonWithPoint(const sf::Vector2f & point) const
{
	sf::RectangleShape mouseRect;
	mouseRect.setPosition(point);

	if (isCollisionWithRect(mouseRect))
		return true;
	return false;
}

bool Entity::isVisible() const
{
	return this->visible;
}

void Entity::setVisible(const bool visible)
{
	this->visible = visible;
}

