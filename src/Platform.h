#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>

class Platform
{
private:
	sf::Vector2f pos;
	sf::Vector2f size;
	sf::RectangleShape rec;
public:
	Platform();
	Platform(sf::Vector2f nPos, sf::Vector2f nSize, int type);
	~Platform();

	// setters
	void setTexture(int type);
	void setSize(sf::Vector2f nSize);
	void setPosition(sf::Vector2f nPos);

	// getters
	const sf::Vector2f getPosition()
	{ return pos; }
	const sf::Vector2f getSize()
	{ return size; }
	const sf::FloatRect getCollisionRect()
	{ return rec.getGlobalBounds(); }

	void render(sf::RenderWindow &window);
};

#endif
