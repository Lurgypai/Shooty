#pragma once
#include "stdafx.h"
#include "BulletBase.h"
#include "EntityPlayer.h"

class TriangleBullet : public Bullet {
private:
	float xVelocity;
	float yVelocity;
	float rotateSpeed;
public:
	TriangleBullet(void);
	TriangleBullet(float angle, sf::Vector2f position);
	float getXVelocity();
	float getYVelocity();

	void setXVelocity(float xVelocity_);
	void setYVelocity(float yVelocity_);

	void load();
	void update(sf::RenderWindow& window, const Arena& arena, Player* player);
};
