#include "Enemies.h"
#include "Enemy1.h"
#include "Constants.h"
#include <ctime>

Enemy1::Enemy1()
{
	// Load Enemies texture, assign to sprite, set starting sprite dimensions
	Texture.loadFromFile("../assets/sprites/magebaddie.png");
	Sprite.setTexture(Texture);
	Sprite.setOrigin(32, 128);
	Sprite.setPosition(1280, 1360);

	// Initialize basic Enemies stats
	HP = ENEMY1_BASE_HP;
	SpeedMultiplier = 1;
	Speed = ENEMY1_BASE_SPEED * SpeedMultiplier;
	damage = ENEMY1_DAMAGE;
	isAlive = true;
	armor = ENEMY1_ARMOR;

	srand(time(0));
}

void Enemy1::update(float time)
{
	Enemies::chaseHero();
}