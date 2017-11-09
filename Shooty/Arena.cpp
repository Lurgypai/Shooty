#include "stdafx.h"
#include "Arena.h"
#include "Configuration.h"
#include "FileNotFoundException.h"

Arena::Arena(void) {}

bool Arena::contains(const sf::Vector2f & point) const {
	return arena.contains(point);
}

Polygon* Arena::getArena() {
	return &arena;
}

void Arena::draw(sf::RenderWindow& window_) {
	window_.draw(sprite);
}

void Arena::load() {
	if (!texture.loadFromFile("resources/images/arena.png")) {
		FileNotFoundException e;
		throw e;
	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	sf::Vertex x, y, z, a, b, c;
	x.position = sf::Vector2f(317.0, 1.0);
	y.position = sf::Vector2f(395.0, 135.0);
	z.position = sf::Vector2f(317.0, 269.0);
	a.position = sf::Vector2f(163.0, 269.0);
	b.position = sf::Vector2f(85.0, 135.0);
	c.position = sf::Vector2f(163.0, 1.0);
	x.color = sf::Color::Blue;
	y.color = sf::Color::Blue;
	z.color = sf::Color::Blue;
	a.color = sf::Color::Blue;
	b.color = sf::Color::Blue;
	c.color = sf::Color::Blue;
	std::vector<sf::Vertex> arena_;
	arena_.push_back(x);
	arena_.push_back(y);
	arena_.push_back(z);
	arena_.push_back(a);
	arena_.push_back(b);
	arena_.push_back(c);
	arena = Polygon(arena_);
}
