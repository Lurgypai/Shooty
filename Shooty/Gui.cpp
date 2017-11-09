#include "stdafx.h"
#include "Gui.h"
#include "FileNotFoundException.h"

void Gui::load() {
	if ((!hbarTexture.loadFromFile("resources/images/gui/health.png", sf::IntRect(0, 0, 71, 50))) &
			(!heartFullTexture.loadFromFile("resources/images/gui/health.png", sf::IntRect(2, 61, 16, 17))) &
			(!heartHalfTexture.loadFromFile("resources/images/gui/health.png", sf::IntRect(20, 61, 16, 17))) &
			(!dashPipTexture.loadFromFile("resources/images/gui/health.png", sf::IntRect(38, 61, 4, 4))) &
		(!n0.loadFromFile("resources/images/gui/numbers.png", sf::IntRect(0, 0, 5, 5))) &
		(!n1.loadFromFile("resources/images/gui/numbers.png", sf::IntRect(5, 0, 5, 5))) &
		(!n2.loadFromFile("resources/images/gui/numbers.png", sf::IntRect(10, 0, 5, 5))) &
		(!n3.loadFromFile("resources/images/gui/numbers.png", sf::IntRect(15, 0, 5, 5))) &
		(!n4.loadFromFile("resources/images/gui/numbers.png", sf::IntRect(20, 0, 5, 5))) &
		(!n5.loadFromFile("resources/images/gui/numbers.png", sf::IntRect(25, 0, 5, 5))) &
		(!n6.loadFromFile("resources/images/gui/numbers.png", sf::IntRect(30, 0, 5, 5))) &
		(!n7.loadFromFile("resources/images/gui/numbers.png", sf::IntRect(35, 0, 5, 5))) &
		(!n8.loadFromFile("resources/images/gui/numbers.png", sf::IntRect(40, 0, 5, 5))) &
		(!n9.loadFromFile("resources/images/gui/numbers.png", sf::IntRect(45, 0, 5, 5))) &
		(!points.loadFromFile("resources/images/gui/points.png"))) {
		FileNotFoundException e;
		throw e;
	}

	renderPoints = 0;
	renderHealth = 6;

	hbar.setTexture(hbarTexture);

	hbar.setPosition(sf::Vector2f(25.0, 25.0));
	sf::Sprite temp1;
	temp1.setTexture(heartFullTexture);
	sf::Sprite temp2;
	temp2.setTexture(heartFullTexture);
	sf::Sprite temp3;
	temp3.setTexture(heartFullTexture);

	temp1.setPosition(sf::Vector2f(30.0, 38.0));
	temp2.setPosition(sf::Vector2f(48.0, 38.0));
	temp3.setPosition(sf::Vector2f(66.0, 38.0));

	hearts.push_back(temp1);
	hearts.push_back(temp2);
	hearts.push_back(temp3);

	pointsBar.setTexture(points);
	pointsBar.setPosition(365.0, 25.0);

	pointsNum[0].setTexture(n0);
	pointsNum[0].setPosition(390.0, 43.0);
	pointsNum[1].setTexture(n0);
	pointsNum[1].setPosition(395.0, 43.0);
	pointsNum[2].setTexture(n0);
	pointsNum[2].setPosition(400.0, 43.0);
	pointsNum[3].setTexture(n0);
	pointsNum[3].setPosition(405.0, 43.0);
	pointsNum[4].setTexture(n0);
	pointsNum[4].setPosition(410.0, 43.0);
	pointsNum[5].setTexture(n0);
	pointsNum[5].setPosition(415.0, 43.0);

	multiplierNum[0].setTexture(n0);
	multiplierNum[0].setPosition(430.0, 43.0);
	multiplierNum[1].setTexture(n0);
	multiplierNum[1].setPosition(436.0, 43.0);

	dashPip[0].setTexture(dashPipTexture);
	dashPip[1].setTexture(dashPipTexture);
	dashPip[2].setTexture(dashPipTexture);

	dashPip[0].setPosition(hbar.getPosition().x + 40, hbar.getPosition().y + 40);
	dashPip[1].setPosition(hbar.getPosition().x + 46, hbar.getPosition().y + 40);
	dashPip[2].setPosition(hbar.getPosition().x + 52, hbar.getPosition().y + 40);
}

void Gui::draw(sf::RenderWindow & window) {
	typedef std::vector<sf::Sprite>::const_iterator iter;

	window.draw(hbar);
	window.draw(pointsBar);
	for (sf::Sprite sprt : multiplierNum) {
		window.draw(sprt);
	}

	std::string points = std::to_string(renderPoints);
	std::reverse(points.begin(), points.end());
	int column(5);
	for (char num : points) {
		int number = num - '0';
		switch (number) {
		case 0:
			pointsNum[column].setTexture(n0);
			break;
		case 1:
			pointsNum[column].setTexture(n1);
			break;
		case 2:
			pointsNum[column].setTexture(n2);
			break;
		case 3:
			pointsNum[column].setTexture(n3);
			break;
		case 4:
			pointsNum[column].setTexture(n4);
			break;
		case 5:
			pointsNum[column].setTexture(n5);
			break;
		case 6:
			pointsNum[column].setTexture(n6);
			break;
		case 7:
			pointsNum[column].setTexture(n7);
			break;
		case 8:
			pointsNum[column].setTexture(n8);
			break;
		case 9:
			pointsNum[column].setTexture(n9);
			break;
		}
		window.draw(pointsNum[column]);
		column--;
	}

	std::string multiplier = std::to_string(renderMultiplier);
	int column_{0};
	for (char num : multiplier) {
		int number = num - '0';
		switch (number)
		{
		case 0:
			multiplierNum[column_].setTexture(n0);
			break;
		case 1:
			multiplierNum[column_].setTexture(n1);
			break;
		case 2:
			multiplierNum[column_].setTexture(n2);
			break;
		case 3:
			multiplierNum[column_].setTexture(n3);
			break;
		case 4:
			multiplierNum[column_].setTexture(n4);
			break;
		case 5:
			multiplierNum[column_].setTexture(n5);
			break;
		case 6:
			multiplierNum[column_].setTexture(n6);
			break;
			multiplierNum[column_].setTexture(n7);
		case 7:
			break;
		case 8:
			multiplierNum[column_].setTexture(n8);
			break;
		case 9:
			multiplierNum[column_].setTexture(n9);
			break;
		}
		window.draw(multiplierNum[column_]);
		column_++;
	}

	if (renderHealth == 5 || renderHealth == 6) {
		for (iter i = hearts.begin(); i != hearts.end(); i++) {
			window.draw(*i);
		}
	}
	else if (renderHealth == 3 || renderHealth == 4) {
		for (iter i = hearts.begin(); i != hearts.end() - 1; i++) {
			window.draw(*i);
		}

	}
	else if (renderHealth == 1 || renderHealth == 2) {
		window.draw(hearts.at(0));
	}

	for (int i = 0; i < 3 - renderDashes; i++) {
		window.draw(dashPip[i]);
	}
}

void Gui::update(const Player & player) {
	renderMultiplier = player.getMultiplier() * 10;

	typedef std::vector<sf::Sprite>::iterator iter;
	renderHealth = player.getHealth();
	renderPoints = player.getPoints();
	renderDashes = player.getDashes();
	if (renderHealth % 2 != 0) {
		if (renderHealth == 5)
			hearts[2].setTexture(heartHalfTexture);
		if (renderHealth == 3)
			hearts[1].setTexture(heartHalfTexture);
		if (renderHealth == 1)
			hearts[0].setTexture(heartHalfTexture);
	}
	else {
		for (iter i = hearts.begin(); i != hearts.end(); i++) {
			i->setTexture(heartFullTexture);
		}
	}
}
