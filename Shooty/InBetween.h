#pragma once
#include "stdafx.h"
#include "EntityPlayer.h"

class InBetween {
protected:
	sf::Font font;
	bool start;
	sf::Clock clock;

public:
	virtual void load() =0;
	virtual void update(Player& player, int levelNumber, SoundManager& sounds) =0;
	virtual void draw(sf::RenderWindow& window) =0;
	virtual void reset() =0;
};
