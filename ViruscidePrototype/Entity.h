#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"

/* Created Entity class for game objects */

class Entity : public sf::Drawable
{
public:
	virtual ~Entity() {};

	bool operator == (const Entity& otherEntity);

	Entity();
	Entity(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Texture& texture, const sf::Vector2u& noOfFrames);
	Entity(const sf::Vector2f& position, const sf::Vector2f& size);
	Entity(float xPos, float yPos, const sf::Vector2f& size, const float speed);


	sf::RectangleShape getHitbox() const;
	sf::Sprite getSprite() const;
	sf::Vector2f getPosition() const;
	sf::Vector2i getICenter() const;
	sf::Vector2f getCenter() const;


	int32_t getWidth() const;
	int32_t getHeight() const;

	void setCenterPosition(const sf::Vector2f& newPosition);
	void setPosition(const sf::Vector2f& newPosition);
	void setXYPosition(float x, float y);
	void setSize(const sf::Vector2f& size);
	void setColour(const sf::Color& newColor);

	sf::RectangleShape getCollision(const Entity& otherEntity) const;

	bool isCollision(const Entity& otherEntity) const;
	bool isCollisionWithRect(const sf::RectangleShape& hitBox) const;
	bool isCollisonWithPoint(const sf::Vector2f & point) const;

	bool isVisible() const;
	void setVisible(const bool visible);

protected:

	bool visible = true;
	sf::RectangleShape hitbox;
	sf::Sprite sprite;
	sf::Texture* texture;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};