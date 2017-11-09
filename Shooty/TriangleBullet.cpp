#include "stdafx.h"
#include "TriangleBullet.h"
#include "FileNotFoundException.h"
#include "Configuration.h"
#include "Arena.h"

TriangleBullet::TriangleBullet(float angle, sf::Vector2f position) : rotateSpeed(17){
	load();
	getSprite()->setPosition(position);
	setExists(false);
}

float TriangleBullet::getXVelocity() {
	return xVelocity;
}

float TriangleBullet::getYVelocity() {
	return yVelocity;
}

void TriangleBullet::setXVelocity(float xVelocity_) {
	xVelocity = xVelocity_;
}

void TriangleBullet::setYVelocity(float yVelocity_) {
	yVelocity = yVelocity_;
}

void TriangleBullet::load() {
	if (!getTexture()->loadFromFile("resources/images/entity/bullet/trianglebullet.png")) {
		FileNotFoundException e;
		throw(e);
	}
	getSprite()->setTexture(*getTexture());
	setSpeed(200);
}

void TriangleBullet::update(sf::RenderWindow & window, const Arena& arena, Player* player) {
	sf::Vector2f delta = sf::Vector2f(player->getSprite()->getPosition().x - getSprite()->getPosition().x, player->getSprite()->getPosition().y - getSprite()->getPosition().y);
	float deltaAngle = std::atan2f(delta.y, delta.x) * (180 / 3.1415926535898);

	if (deltaAngle < 0)
		deltaAngle += 360;

	float oppositeAngle = deltaAngle + 180;

	if (oppositeAngle > 360)
		oppositeAngle -= 360;

	if (deltaAngle < 180 && (angle > deltaAngle && angle < oppositeAngle)) 
		angle -= (angle - deltaAngle) / rotateSpeed;
	
	if (deltaAngle > 180 && angle > deltaAngle) 
		angle -= (angle - deltaAngle) / rotateSpeed;
	
	if (deltaAngle > 180 &&	angle < oppositeAngle) 
		angle -= (360 - deltaAngle + angle) / rotateSpeed;
	

	if (deltaAngle < 180 && angle < deltaAngle) 
		angle += (deltaAngle - angle) / rotateSpeed;
	
	if (deltaAngle < 180 && angle > oppositeAngle) 
		angle += ((360 - angle) + deltaAngle) / rotateSpeed;         
	

	if	(deltaAngle > 180 && (angle < deltaAngle && angle > oppositeAngle)) 
		angle += (deltaAngle - angle) / rotateSpeed;
	

	if (angle > 360)
		angle -= 360;

	if (angle < 0)
		angle += 360;

	float maxAngle = deltaAngle + .5;
	float minAngle = deltaAngle - .5;

	if (minAngle < 0)
		minAngle += 360;

	if (maxAngle > 360)
		maxAngle -= 360;

	if (angle > minAngle && angle < maxAngle) {
		angle = deltaAngle;
	}

	getSprite()->setRotation(angle);
	setXVelocity((float)std::cos(angle / (180 / 3.1415926535898)) * speed() * ((float)1 / 60));
	setYVelocity((float)std::sin(angle / (180 / 3.1415926535898)) * speed() * ((float)1 / 60));
	getSprite()->move(xVelocity, yVelocity);

	if (!arena.contains(getSprite()->getPosition()))
		setExists(false);


	if (player->getSprite()->getGlobalBounds().contains(sprite.getPosition())) {
		//sounds.playSound("enemy.rockethit");
		player->damage(1);
		exists = false;
	}
}