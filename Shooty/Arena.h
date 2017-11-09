#pragma once
#include "stdafx.h"
#include "Polygon.h"

class Arena {
private:
	Polygon arena;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Arena(void);
	bool contains(const sf::Vector2f& point) const;
	Polygon* getArena();
	void draw(sf::RenderWindow& window_);
	void load();
};
