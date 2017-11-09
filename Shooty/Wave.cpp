#include "stdafx.h"
#include "Wave.h"
#include "EnemyBase.h"

Wave::Wave(void) : started(false) {}

Wave::~Wave(void) {}

std::vector<std::shared_ptr<EnemyBase>>* Wave::getEnemies() {
	return &enemies;
}

void Wave::addEnemy(EnemyBase::Type type, const sf::Vector2f& pos) {
	std::shared_ptr<EnemyBase> enemy;
	switch (type) {
	case EnemyBase::SQUARE:
		enemy = std::shared_ptr<EnemyBase>(new EnemyBase(0.0f, 0.0f, 2, 6, 1.0f, 1.0f, 1.5f, false, EnemyBase::SQUARE, EnemyBase::SQUARE, 5, "resources/images/entity/enemy/square.png"));
		enemy->setPosition(pos);
		enemies.push_back(enemy);
		break;
	case EnemyBase::TRIANGLE:
		enemy = std::shared_ptr<EnemyBase>(new EnemyBase(0.0f, 0.0f, 3, 0, 0.0f, 0.0f, 3.0f, false, EnemyBase::TRIANGLE, EnemyBase::TRIANGLE, 1, "resources/images/entity/enemy/triangle.png"));
		enemy->setPosition(pos);
		enemies.push_back(enemy);
		break;
	case EnemyBase::CIRCLE:
		enemy = std::shared_ptr<EnemyBase>(new EnemyBase(0.0f, 0.0f, 2, 1, 0.5f, 0.5f, 3.0f, false, EnemyBase::CIRCLE, EnemyBase::CIRCLE, 1, "resources/images/entity/enemy/circle.png"));
		enemy->setPosition(pos);
		enemies.push_back(enemy);
		break;
	}
}

void Wave::spawnWave(EntityManager * manager) {
	if (!started) {
		currentEnemy = enemies.begin();
		(*currentEnemy)->getShootClock()->restart();
		(*currentEnemy)->getClock()->restart();
		manager->addEnemy(**currentEnemy);
		if (currentEnemy != enemies.end()) {
			currentEnemy++;
			spawnClock.restart();
		}
		started = true;
	}
		if (spawnClock.getElapsedTime().asSeconds() >= SPAWNDELAY) {
			spawnClock.restart();
			(*currentEnemy)->getShootClock()->restart();
			(*currentEnemy)->getClock()->restart();
			manager->addEnemy(**currentEnemy);
			if (currentEnemy != enemies.end()) {
			currentEnemy++;
		}
	}
	completed = currentEnemy == enemies.end();
}

bool Wave::getCompleted() {
	return completed;
}

void Wave::setCompleted(bool completed_) {
	completed = completed_;
}
