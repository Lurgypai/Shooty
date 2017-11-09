#pragma once
#include "stdafx.h"
#include "InBetween.h"

//inbetween, renders and adds points
class PointsScreen : public InBetween {
public:
	enum State {
		ENEMY, HEALTH, TOTAL, EXIT
	};

	State getState() const;

	void load();
	void update(Player& player, int levelNumber, SoundManager& sounds);
	void draw(sf::RenderWindow& window);
	void reset();
private:


	int points;
	int healthNum;
	int timeLeft;

	int enemyPoints;
	int timePoints;
	float healthMultiplier;
	int totalPoints;

	State state;
	sf::Sprite bg;
	sf::Texture bgtexture;
	sf::Text kills;
	sf::Text time;
	sf::Text health;
	sf::Text total;
	sf::Text kPoints;
	sf::Text tPoints;
	sf::Text hPoints;
	sf::Text toPoints;
};

/*
on update:
if not in starting level (for now 0)
-ENEMY:
--display text
--every update add 1 point until reaching the total amount for enemies killed.
--then wait
-TIME
--display text
--give player poitns based of time left. Go to total.
--then wait
-HEALTH
display text
--multilpier based of remaining health
--then wait
-TOTAL
display text
--display total poitns earned
--save them (?)
-EXIT
--move to the advancer
*/