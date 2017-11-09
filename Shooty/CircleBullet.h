#pragma once
#include "stdafx.h"
#include "BulletBase.h"
#include "EntityPlayer.h"

class CircleBullet : public Bullet {
private:
	bool canHit;
	float expandingSpeed;
	sf::CircleShape circle;
public:
	CircleBullet(void);
	CircleBullet(float angle, sf::Vector2f position);

	float getExpandSpeed() const;
	bool getCanHit() const;
	void setExpandSpeed(float speed_);
	void setCanHit(bool canHit_);

	sf::CircleShape* getSprite();
	sf::CircleShape* getDrawable();
	sf::CircleShape* getTransformable();

	void load();
	void update(sf::RenderWindow& window, const Arena& arena, Player* player);
};
