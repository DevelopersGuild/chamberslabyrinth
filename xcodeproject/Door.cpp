#include "Door.h"
#include "Hero.h"

Door::Door()
{
	isOpen = false;

	texture.loadFromFile("../assets/sprites/clossdoor.png");
	texture.setRepeated(true);
	sprite.setTexture(texture);
	sprite.setPosition(1260, 1290);

}

void Door::openDoor()
{
	isOpen = true;
	texture.loadFromFile("../assets/sprites/opendoor.png");
	sprite.setTexture(texture);
}

void Door::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}


Door::~Door()
{
}
