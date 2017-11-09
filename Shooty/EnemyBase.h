#pragma once
#include "stdafx.h"
#include "EntityBase.h"
#include "Arena.h"
#include "EntityPlayer.h"
#include "IAIComponent.h"
#include "BulletBase.h"

class EnemyBase : public Entity {
public:

	enum Type {
		SQUARE, TRIANGLE, CIRCLE
	};

	EnemyBase(float x, float y, int health_, int speed, float maxX, float maxY, float walkCooldown_, bool canMove_, Type ai_, Type bullet, int maxBullets, std::string fileLocation_);
	~EnemyBase();

	int getHealth() const;
	bool getCanMove() const;
	bool getCanShoot() const;
	sf::Clock* getClock();
	sf::Clock* getShootClock();
	std::vector<std::shared_ptr<Bullet>>* getBullets();

	float moveCooldown() const;

	void setCanMove(bool canMove_);
	void setCanShoot(bool canShoot_);
	void setCooldown(float moveCooldown_);

	void setHealth(int health);

	void damage(int amount);
	bool checkHit(Player* player);
	bool checkHit(Player* player, const float& radius);

	void shoot();
	void update(sf::RenderWindow& window, const Arena& arena, Player& player, SoundManager& sounds);
	void draw(sf::RenderWindow& window);
	void load();


	const int MAX_BULLETS;
protected:
	int health;
	bool dashedInto;

	float walkCooldown;

	bool canMove;
	bool canShoot;
	sf::Clock clock;
	sf::Clock shootClock;

	std::shared_ptr<AIComponent> ai;

	std::vector < std::shared_ptr<Bullet> > bullets;
};

//update no longer virtual
//deleted other update
//move framedelay to the ai's