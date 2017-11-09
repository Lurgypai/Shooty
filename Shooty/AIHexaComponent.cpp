#include "stdafx.h"
#include "AIHexaComponent.h"
#include "EntityPlayer.h"
#include "EnemyBase.h"
#include "EntityBoss.h"

void AIHexaComponent::update(sf::RenderWindow & window, EnemyBase * entity, Player * player, const Arena & arena, SoundManager & sounds) {
	sf::Vector2f delta = sf::Vector2f(player->getSprite()->getPosition().x - entity->getSprite()->getPosition().x, player->getSprite()->getPosition().y - entity->getSprite()->getPosition().y);
	float angle = std::atan2f(delta.y, delta.x) * (180 / 3.1415926535898);
	entity->setAngle(angle);

	Boss* boss = (Boss*)entity;

	if (boss->getShootClock()->getElapsedTime().asSeconds() >= 0.00833F) {
		boss->getShootClock()->restart();

		if (boss->isDashing()) {
			dashFrame++;
			float moveX = (boss->getDashVelocity() * (std::cos(boss->getDashAngle() * (3.1415926535898 / 180))));
			float moveY = (boss->getDashVelocity() * (std::sin(boss->getDashAngle() * (3.1415926535898 / 180))));
			float distance = std::sqrt(std::pow(delta.x, 2) + std::pow(delta.y, 2));
			if (distance <= 46.0 && boss->canDashHit()) {
				player->damage(2);
				boss->setCanDashHit(false);
			}
			if (arena.contains(sf::Vector2f(boss->getSprite()->getPosition().x + moveX, boss->getSprite()->getPosition().y + moveY))) {
				boss->getSprite()->move(moveX, moveY);
			}
			if (dashFrame == dashFrames) {
				dashFrame = 0;
				boss->setDashing(false);
			}
		}

		if (attackTime != attackWait) {
			attackTime++;
		}
		else {
			boss->attack(sounds);
			attackTime = 0;
		}
		if(boss->checkHit(player, 46.0)) {
			boss->damage(1);
			player->restoreDash();
			sounds.playSound("player.hit");
		}

		if (boss->getHealth() <= 0) {
			player->incrementMultiplierCounter(1);
			player->score(500);
			boss->setDead(true);
		}
	}
	
	for (std::vector<SquareBullet>::iterator i = boss->getSquareShot()->begin(); i != boss->getSquareShot()->end(); i++) {
		if (i->getExists()) {
			i->update(window, arena, player);
		}
	}
	for (std::vector<TriangleBullet>::iterator i = boss->getTriangleShot()->begin(); i != boss->getTriangleShot()->end(); i++) {
		if (i->getExists()) {
			i->update(window, arena, player);
		}
	}
	for (std::vector<CircleBullet>::iterator i = boss->getCircleShot()->begin(); i != boss->getCircleShot()->end(); i++) {
		if (i->getExists()) {
			i->update(window, arena, player);
		}
	}
}
