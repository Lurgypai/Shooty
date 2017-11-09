#include "stdafx.h"
#include "PointsScreen.h"
#include "FileNotFoundException.h"

PointsScreen::State PointsScreen::getState() const {
	return state;
}

void PointsScreen::load() {
	if (!bgtexture.loadFromFile("resources/images/gui/pointsbg.png") & !font.loadFromFile("resources/fonts/m20.ttf")) {
		FileNotFoundException e;
		throw e;
	}

	bg.setTexture(bgtexture);
	bg.setPosition(1, 1);

	kills = sf::Text("Kills", font, 192);
	kills.setScale(.125, .125);
	kills.setFillColor(sf::Color::White);
	kills.setPosition(80, 60);

	kPoints = sf::Text("", font, 192);
	kPoints.setScale(.125, .125);
	kPoints.setFillColor(sf::Color::White);
	kPoints.setPosition(200, 60);

	health = sf::Text("health", font, 192);
	health.setScale(.125, .125);
	health.setFillColor(sf::Color::White);
	health.setPosition(80, 100);

	hPoints = sf::Text("", font, 192);
	hPoints.setScale(.125, .125);
	hPoints.setFillColor(sf::Color::White);
	hPoints.setPosition(200, 100);

	total = sf::Text("total", font, 192);
	total.setScale(.125, .125);
	total.setFillColor(sf::Color::White);
	total.setPosition(80, 180);

	toPoints = sf::Text("", font, 192);
	toPoints.setScale(.125, .125);
	toPoints.setFillColor(sf::Color::White);
	toPoints.setPosition(200, 180);

	state = PointsScreen::State::ENEMY;
}

void PointsScreen::update(Player & player, int levelNumber, SoundManager& sounds) {
	if (state != EXIT) {
		if (!start) {
			clock.restart();
			start = true;
			enemyPoints = player.getPoints();
			timePoints = 0;
			healthMultiplier = ((float)player.getHealth()) / 2;
			if (healthMultiplier < 1.0) {
				healthMultiplier = 1.0;
			}
			totalPoints = enemyPoints * healthMultiplier;

			kPoints.setString(std::to_string(enemyPoints));
			tPoints.setString(std::to_string(timePoints));
			hPoints.setString("x" + std::to_string(healthMultiplier).substr(0,3));
			toPoints.setString(std::to_string(totalPoints));
			sounds.playSound("gui.points");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			state = State::TOTAL;
		}
		switch (state) {
		case ENEMY:
			if (clock.getElapsedTime().asSeconds() >= 1.5) {
				clock.restart();
				sounds.playSound("gui.points");
				state = State::HEALTH;
			}
			break;
		case HEALTH:
			if (clock.getElapsedTime().asSeconds() >= 1.5) {
				clock.restart();
				sounds.playSound("gui.points");
				state = State::TOTAL;
			}
			break;
		case TOTAL:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					state = State::EXIT;
					player.setPoints(totalPoints);
				}
			break;
		}
	}
}

void PointsScreen::draw(sf::RenderWindow & window) {
	window.draw(bg);
	switch (state) {
	case TOTAL:
		window.draw(total);
		window.draw(toPoints);
	case HEALTH:
		window.draw(health);
		window.draw(hPoints);
	case ENEMY:
		window.draw(kills);
		window.draw(kPoints);
	}
}

void PointsScreen::reset() {
	state = State::ENEMY;
	start = false;
}

/*
update:
check if in right case:
if so display string

*/
