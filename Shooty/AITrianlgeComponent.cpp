#include "stdafx.h"
#include "AITriangleComponent.h"
#include "EntityPlayer.h"
#include "EnemyBase.h"

void AITriangleComponent::update(sf::RenderWindow & window, EnemyBase* entity, Player* player, const Arena& arena, SoundManager& sounds) {
	sf::Vector2f delta = sf::Vector2f(player->getSprite()->getPosition().x - entity->getSprite()->getPosition().x, player->getSprite()->getPosition().y - entity->getSprite()->getPosition().y);
	float angle = std::atan2f(delta.y, delta.x) * (180 / 3.1415926535898);
	entity->setAngle(angle);
	entity->getSprite()->setRotation(angle);

	if (!(entity->getBullets()->at(0)->getExists())) {
		if (entity->getShootClock()->getElapsedTime().asSeconds() > 3) {
			entity->getShootClock()->restart();
			sounds.playSound("enemy.triangleshoot");
			entity->shoot();
		}
	}
	else {
		entity->getShootClock()->restart();
	}
	if (entity->getBullets()->at(0)->getExists()) {
		entity->getBullets()->at(0)->update(window, arena, player);
	}
	if (entity->checkHit(player, 4.0)) {
		entity->damage(1);
		sounds.playSound("player.hit");
		player->restoreDash();
	}
	if (entity->getHealth() <= 0) {
		player->incrementMultiplierCounter(1);
		player->score(25);
		entity->setDead(true);
	}
} //radius based damage
