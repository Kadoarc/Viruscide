#pragma once
#include <SFML/Graphics.hpp>
class TileMap :public sf::Drawable
{
public:
	explicit TileMap(float tileSize, float tileWorldSize);
	void loadFromCSV(const std::string &filename);

	void setTexture(const sf::Texture &texture);

private:
	void addTileVertices(int x, int y, sf::Vector2f position);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	std::vector<int> mapValues;
	sf::VertexArray vertexArray;

	const sf::Texture *texture;

	float tileSize;
	float tileWorldSize;


};

