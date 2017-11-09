#include "stdafx.h"
#include "Level.h"

Level::Level(void) {}

Level::Level(int id_) : id(id_), totalWaves(0), currentWave(0), completed(false) {
}

void Level::addWave(const std::shared_ptr<Wave> wave) {
	waves.push_back(wave);
	totalWaves++;
}

std::shared_ptr<Wave> Level::getCurrentWave() {
	if (hasBoss && currentWave == totalWaves - 1) {
		return nullptr;
	}
	return waves.at(currentWave);
}

void Level::setCurrentWave(int wave_) {
	currentWave = wave_;
}

void Level::spawnWave(EntityManager* manager) {
	if (currentWave == totalWaves - 1 && hasBoss) {
		return;
	}
	waves.at(currentWave)->spawnWave(manager);
}

void Level::advanceWave(EntityManager* manager) {
	if (currentWave != totalWaves - 1) {
		currentWave++;
		if (currentWave == totalWaves - 1 && hasBoss) {
			manager->spawnBoss();
			return;
		}
		spawnWave(manager);

	} else {
			completed = true;
			return;
	}
}

bool Level::checkCurrentWaveComplete() {

	if (!started) {
		return false;
	}
	if (!hasBoss) {
		std::shared_ptr<Wave> wave = waves.at(currentWave);
		for (std::vector<std::shared_ptr<EnemyBase>>::const_iterator i = wave->getEnemies()->begin(); i != wave->getEnemies()->end(); i++) {
			if (!(*i)->getDead())
				return false;
		}
		return true;
	}
	else if (hasBoss && currentWave != totalWaves - 1) {
		std::shared_ptr<Wave> wave = waves.at(currentWave);
		for (std::vector<std::shared_ptr<EnemyBase>>::const_iterator i = wave->getEnemies()->begin(); i != wave->getEnemies()->end(); i++) {
			if (!(*i)->getDead())
				return false;
		}
	}
	else {
		return false;
	}
}

bool Level::isStarted() {
	return started;
}

bool Level::isComplete() {
	return completed;
}

void Level::setStarted(bool started_) {
	started = started_;
}

void Level::setComplete(bool completed_) {
	completed = completed_;
}

void Level::setHasBoss(bool hasBoss_) {
	hasBoss = hasBoss_;
	totalWaves++;
}

bool Level::getHasBoss() {
	return hasBoss;
}

bool Level::isFinalWave() {
	return currentWave == totalWaves - 1;
}

int Level::getId() const {
	return id;
}

