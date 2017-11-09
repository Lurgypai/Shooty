#pragma once
#include "stdafx.h"
#include "EnemyBase.h"
#include "TriangleBullet.h"
#include "CircleBullet.h"
#include "SquareBullet.h"

class Boss : public EnemyBase {
public:
	Boss(float x_, float y_, int health_);
	~Boss();
	void reset();
	void attack(SoundManager& sounds);
	void draw(sf::RenderWindow& window);

	std::vector<SquareBullet>* getSquareShot();
	std::vector<TriangleBullet>* getTriangleShot();
	std::vector<CircleBullet>* getCircleShot();

	bool isDashing();
	void setDashing(bool isDashing);
	bool canDashHit();
	void setCanDashHit(bool can);

	float getDashVelocity();
	float getDashAngle();

private:
	enum CurrentAttack {
		SQUARE, TRIANGLE, CIRCLE, DASH
	};

	void switchAttack();

	CurrentAttack attackState;
	std::vector<SquareBullet> squareShot;
	std::vector<TriangleBullet> triangleShot;
	std::vector<CircleBullet> circleShot;

	int attacks;
	int maxSquareAttacks;
	int maxCircleAttacks;
	int maxTriangleAttacks;

	float velocity;
	float dashAngle;
	bool stillDashing;
	bool dashHit;
};