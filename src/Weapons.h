#ifndef WEAPONS_H
#define WEAPONS_H

#include <SFML/Graphics.hpp>
//#include "Hero.h"

class Hero;
class Entity;

class Weapons
{
protected:
	float damage;
	float range;
	float crit_chance;
	float crit_multiplier;
	float damage_fluctuation;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Clock cooldown;
public:
	Weapons();
	virtual ~Weapons();
	virtual void render(sf::RenderWindow& window);
	virtual void update(bool);
	float dmgRandomizer(float fluctuation);
	float critical(float multiplier);
	void setPosition(float, float);
	virtual bool attack();
	//Accessors
	const float getX()
	{ return Sprite.getPosition().x; }
	const float getY()
	{ return Sprite.getPosition().y; }
	const float getDamage() { return damage; }
	const sf::FloatRect getAttackRect(bool);
};


#endif
