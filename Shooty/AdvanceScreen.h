#pragma once
#include "stdafx.h"
#include "EntityPlayer.h"
#include "InBetween.h"

class AdvanceScreen : public InBetween {
public:
	enum State {
	LEVEL, COUNTDOWN, GO, EXIT
};

private:
	sf::Text level;
	sf::Text lvlnumber;
	sf::Text number;
	sf::Text go;

	State state;
public:
	void load();
	void update(Player& player, int levelNumber, SoundManager& sounds);
	void draw(sf::RenderWindow& window);
	State getState();
	void reset();
};
