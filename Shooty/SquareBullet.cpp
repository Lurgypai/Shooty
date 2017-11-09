#include "stdafx.h"
#include "SquareBullet.h"
#include "FileNotFoundException.h"
#include "Configuration.h"
#include "Arena.h"

SquareBullet::SquareBullet(float angle, sf::Vector2f position) {
	load();
	getSprite()->setPosition(position);
	setExists(false);
}

float SquareBullet::getXVelocity() {
	return xVelocity;
}

float SquareBullet::getYVelocity() {
	return yVelocity;
}

void SquareBullet::setXVelocity(float xVelocity_) {
	xVelocity = xVelocity_;
}

void SquareBullet::setYVelocity(float yVelocity_) {
	yVelocity = yVelocity_;
}

void SquareBullet::load() {
	if (!getTexture()->loadFromFile("resources/images/entity/bullet/squarebullet.png")) {
		FileNotFoundException e;
		throw(e);
	}
	getSprite()->setTexture(*getTexture());
	setSpeed(150);
}

void SquareBullet::update(sf::RenderWindow & window, const Arena& arena, Player* player) {
	setXVelocity((float)std::cos(angle / (180 / 3.1415926535898)) * speed() * ((float)1 / 60));
	setYVelocity((float)std::sin(angle / (180 / 3.1415926535898)) * speed() * ((float)1 / 60));
	getSprite()->move(xVelocity, yVelocity);


	if (player->getSprite()->getGlobalBounds().contains(sprite.getPosition())) {
		player->damage(1);
		exists = false;
	}

	if (!arena.contains(getSprite()->getPosition()))
		exists = false;
}
