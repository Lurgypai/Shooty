#include "stdafx.h"
#include "EntityPlayer.h"
#include "EntityBase.h"
#include "FileNotFoundException.h"
#include "Configuration.h"
#include "Arena.h"

void Player::load(User& user_) {
	if (!getTexture()->loadFromFile("resources/images/entity/player.png", sf::IntRect(0, 0, 9, 7))) {
		FileNotFoundException e;
		throw e;
	}
	if (!invulnerableTexture.loadFromFile("resources/images/entity/player.png", sf::IntRect(9, 0, 9, 7))) {
		FileNotFoundException e;
		throw e;
	}
	getSprite()->setTexture(*getTexture());
	getSprite()->setOrigin(getSprite()->getGlobalBounds().width / 2, getSprite()->getGlobalBounds().height / 2);

	getSprite()->setPosition(Config::getBaseWidth() / 2, Config::getBaseHeight() / 2);

	setYVelocity(0);
	setXVelocity(0);
	setMaxXVelocity(3);
	setMaxYVelocity(3);
	setSpeed(1);
	setHealth(MAXHEALTH);
	setDead(false);

	internalAngle = 0;
	velocity = 0;

	for (int i = 0; i != Player::NUMBULLETS; i++) {
		bullets[i] = PlayerBullet(0, -sf::Vector2f(-1, -1));
		bullets[i].load();
	}
	user = &user_;
}

void Player::load(void) {}

void Player::update(sf::RenderWindow& window, const Arena& arena) {
	sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	sf::Vector2f delta(mousePosition.x - getSprite()->getPosition().x, mousePosition.y - getSprite()->getPosition().y);
	float angle = std::atan2f(delta.y, delta.x) * (180 / 3.1415926535898);
	setAngle(angle);
	getSprite()->setRotation(angle);

	while (internalAngle > 360) {
		internalAngle -= 360;
	}
	while (internalAngle < 0) {
		internalAngle += 360;
	}

	float newInternalAngle = 0;
	float newVelocity = 0;

	float moveX = 0;
	float moveY = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

		if (internalAngle > 274 || internalAngle <= 90) {
			newInternalAngle -= 5;
		}
		else if (internalAngle > 90 && internalAngle < 266) {
			newInternalAngle += 5;
		}
		else {
			newInternalAngle = 270;
		}
		newVelocity += ((float)getSpeed() * ((float)1 / 60));
		std::cout << "W: " << internalAngle << std::endl;

		moveX = (newVelocity * std::cos(newInternalAngle * (3.1415926535898 / 180)) + velocity * std::cos(internalAngle * (3.1415926535898 / 180)));
		moveY = (newVelocity * std::sin(newInternalAngle * (3.1415926535898 / 180)) + velocity * std::sin(internalAngle * (3.1415926535898 / 180)));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

		if (internalAngle > 94 && internalAngle <= 270) {
			newInternalAngle -= 7;
		}
		else if (internalAngle < 86 || internalAngle > 270) {
			newInternalAngle += 7;
		}
		else {
			newInternalAngle = 90;
		}
		newVelocity += ((float)getSpeed() * ((float)1 / 60));
		std::cout << "S: " << internalAngle << std::endl;

		moveX = (newVelocity * std::cos(newInternalAngle * (3.1415926535898 / 180)) + velocity * std::cos(internalAngle * (3.1415926535898 / 180)));
		moveY = (newVelocity * std::sin(newInternalAngle * (3.1415926535898 / 180)) + velocity * std::sin(internalAngle * (3.1415926535898 / 180)));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

		if (internalAngle > 184) {
			newInternalAngle -= 7;
		}
		else if (internalAngle < 176) {
			newInternalAngle += 7;
		}
		else {
			newInternalAngle = 180;
		}
		newVelocity += ((float)getSpeed() * ((float)1 / 60));
		std::cout << "A: " << internalAngle << std::endl;

		moveX = (newVelocity * std::cos(newInternalAngle * (3.1415926535898 / 180)) + velocity * std::cos(internalAngle * (3.1415926535898 / 180)));
		moveY = (newVelocity * std::sin(newInternalAngle * (3.1415926535898 / 180)) + velocity * std::sin(internalAngle * (3.1415926535898 / 180)));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

		if (internalAngle > 4 && internalAngle <= 180) {
			newInternalAngle -= 7;
		}
		else if (internalAngle < 356 && internalAngle > 180) {
			newInternalAngle += 7;
		}
		else {
			newInternalAngle = 0;
		}
		newVelocity += ((float)getSpeed() * ((float)1 / 60));
		std::cout << "D: " << internalAngle << std::endl;

		moveX = (newVelocity * std::cos(newInternalAngle * (3.1415926535898 / 180)) + velocity * std::cos(internalAngle * (3.1415926535898 / 180)));
		moveY = (newVelocity * std::sin(newInternalAngle * (3.1415926535898 / 180)) + velocity * std::sin(internalAngle * (3.1415926535898 / 180)));
	}

	if (newVelocity > MAXVELOCITY)
		newVelocity = MAXVELOCITY;


	internalAngle = std::atan2f(moveY, moveX) * (180 / 3.1415926535898);
	velocity = std::sqrt(std::pow(moveX, 2) + std::pow(moveY, 2));


	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		if (!getInvulnerable()) {
			for (int i = 0; i != Player::NUMBULLETS; i++) {
				if (!bullets[i].getExists()) {
					if (shootDelay >= Player::FRAMEDELAY) {
						bullets[i].setExists(true);
						bullets[i].getSprite()->setPosition(getSprite()->getPosition());
						bullets[i].setAngle(getAngle());
						shootDelay = 0;
					}
					break;
				}
			}
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
		setInvulnerable(true);
	}
	else {
		setInvulnerable(false);
	}

	if (getInvulnerable()) {
		getSprite()->setTexture(invulnerableTexture);
	}
	else {
		getSprite()->setTexture(*getTexture());
	}
	if (arena.contains(sf::Vector2f(getSprite()->getPosition().x + moveX, getSprite()->getPosition().y + moveY))) {
		getSprite()->move(moveX, moveY);
	}
	for (int i = 0; i != Player::NUMBULLETS; i++) {
		if (bullets[i].getExists()) {
			bullets[i].update(window, arena);
		}
	}
	if (getHealth() <= 0) {
		setDead(true);
	}
	if (shootDelay != FRAMEDELAY)
	shootDelay++;
}

void Player::draw(sf::RenderWindow & window) {
	window.draw(*getSprite());
	for (int i = 0; i != Player::NUMBULLETS; i++) {
		if (bullets[i].getExists()) {
			window.draw(*bullets[i].getSprite());
		}
	}
}

bool Player::getInvulnerable() {
	return invulnerable;
}

sf::Texture * Player::getInvulTexture() {
	return &invulnerableTexture;
}

PlayerBullet* Player::getBullets() {
	return bullets;
}

void Player::setInvulnerable(bool invulnerable_) {
	invulnerable = invulnerable_;
}

void Player::setInvulTexture(const sf::Texture & texture_) {
	invulnerableTexture = texture_;
}

void Player::setHealth(int health_) {
	health = health_;
}

void Player::setPoints(int points_) {
	points = points_; 
}

void Player::setUser(User& user_) {
	user = &user_;
}

void Player::damage(int damage) {
	if (!invulnerable) {
		//health -= damage;
		if (health < 0) health = 0;
	}

}

void Player::score(int points_) {
	points += points_;
}

int Player::getHealth() const {
	return health;
}

int Player::getPoints() const {
	return points;
}

User* Player::getUser() {
	return user;
}

/*
x and y velocitie again
but use them to stor the magnitudes of the vectors. and angle = the angle to rotate to.
create a vector from these magnitudes and and angles. then add to the current position vector. store as new vector
*/