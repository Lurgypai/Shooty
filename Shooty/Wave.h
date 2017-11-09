#pragma once
#include "stdafx.h"
#include "EnemyBase.h"
#include "EntityManager.h"

class Wave {
private:
	std::vector<std::shared_ptr<EnemyBase>> enemies;
	sf::Clock spawnClock;
	std::vector<std::shared_ptr<EnemyBase>>::const_iterator currentEnemy;
	bool started;
	bool completed;
	float SPAWNDELAY = .33f;
public:
	Wave(void);
	~Wave(void);
	std::vector<std::shared_ptr<EnemyBase>>* getEnemies();
	void addEnemy(EnemyBase::Type type, const sf::Vector2f& pos);
	void spawnWave(EntityManager* manager);
	bool getCompleted();
	void setCompleted(bool completed_);
};