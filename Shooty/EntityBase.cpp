#include "stdafx.h"
#include "EntityBase.h"
#include "Arena.h"
#include "FileNotFoundException.h"

Entity::Entity(float maxX_, float maxY_, float speed_, const std::string& fileLocation) : speed(speed_), angle(0), maxXVelocity(maxX_), maxYVelocity(maxY_),  xVelocity(0), yVelocity(0) {
	if (!texture.loadFromFile(fileLocation)) {
		FileNotFoundException e;
		throw e;
	}

	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	dead = false;
}

Entity::~Entity(void) {}

sf::Sprite* Entity::getSprite() {
	return &sprite;
}

sf::Texture * Entity::getTexture() {
	return &texture;
}

float Entity::getXVelocity() {
	return xVelocity;
}

float Entity::getYVelocity() {
	return yVelocity;
}

float Entity::getMaxXVelocity() {
	return maxXVelocity;
}

float Entity::getMaxYVelocity()
{
	return maxYVelocity;
}

float Entity::getAngle() {
	return angle;
}

float Entity::getSpeed() {
	return speed;
}

bool Entity::getDead() {
	return dead;
}

std::string Entity::getId() {
	return id;
}

void Entity::setXVelocity(float xVelocity_) {
	xVelocity = xVelocity_;
}

void Entity::setYVelocity(float yVelocity_) {
	yVelocity = yVelocity_;
}

void Entity::setMaxXVelocity(float maxX_) {
	maxXVelocity = maxX_;
}

void Entity::setMaxYVelocity(float maxY_) {
	maxYVelocity = maxY_;
}

void Entity::setSpeed(float speed_) {
	speed = speed_;
}

void Entity::setAngle(float angle_) {
	angle = angle_;
}

void Entity::setDead(bool dead_) {
	dead = dead_;
}

void Entity::setPosition(const sf::Vector2f & pos) {
	sprite.setPosition(pos);
}
