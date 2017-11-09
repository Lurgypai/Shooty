#include "stdafx.h"
#include "EntityBoss.h"
#include "AIHexaComponent.h"
Boss::Boss(float x_, float y_, int health_) : EnemyBase(x_, y_, health_, 0, 0.0, 0.0, 0.0, false, Type::SQUARE, Type::SQUARE, 0, "resources/images/entity/enemy/boss.png"),
attackState(SQUARE), squareShot(7, SquareBullet(0, sf::Vector2f(0, 0))), circleShot(2, CircleBullet(0, sf::Vector2f(0, 0))), triangleShot(6, TriangleBullet(0, sf::Vector2f(0, 0))),
attacks(0), maxSquareAttacks(7), maxCircleAttacks(2), maxTriangleAttacks(4), velocity(7.0), stillDashing(false), dashHit(false) {
	ai = std::shared_ptr<AIComponent>(new AIHexaComponent());
}

Boss::~Boss() {
}

void Boss::reset() {
	health = 50;
	sprite.setPosition(240, 50);
	stillDashing = false;
	canShoot = false;
	for (SquareBullet bullet : squareShot) {
		bullet.setExists(false);
	}
	for (CircleBullet bullet : circleShot) {
		bullet.setExists(false);
	}
	for (TriangleBullet bullet : triangleShot) {
		bullet.setExists(false);
	}
}

void Boss::attack(SoundManager& sounds) {
	if (clock.getElapsedTime().asSeconds() >= 1.5f) {
		canShoot = true;
	}
	if (!canShoot) {
		return;
	}
	switch (attackState)
	{
	case Boss::SQUARE:
		for (std::vector<SquareBullet>::iterator i = squareShot.begin(); i != squareShot.end(); i++) {
			if (!i->getExists()) {
				i->setExists(true);
				i->getSprite()->setPosition(sprite.getPosition());
				i->setAngle(angle);
				sounds.playSound("enemy.squareshoot");
				break;
			}
		}

		attacks++;
		if (attacks == maxSquareAttacks) {
			attacks = 0;
			switchAttack();
			clock.restart();
			canShoot = false;
		}
		break;
	case Boss::TRIANGLE:
		for (std::vector<TriangleBullet>::iterator i = triangleShot.begin(); i != triangleShot.end(); i++) {
			if (!i->getExists()) {
				i->setExists(true);
				i->getSprite()->setPosition(sprite.getPosition());
				i->setAngle(angle);
				sounds.playSound("enemy.triangleshoot");
				break;
			}
		}

		attacks++;
		if (attacks == maxTriangleAttacks) {
			attacks = 0;
			switchAttack();
			clock.restart();
			canShoot = false;
		}
		break;
	case Boss::CIRCLE:
		for (std::vector<CircleBullet>::iterator i = circleShot.begin(); i != circleShot.end(); i++) {
			if (!i->getExists()) {
				i->setExists(true);
				i->getSprite()->setPosition(sprite.getPosition());
				i->setAngle(angle);
				sounds.playSound("enemy.circleshoot");
				break;
			}
		}

		attacks++;
		if (attacks == maxCircleAttacks) {
			attacks = 0;
			switchAttack();
			clock.restart();
			canShoot = false;
		}
		break;
	case Boss::DASH:
		if (stillDashing)
			return;
		else {
			attacks = 0;
			switchAttack();
			clock.restart();
			canShoot = false;
		}
		break;
	}
}

void Boss::draw(sf::RenderWindow & window) {
	window.draw(sprite);
	for (std::vector<SquareBullet>::iterator i = squareShot.begin(); i != squareShot.end(); i++) {
		if (i->getExists())
			window.draw(*(i->getSprite()));
	}
	for (std::vector<TriangleBullet>::iterator i = triangleShot.begin(); i != triangleShot.end(); i++) {
		if (i->getExists())
			window.draw(*(i->getSprite()));
	}
	for (std::vector<CircleBullet>::iterator i = circleShot.begin(); i != circleShot.end(); i++) {
		if (i->getExists())
			window.draw(*(i->getSprite()));
	}
}

std::vector<SquareBullet>* Boss::getSquareShot() {
	return &squareShot;
}

std::vector<TriangleBullet>* Boss::getTriangleShot() {
	return &triangleShot;
}

std::vector<CircleBullet>* Boss::getCircleShot() {
	return &circleShot;
}

bool Boss::isDashing() {
	return stillDashing;
}

void Boss::setDashing(bool isDashing) {
	stillDashing = isDashing;
}

bool Boss::canDashHit() {
	return dashHit;
}

void Boss::setCanDashHit(bool can) {
	dashHit = can;
}

float Boss::getDashVelocity() {
	return velocity;
}

float Boss::getDashAngle() {
	return dashAngle;
}

void Boss::switchAttack() {
	static bool seeded = false;

	if (!seeded) {
		srand(time(0));
		seeded = true;
	}

	attackState = static_cast<CurrentAttack>(rand() % 4);
	if (attackState == CurrentAttack::DASH) {
		stillDashing = true;
		dashAngle = angle;
		dashHit = true;
	}
}
