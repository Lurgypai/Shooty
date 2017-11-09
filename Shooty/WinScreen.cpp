#include "stdafx.h"
#include "WinScreen.h"
#include "FileNotFOundException.h"

WinScreen::WinScreen() : displayPoints(0) {
	if (!bg.loadFromFile("resources/images/winner.png") & !font.loadFromFile("resources/fonts/m20.ttf")) {
		FileNotFoundException e;
		throw e;
	}
	bgSprite.setTexture(bg);
	bgSprite.setPosition(0, 0);

	points = sf::Text("", font, 192);
	points.setScale(.125, .125);

	points.setFillColor(sf::Color::Black);
	points.setOrigin(points.getLocalBounds().left + points.getLocalBounds().width, points.getLocalBounds().top);
	points.setPosition(259, 94);
}

WinScreen::~WinScreen() {}

void WinScreen::update(const Player & player, SoundManager & sounds) {
	if (displayPoints != player.getPoints()) {
		displayPoints++;
		points.setString(std::to_string(displayPoints));
		points.setOrigin(points.getLocalBounds().left + points.getLocalBounds().width, points.getLocalBounds().top);
		points.setPosition(259, 94);
	}
}

void WinScreen::draw(sf::RenderWindow & window) {
	window.draw(bgSprite);
	window.draw(points);
}

void WinScreen::reset() {
	displayPoints = 0;
}
