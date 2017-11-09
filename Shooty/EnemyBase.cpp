#include "stdafx.h"
#include "EnemyBase.h"
#include "FileNotFoundException.h"
#include "SquareBullet.h"
#include "TriangleBullet.h"
#include "CircleBullet.h"
#include "AISquareComponent.h"
#include "AITriangleComponent.h"
#include "AICircleComponent.h"

EnemyBase::EnemyBase(float x, float y, int health_, int speed, float maxX, float maxY, float walkCooldown_, bool canMove_, Type ai_, Type bullet, int maxBullets, std::string fileLocation_)
	: health(health_), walkCooldown(walkCooldown_), canMove(canMove_), MAX_BULLETS(maxBullets), dashedInto(false), Entity(maxX, maxY, speed, fileLocation_) {
	

	sprite.setPosition(sf::Vector2f(x, y));
	
	switch (ai_) {
	case Type::SQUARE: 
		ai= std::shared_ptr<AIComponent>(new AISquareComponent());
		break;
	case Type::TRIANGLE:
		ai = std::shared_ptr<AIComponent>(new AITriangleComponent());
		break;
	case Type::CIRCLE:
		ai = std::shared_ptr<AIComponent>(new AICircleComponent());
		break;
	}

	for (int i = 0; i != maxBullets; i++) {
		switch (bullet) {
		case Type::SQUARE:
			bullets.push_back(std::shared_ptr<SquareBullet>(new SquareBullet(0, sf::Vector2f(0, 0))));
			break;
		case Type::TRIANGLE:
			bullets.push_back(std::shared_ptr<TriangleBullet>(new TriangleBullet(0, sf::Vector2f(0, 0))));
			break;
		case Type::CIRCLE:
			bullets.push_back(std::shared_ptr<CircleBullet>(new CircleBullet(0, sf::Vector2f(0, 0))));
			break;
		}
	}
	xVelocity = 0;
	yVelocity = 0;

	dead = false;

}

EnemyBase::~EnemyBase(void) {
	bullets.clear();
}

int EnemyBase::getHealth() const {
	return health;
}

bool EnemyBase::getCanMove() const {
	return canMove;
}

bool EnemyBase::getCanShoot() const {
	return canShoot;
}

sf::Clock* EnemyBase::getClock() {
	return &clock;
}

sf::Clock * EnemyBase::getShootClock() {
	return &shootClock;
}

std::vector<std::shared_ptr<Bullet>>* EnemyBase::getBullets() {
	return &bullets;
}

float EnemyBase::moveCooldown() const {
	return walkCooldown;
}

void EnemyBase::setCanMove(bool canMove_) {
	canMove = canMove_;
}

void EnemyBase::setCanShoot(bool canShoot_) {
	canShoot = canShoot_;
}

void EnemyBase::setCooldown(float moveCooldown_) {
	walkCooldown = moveCooldown_;
}

void EnemyBase::setHealth(int health_) {
	health = health_;
}

void EnemyBase::damage(int amount) {
	health -= amount;
}

bool EnemyBase::checkHit(Player* player) {
	bool hit = false;
	for (int i = 0; i != Player::NUMBULLETS; i++) {
		if (player->getBullets()[i].getExists() && getSprite()->getGlobalBounds().contains(player->getBullets()[i].getSprite()->getPosition())) {
			hit = true;
			player->getBullets()[i].setExists(false);
			break;
		}
	}
	return hit;
}

bool EnemyBase::checkHit(Player * player, const float& radius) {
	bool hit = false;
	for (int i = 0; i != Player::NUMBULLETS; i++) {
		PlayerBullet* bullet = &(player->getBullets()[i]);
		if (bullet->getExists()) {
			sf::Vector2f bulletDelta = sf::Vector2f(getSprite()->getPosition().x - bullet->getSprite()->getPosition().x, getSprite()->getPosition().y - bullet->getSprite()->getPosition().y);
			float distance = sqrt(pow(bulletDelta.x, 2) + pow(bulletDelta.y, 2));
			if (distance < radius) {
				hit = true;
				bullet->setExists(false);
				break;
			}
		}
	}

	sf::Vector2f playerDelta = sf::Vector2f(sprite.getPosition().x - player->getSprite()->getPosition().x, sprite.getPosition().y - player->getSprite()->getPosition().y);
	float distance = sqrt(pow(playerDelta.x, 2) + pow(playerDelta.y, 2));
	if (!dashedInto) {
		if (player->getInvulnerable()) {
			if (distance < radius + 2.0f) {
				dashedInto = true;
				hit = true;
				player->addMultiplier(0.1f);
			}
		}
	}
	else {
		if (distance > radius + 2.0f) {
			dashedInto = false;
		}
	}
	return hit;
}

void EnemyBase::shoot() {
	for (int i = 0; i != MAX_BULLETS; i++) {
		if (!bullets[i]->getExists()) {

			bullets[i]->setExists(true);
			bullets[i]->getTransformable()->setPosition(sprite.getPosition());
			bullets[i]->setAngle(angle);
			break;
		}
	}
}

void EnemyBase::update(sf::RenderWindow& window, const Arena& arena, Player& player, SoundManager& sounds) {
	if (!getDead()) {
		ai->update(window, this, &player, arena, sounds);
	}
}

void EnemyBase::draw(sf::RenderWindow & window) {
	window.draw(sprite);
	for (std::vector<std::shared_ptr<Bullet>>::const_iterator i = bullets.begin(); i != bullets.end(); i++) {
		if ((*i)->getExists())
		window.draw(*(*i)->getDrawable());
	}
}

void EnemyBase::load() {}
