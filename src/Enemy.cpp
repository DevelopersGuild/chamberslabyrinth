#include "Enemy.h"
#include "Constants.h"
#include "Game.h"
#include <iostream>

Enemy::Enemy()
{
	Freeze.restart().asSeconds();
	is_alive_ = true;
	heroDetected = false;
	patrol_right = true;
	isFrozen = false;
	wasPaused = true;
	patrol_pause = 0.0; //? sec pause
	collisionNum = 0;
	if (faceRight)
		Sprite.setScale(-1.f, 1.f);
	knockBackDuration = 0.1;
	backing = 0;
}

void Enemy::chaseHero()
{
	// Detection
	if (heroDetection(Game::getHero()))
		onHeroDetected(Game::getHero());
	// Check if alive
	if (HP <= 0)
		is_alive_ = false;
}

void Enemy::left()
{
	faceRight = false;
	velocity.x = (velocity.x + 3* -speed) / 4;
}

void Enemy::right()
{
	faceRight = true;
	velocity.x = (velocity.x + 3*speed) / 4;
}

bool Enemy::heroDetection(Hero* hero)
{
	if ((getX() - hero->getX()) <= ENEMY_DETECTION_RADIUS && (hero->getX() - getX()) <= ENEMY_DETECTION_RADIUS && (getY() - hero->getY()) <= ENEMY_DETECTION_RADIUS)
	{
		heroDetected = true;
		return true;
	}
	else
	{
		heroDetected = false;
		return false;
	}
}

void Enemy::onHeroDetected(Hero* hero)
{
	 if ((getX() - hero->getX()) > 0)
	{
		faceRight = false;
	}
	else
	{
		faceRight = true;
	}
}

float Enemy::onHit(float dmg)
{
	//std::cout << "attacked";
	float dmgDealt = 0;

	if (dmg > armor)
		dmgDealt = (dmg - armor / 4);
	else
		dmgDealt = rand() % 10;

	HP = HP - dmgDealt;
	return dmgDealt;
}

void Enemy::freeze()
{
	Freeze.restart().asSeconds();
	if (!isFrozen)
		isFrozen = true;
}

void Enemy::knockBack(float seconds)
{
	if (backing != 0)
	{
		if (backing == 'l')
		{
			velocity.x = -speed * seconds * seconds * 1000;
			Sprite.move(8 * velocity.x, 0.f);
		}
		else if (backing == 'r')
		{
			velocity.x = speed * seconds * seconds * 1000;
			Sprite.move(8 * velocity.x, 0.f);
		}
		else
		{
			velocity.x = speed * seconds * seconds * 1000;
			Sprite.move(8 * velocity.x, 0.f);
		}
		knockBackDuration -= seconds;
	}
	else
	{
	}
	if (knockBackDuration < 0)
	{
		backing = 0;
		knockBackDuration = 0.1;
	}
}

void Enemy::areaPatrol(float deltaTime)
{
	if (speedMultiplier != 1)
		speedMultiplier = 1;
	if (patrol_pause > 0)
	{
		if (getX() >= patrol_origin + PATROL_RADIUS)
		{
			if (patrol_right)//on the right edge of patrol boundary
				patrol_right = false;
		}

		else if (getX() <= patrol_origin - PATROL_RADIUS)
		{
			if (!patrol_right)//on the left edge of patrol boundary
				patrol_right = true;
		}
		patrol_pause -= deltaTime;
	}
	else if (getX() <= patrol_origin + PATROL_RADIUS && getX() >= patrol_origin - PATROL_RADIUS)
	{//within patrol boundary
		if (patrol_right)
			right();
		else
			left();
		wasPaused = false;
	}
	else //outside patrol boundary
	{
		if (!wasPaused)
		{
			patrol_pause = 3.0;
			wasPaused = true;
		}
		if (getX() >= patrol_origin + PATROL_RADIUS)
		{
			if (patrol_right)
				patrol_right = false;
			left();
		}
		else
		{
			if (!patrol_right)
				patrol_right = true;
			right();
		}
	}
}
