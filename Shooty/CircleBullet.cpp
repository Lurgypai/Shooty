#include "stdafx.h"
#include "CircleBullet.h"
#include "FileNotFoundException.h"
#include "Configuration.h"
#include "Arena.h"

CircleBullet::CircleBullet(float angle, sf::Vector2f position) {
	load();
	getSprite()->setPosition(position);
	setExists(false);
}

float CircleBullet::getExpandSpeed() const {
	return expandingSpeed;
}

bool CircleBullet::getCanHit() const {
	return canHit;
}

void CircleBullet::setExpandSpeed(float speed_) {
	expandingSpeed = speed_;
}

void CircleBullet::setCanHit(bool canHit_) {
	canHit = canHit_;
}

sf::CircleShape * CircleBullet::getSprite() {
	return &circle;
}

sf::CircleShape * CircleBullet::getDrawable() {
	return &circle;
}

sf::CircleShape * CircleBullet::getTransformable() {
	return &circle;
}

void CircleBullet::load() {
	circle.setOrigin(circle.getGlobalBounds().width / 2, circle.getGlobalBounds().height / 2);
	circle.setPointCount(100);
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineThickness(-4);
	circle.setOutlineColor(sf::Color::White);
	circle.setRadius(1);
	expandingSpeed = 2;
}

void CircleBullet::update(sf::RenderWindow & window, const Arena& arena, Player* player) {
	circle.setOrigin(circle.getGlobalBounds().width / 2, circle.getGlobalBounds().height / 2);
	circle.setRadius(circle.getRadius() + expandingSpeed);



	if (circle.getRadius() > 500) {
		exists = false;
		canHit = true;
		circle.setRadius(1);
	}


	float bulletDistance = sqrt(pow(player->getSprite()->getPosition().x - circle.getPosition().x, 2) +
		pow(player->getSprite()->getPosition().y - circle.getPosition().y, 2));

		if (bulletDistance < circle.getRadius() && bulletDistance > circle.getRadius() - 6) {
			if (canHit) {
				player->damage(1);
				canHit = false;
			}
		}
}
