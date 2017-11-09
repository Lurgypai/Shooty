#pragma once
#include "stdafx.h"
#include "BulletBase.h"

class PlayerBullet : public Bullet {
private:
	float xVelocity;
	float yVelocity;
	float angle;

public:
	PlayerBullet(void);
	PlayerBullet(float angle, sf::Vector2f position);
	float getXVelocity();
	float getYVelocity();

	void setXVelocity(float xVelocity_);
	void setYVelocity(float yVelocity_);
	void setAngle(float angle_);

	void load();
	void update(sf::RenderWindow& window, const Arena& arena, Player* player);
};
