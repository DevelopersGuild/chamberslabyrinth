#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity
{
protected:
	sf::Texture Texture;
	sf::Sprite Sprite;

	int HP;
	bool isAlive;
	float Speed;
	float SpeedMultiplier;

	void jump();
	void left();
	void right();
public:
	Entity();
	void update();
	void render(sf::RenderWindow& window);

	// Accessors
	const float getX()
	{
		return Sprite.getPosition().x;
	}
	const float getY()
	{
		return Sprite.getPosition().y;
	}
	const sf::FloatRect getCollisionRect()
	{
		return Sprite.getGlobalBounds();
	}
	const bool getAlive()
	{
		return isAlive;
	}
	const int getHP()
	{
		return HP;
	}
};

#endif