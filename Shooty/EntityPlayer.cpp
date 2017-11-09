#include "stdafx.h"
#include "EntityPlayer.h"
#include "EntityBase.h"
#include "FileNotFoundException.h"
#include "Configuration.h"
#include "Arena.h"

Player::Player(void) : Entity(3.0F, 3.0F, 1.0F, "resources/images/entity/player1.png") {
	if (!invulnerableTexture.loadFromFile("resources/images/entity/player2.png")) {
		FileNotFoundException e;
		throw e;
	}

	setPosition(sf::Vector2f(Config::getBaseWidth() / 2, Config::getBaseHeight() / 2));
	health = MAXHEALTH;
	shootDelay = 0;
	internalAngle = 0;
	velocity = 0;
	controlVelocity = 0;
	dashes = 0;
	dodgeAngle = 0.0;
	multiplier = 1.0f;
	multiplierCountUp = 0;
}

void Player::load(User& user_, SoundManager& sounds_) {
	for (int i = 0; i != Player::NUMBULLETS; i++) {
		bullets[i] = PlayerBullet(0, -sf::Vector2f(-1, -1));
		bullets[i].load();
	}
	user = &user_;
	sounds = sounds_;
	invulFrames = 0;
	dashWait = 5;
}

void Player::load(void) {}

void Player::update(sf::RenderWindow& window, const Arena& arena, SoundManager& sounds_) {
	if (dashes < 0)
		dashes = 0;
	if (dashes > TOTALDASHES)
		dashes = TOTALDASHES;
	if (dashWait > TOTALDASHWAIT)
		dashWait = TOTALDASHWAIT;
	if (invulnerable) {
		if (invulFrames < TOTALINVULFRAMES) {
			if (invulFrames == 0) {
				controlVelocity = .75;
			}
			sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			sf::Vector2f delta(mousePosition.x - sprite.getPosition().x, mousePosition.y - sprite.getPosition().y);
			float angle = std::atan2f(delta.y, delta.x) * (180 / 3.1415926535898);
			setAngle(angle);
			sprite.setRotation(angle);

			invulFrames++;
		}
		else {
			invulnerable = false;
			invulFrames = 0;
			dashWait = 0;
		}
	}
	else {
		if (dashWait < TOTALDASHWAIT)
			dashWait++;
		sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		sf::Vector2f delta(mousePosition.x - sprite.getPosition().x, mousePosition.y - sprite.getPosition().y);
		float angle = std::atan2f(delta.y, delta.x) * (180 / 3.1415926535898);
		setAngle(angle);
		sprite.setRotation(angle);

		while (internalAngle > 360) {
			internalAngle -= 360;
		}
		while (internalAngle < 0) {
			internalAngle += 360;
		}


		if (controlVelocity < 0) {
			controlVelocity = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			controlVelocity += ((float)speed * (float)1 / 60);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				controlAngle = 225;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				controlAngle = 315;
			}
			else {
				controlAngle = 270;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			controlVelocity += ((float)speed * (float)1 / 60);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				controlAngle = 135;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				controlAngle = 45;
			}
			else {

				controlAngle = 90;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			controlVelocity += ((float)speed * (float)1 / 60);
			controlAngle = 180;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			controlVelocity += ((float)speed * (float)1 / 60);
			controlAngle = 0;
		}
		else {
			controlVelocity = 0;
		}
	}

	float moveX = (controlVelocity * std::cos(controlAngle * (3.1415926535898 / 180)) + velocity * std::cos(internalAngle * (3.1415926535898 / 180)));
	float moveY = (controlVelocity * std::sin(controlAngle * (3.1415926535898 / 180)) + velocity * std::sin(internalAngle * (3.1415926535898 / 180)));

	internalAngle = std::atan2f(moveY, moveX) * (180 / 3.1415926535898);
	velocity = std::sqrt(std::pow(moveX, 2) + std::pow(moveY, 2));
	if (!invulnerable) {
		if (velocity > MAXVELOCITY)
			velocity = MAXVELOCITY;
		if (controlVelocity > MAXVELOCITY)
			controlVelocity = MAXVELOCITY;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			for (int i = 0; i != Player::NUMBULLETS; i++) {
				if (!bullets[i].getExists()) {
					if (shootDelay >= Player::FRAMEDELAY) {
						bullets[i].setExists(true);
						bullets[i].getSprite()->setPosition(sprite.getPosition());
						bullets[i].setAngle(getAngle());
						sounds_.playSound("player.shoot");
						shootDelay = 0;
					}
					break;
			}
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && !invulnerable && (dashWait == TOTALDASHWAIT) && dashes < TOTALDASHES) {
		dashes++;
		setInvulnerable(true);
	}

	if (getInvulnerable()) {
		sprite.setTexture(invulnerableTexture);
	}
	else {
		sprite.setTexture(*getTexture());
	}

	if (arena.contains(sf::Vector2f(sprite.getPosition().x + moveX, sprite.getPosition().y + moveY))) {
		sprite.move(moveX, moveY);
	}
	else {
		velocity = 0;
		xVelocity = 0;
		yVelocity = 0;
	}
	for (int i = 0; i != Player::NUMBULLETS; i++) {
		if (bullets[i].getExists()) {
			bullets[i].update(window, arena, this);
		}
	}
	if (getHealth() <= 0) {
		sounds_.playSound("player.death");
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

void Player::softReset() {
	setPosition(sf::Vector2f(Config::getBaseWidth() / 2, Config::getBaseHeight() / 2));
	shootDelay = 0;
	dodgeAngle = 0.0;
	dashWait = 5;
	invulFrames = 0;

	health = MAXHEALTH;
	dashes = 0;
	internalAngle = 0;
	controlAngle = 0;
	velocity = 0;
	controlVelocity = 0;
	dead = false;
	for (PlayerBullet bullet : bullets) {
		bullet.setExists(false);
	}
}

void Player::reset() {
	softReset();
	multiplier = 1.0f;
	points = 0;
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
	if (invulnerable_) {
		sounds.playSound("player.dash");
	}
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
		sounds.playSound("player.damaged");
		health-= damage;
		multiplier -= 0.1f;
		if (multiplier < 1.0f)
			multiplier = 1.0f;
		dashes = 0;
		if (health < 0) health = 0;
	}
}

void Player::score(int points_) {
	points += (points_ * multiplier);
}

void Player::restoreDash() {
	if (dashes > 0) {
		dashes--;
	}
}

void Player::addMultiplier(float addition) {
	multiplier += addition;
	if (multiplier >= maxmultiplier) {
		multiplier = maxmultiplier;
	}
}

float Player::getMultiplier() const {
	return multiplier;
}

void Player::incrementMultiplierCounter(int num) {
	multiplierCountUp+=num;
	if (multiplierCountUp == TOTALCOUNTUP) {
		addMultiplier(.1);
		multiplierCountUp = 0;
	}
}

int Player::getHealth() const {
	return health;
}

int Player::getPoints() const {
	return points;
}

int Player::getDashes() const {
	return dashes;
}

User* Player::getUser() {
	return user;
}

/*
x and y velocitie again
but use them to stor the magnitudes of the vectors. and angle = the angle to rotate to.
create a vector from these magnitudes and and angles. then add to the current position vector. store as new vector
*/