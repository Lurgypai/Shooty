#pragma once
#include "stdafx.h"
#include "Arena.h"

class Player;

class Bullet {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	int maxAmount;
	int moveSpeed;
	float angle;
	bool exists;
public:
	sf::Sprite* getSprite();
	virtual sf::Drawable* getDrawable();
	virtual sf::Transformable* getTransformable();
	sf::Texture* getTexture();
	bool getExists();

	void setExists(bool exists_);

	int max();
	int speed();

	void setSpeed(int moveSpeed_);
	void setAngle(float angle_);

	virtual void load()=0;
	virtual void update(sf::RenderWindow& window, const Arena& arena, Player* player) =0;
};