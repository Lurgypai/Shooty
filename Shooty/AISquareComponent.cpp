#include "stdafx.h"
#include "AISquareComponent.h"
#include "EntityPlayer.h"
#include "EnemyBase.h"

void AISquareComponent::update(sf::RenderWindow & window, EnemyBase* entity, Player* player, const Arena& arena, SoundManager& sounds) {
	sf::Vector2f delta = sf::Vector2f(player->getSprite()->getPosition().x - entity->getSprite()->getPosition().x, player->getSprite()->getPosition().y - entity->getSprite()->getPosition().y);
	float angle = std::atan2f(delta.y, delta.x) * (180 / 3.1415926535898);
	float distance = sqrt(pow(delta.x, 2) + pow(delta.y, 2));
	entity->setAngle(angle);
	float moveAngle;

	if (distance > 80) {
		moveAngle = angle;
	}
	else {
		moveAngle = 180 + angle;
	}



	static bool seeded = false;

	if (!seeded) {
		srand(time(0));
		seeded = true;
	}

	float timeDelta = entity->getClock()->getElapsedTime().asSeconds();
	
	if (timeDelta > entity->moveCooldown()) {
		entity->getClock()->restart();
		entity->setCanMove(!entity->getCanMove());
		if (entity->getCanMove()) {
			angleModifier = (rand() % 11) - 5;
			entity->getShootClock()->restart();
			entity->setCanShoot(true);
		}
	}

	if (entity->getCanMove()) {
		moveAngle = moveAngle + angleModifier;
			entity->setXVelocity(entity->getXVelocity() + (float)std::cos(moveAngle / (180 / 3.1415926535898)) * entity->getSpeed() * ((float)1 / 60));
			entity->setYVelocity(entity->getYVelocity() + (float)std::sin(moveAngle / (180 / 3.1415926535898)) * entity->getSpeed() * ((float)1 / 60));
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
		if (entity->getXVelocity() < 0.00125 && entity->getXVelocity() > - 0.00125) {
			entity->setXVelocity(0);
		}
		if (entity->getYVelocity() < 0.00125 && entity->getYVelocity() > -0.00125) {
			entity->setYVelocity(0);
		}
		if (entity->getCanShoot()) {
			if (entity->getShootClock()->getElapsedTime().asSeconds() > 0.5) {
				entity->getShootClock()->restart();
				sounds.playSound("enemy.squareshoot");
				entity->shoot();
			}
		}
	}

	if (arena.contains(sf::Vector2f(entity->getSprite()->getPosition().x + entity->getXVelocity(), entity->getSprite()->getPosition().y + entity->getYVelocity())))
	{
		entity->getSprite()->move(entity->getXVelocity(), entity->getYVelocity());
	}
	else {
		entity->setXVelocity(-entity->getXVelocity() / 4);
		entity->setYVelocity(-entity->getYVelocity() / 4);
	}

	for (int i = 0; i != entity->MAX_BULLETS; i++) {
		if (entity->getBullets()->at(i)->getExists()) {
			entity->getBullets()->at(i)->update(window, arena, player);
		}
	}
	if (entity->checkHit(player, 4)) {
		entity->damage(1);
		sounds.playSound("player.hit");
		player->restoreDash();
	}
	if (entity->getHealth() <= 0 ) {
		player->incrementMultiplierCounter(1);
		player->score(10);
		entity->setDead(true);
	}
}
