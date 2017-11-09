#include "stdafx.h"
#include "EntityManager.h"
#include "EnemyBase.h"

EntityManager::EntityManager(void) : boss(240, 50, 50) {
	boss.setDead(true);
}

EntityManager::~EntityManager(void) {
}

Player * EntityManager::getPlayer() const {
	return player;
}

std::vector<EnemyBase*> EntityManager::getEnemies()
{
	return enemies;
}

void EntityManager::setPlayer(Player& player_) {
	player = &player_;
}

void EntityManager::spawnBoss() {
	boss.setDead(false);
}

bool EntityManager::checkBossDead() {
	return boss.getDead();
}

void EntityManager::addEnemy(EnemyBase& enemy_) {
	enemies.push_back(&enemy_);
}

void EntityManager::update(sf::RenderWindow & window, const Arena& arena, SoundManager& sounds) {
	if (!player->getDead()) {
		player->update(window, arena, sounds);
	}
	if (!boss.getDead()) {
		boss.update(window, arena, *player, sounds);
	}
	for (std::vector<EnemyBase*>::const_iterator iter = enemies.begin(); iter != enemies.end();) {
		(*iter)->update(window, arena, *player, sounds);
		if ((*iter)->getDead()) {
			iter = enemies.erase(iter);
		}
		else {
			iter++;
		}
	}

}

void EntityManager::draw(sf::RenderWindow & window) {
	if (!player->getDead()) {
		player->draw(window);
	}
	if (!boss.getDead()) {
		boss.draw(window);
	}
	for (std::vector<EnemyBase*>::const_iterator iter = enemies.begin(); iter != enemies.end(); iter++) {
		(*iter)->draw(window);
	}
}

void EntityManager::load(Player& player_, User& user, SoundManager& sounds) {
	setPlayer(player_);
	player->load(user, sounds);
}

void EntityManager::reload() {
	for (std::vector<EnemyBase*>::const_iterator iter = enemies.begin(); iter != enemies.end(); iter++) {
		(*iter)->load();
	}
}

void EntityManager::reset() {
	enemies.clear();
	boss.reset();
}
