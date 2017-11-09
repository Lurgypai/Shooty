#pragma once
#include "stdafx.h"
#include "EntityManager.h"

class Gui {
private:
	sf::Font font;
	sf::Texture points;
	sf::Texture n0, n1, n2, n3,n4, n5, n6, n7, n8, n9;
	sf::Sprite pointsNum[6];
	sf::Sprite multiplierNum[2];
	sf::Sprite hbar;
	sf::Sprite pointsBar;
	sf::Sprite dashPip[3];
	sf::Texture dashPipTexture;
	std::vector<sf::Sprite> hearts;
	sf::Texture hbarTexture, heartFullTexture, heartHalfTexture;
	int renderHealth;
	int renderPoints;
	int renderDashes;
	int renderMultiplier;
public:
	void load();
	void draw(sf::RenderWindow& window);
	void update(const Player& player);
};
