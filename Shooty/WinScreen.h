#pragma once
#include "stdafx.h"
#include "EntityPlayer.h"

class WinScreen {
public:
	WinScreen();
	~WinScreen();
	void update(const Player& player, SoundManager& sounds);
	void draw(sf::RenderWindow& window);
	void reset();
private:
	sf::Texture bg;
	sf::Sprite bgSprite;

	sf::Font font;
	sf::Text points;

	int displayPoints;
};