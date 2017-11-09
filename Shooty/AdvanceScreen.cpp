#include "stdafx.h"
#include "AdvanceScreen.h"
#include "FileNotFoundException.h"
#include "EntityPlayer.h"

void AdvanceScreen::load() {
		if (!font.loadFromFile("resources/fonts/m20.ttf")) {
			FileNotFoundException e;
			throw e;
	}

	level = sf::Text("Level", font, 192);
	level.setScale(.125, .125);
	level.setFillColor(sf::Color::White);
	level.setOutlineColor(sf::Color::White);
	level.setOrigin(level.getLocalBounds().width / 2, level.getLocalBounds().height / 2);

	lvlnumber = sf::Text("0", font, 192);
	lvlnumber.setScale(.125, .125);
	lvlnumber.setFillColor(sf::Color::White);
	lvlnumber.setOutlineColor(sf::Color::White);
	lvlnumber.setOrigin(lvlnumber.getLocalBounds().width / 2, lvlnumber.getLocalBounds().height / 2);

	number = sf::Text("0", font, 192);
	number.setScale(.125, .125);
	number.setFillColor(sf::Color::White);
	number.setOutlineColor(sf::Color::White);
	number.setOrigin(number.getLocalBounds().width / 2, number.getLocalBounds().height / 2);

	go = sf::Text("GO", font, 192);
	go.setScale(.125, .125);
	go.setFillColor(sf::Color::White);
	go.setOutlineColor(sf::Color::White);
	go.setOrigin(go.getLocalBounds().width / 2, go.getLocalBounds().height / 2);

	start = false;

	level.setPosition(240, 120);
	lvlnumber.setPosition(240, 153);

	number.setPosition(240, 135);
	go.setPosition(240, 135);
}

void AdvanceScreen::update(Player& player, int currentLevel, SoundManager& sounds) {
	if (!start) {
		clock.restart();
		player.softReset();
		currentLevel++;
		std::string stng = std::to_string(currentLevel);
		lvlnumber.setString(stng);
		start = true;
	}
	int elapsedTime = (int)std::round(clock.getElapsedTime().asSeconds()*10);
	switch (elapsedTime) {
	case 9:
		state = State::LEVEL;
		break;
	case 30:
		state = State::COUNTDOWN;
		number.setString("3");
		sounds.playSound("gui.countdown");
		break;
	case 37:
		number.setString("2");
		sounds.playSound("gui.countdown");
		break;
	case 44:
		number.setString("1");
		sounds.playSound("gui.countdown");
		break;
	case 51:
		state = State::GO;
		sounds.playSound("gui.go");
		break;
	case 58:
		state = State::EXIT;
		break;
	}
}

void AdvanceScreen::draw(sf::RenderWindow & window) {
	switch (state)
	{
	case AdvanceScreen::LEVEL:
		window.draw(level);
		window.draw(lvlnumber);
		break;
	case AdvanceScreen::COUNTDOWN:
		window.draw(number);
		break;
	case AdvanceScreen::GO:
		window.draw(go);
		break;
	}
}

AdvanceScreen::State AdvanceScreen::getState() {
	return state;
}

void AdvanceScreen::reset() {
	start = false;
	state = State::LEVEL;
}
