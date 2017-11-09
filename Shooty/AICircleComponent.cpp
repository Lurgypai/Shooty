#include "stdafx.h"
#include "AICircleComponent.h"
#include "EntityPlayer.h"
#include "EnemyBase.h"
#include "CircleBullet.h"

void AICircleComponent::update(sf::RenderWindow & window, EnemyBase* entity, Player* player, const Arena& arena, SoundManager& sounds) {
	sf::Vector2f delta = sf::Vector2f(player->getSprite()->getPosition().x - entity->getSprite()->getPosition().x, player->getSprite()->getPosition().y - entity->getSprite()->getPosition().y);
	float deltaAngle = (float)std::atan2f(delta.y, delta.x) * (180 / 3.1415926535898);
	float distance = sqrt(pow(delta.x, 2) + pow(delta.y, 2));

	float timeDelta = entity->getClock()->getElapsedTime().asSeconds();

	static bool seeded = false;

	if (!seeded) {
		srand(time(0));
		seeded = true;
	}

	if (timeDelta > entity->moveCooldown()) {
		entity->getClock()->restart();
		entity->setCanMove(!entity->getCanMove());
		if (entity->getCanMove()) {
			entity->setAngle((rand() % 361) + 1);
			sounds.playSound("enemy.circleshoot");
			entity->shoot();
		}
	}


	if (entity->getCanMove()) {
		entity->setXVelocity(entity->getXVelocity() + (float)std::cos(entity->getAngle() / (180 / 3.1415926535898)) * entity->getSpeed() * ((float)1 / 60));
		entity->setYVelocity(entity->getYVelocity() + (float)std::sin(entity->getAngle() / (180 / 3.1415926535898)) * entity->getSpeed() * ((float)1 / 60));
		if (entity->getXVelocity() > entity->getMaxXVelocity()) {
			entity->setXVelocity(entity->getMaxXVelocity());
		}
		if (entity->getYVelocity() > entity->getMaxYVelocity()) {
			entity->setYVelocity(entity->getMaxYVelocity());
		}
		if (entity->getXVelocity() < -entity->getMaxXVelocity()) {
			entity->setXVelocity(-entity->getMaxXVelocity());
		}
		if (entity->getYVelocity() < -entity->getMaxYVelocity()) {
			entity->setYVelocity(-entity->getMaxYVelocity());
		}
	}
	else {
		entity->setXVelocity(entity->getXVelocity() - (entity->getXVelocity() * entity->getSpeed()  * ((float)1 / 60)));
		entity->setYVelocity(entity->getYVelocity() - (entity->getYVelocity() * entity->getSpeed()  * ((float)1 / 60)));
		if (entity->getXVelocity() < 0.00125 && entity->getXVelocity() > -0.00125) {
			entity->setXVelocity(0);
		}
		if (entity->getYVelocity() < 0.00125 && entity->getYVelocity() > -0.00125) {
			entity->setYVelocity(0);
		}
	}

	if (arena.contains(sf::Vector2f(entity->getSprite()->getPosition().x + entity->getXVelocity(), entity->getSprite()->getPosition().y + entity->getYVelocity())))
	{
		entity->getSprite()->move(entity->getXVelocity(), entity->getYVelocity());
	}
	else {
		entity->setXVelocity(0);
		entity->setYVelocity(0);
		entity->setAngle(-entity->getAngle());
	}
	
	if (entity->getBullets()->at(0)->getExists()) {
		entity->getBullets()->at(0)->update(window, arena, player);
	}
	if (entity->checkHit(player, 4.3)) {
		entity->damage(1);
		sounds.playSound("player.hit");
		player->restoreDash();
	}
	if (entity->getHealth() <= 0) {
		player->incrementMultiplierCounter(1);
		player->score(20);
		entity->setDead(true);
	}
}
