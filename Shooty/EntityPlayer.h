#pragma once
#include "stdafx.h"
#include "EntityBase.h"
#include "PlayerBullet.h"
#include "User.h"


class Player : public Entity {
public:
	const static int NUMBULLETS = 5;

	Player(void);

	void load(User& user, SoundManager& sounds_);
	void load(void);
	void update(sf::RenderWindow& window, const Arena& arena, SoundManager& manager);
	void draw(sf::RenderWindow& window);
	void softReset();
	void reset();

	bool getInvulnerable();
	sf::Texture* getInvulTexture();
	PlayerBullet* getBullets();

	void setInvulnerable(bool invulnerable_);
	void setInvulTexture(const sf::Texture& texture_);
	void setHealth(int health_);
	void setPoints(int points_);
	void setUser(User& user_);
	void damage(int damage);
	void score(int points_);
	void restoreDash();
	void addMultiplier(float addition);
	float getMultiplier() const;
	void incrementMultiplierCounter(int num);

	int getHealth() const;
	int getPoints() const;
	int getDashes() const;
	User* getUser();

private:
	const static int FRAMEDELAY = 20;
	int shootDelay;
	float dodgeAngle;
	const int TOTALINVULFRAMES = 15;
	int dashWait;
	const int TOTALDASHWAIT = 5;
	int invulFrames;
	PlayerBullet bullets[NUMBULLETS];

	int health;
	int points;
	int dashes;
	float internalAngle;
	float controlAngle;
	float velocity;
	float controlVelocity;
	float multiplier;
	float maxmultiplier = 2.0f;
	int multiplierCountUp;
	const int TOTALCOUNTUP = 5;
	const int TOTALDASHES = 3;
	const int MAXVELOCITY = 2;
	const int MAXHEALTH = 6;

	bool invulnerable;

	sf::Texture invulnerableTexture;

	User* user;
	SoundManager sounds;
};
