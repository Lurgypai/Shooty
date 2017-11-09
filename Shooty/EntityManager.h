#pragma once
#include "stdafx.h"
#include "EntityPlayer.h"
#include "Arena.h"
#include "EnemyBase.h"
#include "EntityBoss.h"

class EntityManager {
private:
	Player* player;
	Boss boss;
	std::vector<EnemyBase*> enemies;
public:
	EntityManager(void);
	~EntityManager(void);
	Player* getPlayer() const;
	std::vector<EnemyBase*> getEnemies();

	void setPlayer(Player& player_);
	void spawnBoss();
	bool checkBossDead();
	void addEnemy(EnemyBase& enemy_);

	void update(sf::RenderWindow& window, const Arena& arena, SoundManager& sounds);
	void draw(sf::RenderWindow& window);
	void load(Player& player_, User& user, SoundManager& sound);
	void reload();
	void reset();
};
