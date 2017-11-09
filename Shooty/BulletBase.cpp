#include "stdafx.h"
#include "BulletBase.h"

sf::Sprite * Bullet::getSprite() {
	return &sprite;
}

sf::Drawable * Bullet::getDrawable() {
	return &sprite;
}

sf::Transformable * Bullet::getTransformable() {
	return &sprite;
}

sf::Texture * Bullet::getTexture() {
	return &texture;
}

bool Bullet::getExists() {
	return exists;
}

void Bullet::setExists(bool exists_) {
	exists = exists_;
}

int Bullet::max()
{
	return maxAmount;
}

int Bullet::speed() {
	return moveSpeed;
}

void Bullet::setSpeed(int moveSpeed_) {
	moveSpeed = moveSpeed_;
}

void Bullet::setAngle(float angle_) {
	angle = angle_;
}
