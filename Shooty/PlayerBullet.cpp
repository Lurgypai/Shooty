#include "stdafx.h"
#include "PlayerBullet.h"
#include "FileNotFoundException.h"
#include "Configuration.h"
#include "Arena.h"

PlayerBullet::PlayerBullet(void)
{
}

PlayerBullet::PlayerBullet(float angle, sf::Vector2f position) {
	load();
	getSprite()->setPosition(position);
	setExists(false);
}

float PlayerBullet::getXVelocity() {
	return xVelocity;
}

float PlayerBullet::getYVelocity() {
	return yVelocity;
}

void PlayerBullet::setXVelocity(float xVelocity_) {
	xVelocity = xVelocity_;
}

void PlayerBullet::setYVelocity(float yVelocity_) {
	yVelocity = yVelocity_;
}

void PlayerBullet::setAngle(float angle_) {
	angle = angle_;
}

void PlayerBullet::load() {
	if (!getTexture()->loadFromFile("resources/images/entity/bullet/bullet.png")) {
		FileNotFoundException e;
		throw(e);
	}
	getSprite()->setTexture(*getTexture());
	setSpeed(350);
}

void PlayerBullet::update(sf::RenderWindow & window, const Arena& arena, Player* player) {
	setXVelocity((float)std::cos(angle / (180 / 3.1415926535898)) * speed() * ((float) 1 / 60));
	setYVelocity((float)std::sin(angle / (180 / 3.1415926535898)) * speed() * ((float) 1 / 60));
	getSprite()->move(xVelocity, yVelocity);
	if (!arena.contains(getSprite()->getPosition()))
		setExists(false);
}
