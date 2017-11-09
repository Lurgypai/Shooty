#pragma once
#include "stdafx.h"
#include "Arena.h"
#include "SoundManager.h"

class Entity {
public:
	sf::Sprite* getSprite();
	sf::Texture* getTexture();
	float getXVelocity();
	float getYVelocity();
	float getMaxXVelocity();
	float getMaxYVelocity();
	float getAngle();
	float getSpeed();
	bool getDead();
	std::string getId();

	void setXVelocity(float xVelocity_);
	void setYVelocity(float yVelocity_);
	void setMaxXVelocity(float maxX_);
	void setMaxYVelocity(float maxY_);
	void setSpeed(float speed_);
	void setAngle(float angle_);
	void setDead(bool dead_);
	void setPosition(const sf::Vector2f& pos);

	virtual void load() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
protected:
	sf::Sprite sprite;
	sf::Texture texture;

	float xVelocity;
	float yVelocity;
	float maxXVelocity;
	float maxYVelocity;
	float speed;
	float angle;

	bool dead;

	std::string id;

	Entity(float maxX, float maxY, float speed, const std::string& fileLocation);
	virtual ~Entity(void);
};
