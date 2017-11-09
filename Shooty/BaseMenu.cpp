#include "stdafx.h"
#include "BaseMenu.h"
#include "Configuration.h"

void Menu::renderMenu(sf::RenderWindow& _window) {
	for (std::vector<Button>::iterator i = buttons.begin(); i != buttons.end(); i++) {
		_window.draw(*i->getSprite());
		_window.draw(*i->getSfText());
	}
}

void Menu::loadMenu(sf::RenderWindow& _window) {
	for (std::vector<Button>::iterator i = buttons.begin(); i != buttons.end(); i++) {
		if (i->getType() == Button::LARGE) {
			i->loadTexture("resources/images/menu/menu.png", 10, 10, 240, 30);
			i->loadOverlayTexture("resources/images/menu/menu.png", 10, 90, 240, 30);

		}
		if (i->getType() == Button::SMALL) {
			i->loadTexture("resources/images/menu/menu.png", 10, 50, 110, 30);
			i->loadOverlayTexture("resources/images/menu/menu.png", 140, 50, 110, 30);
		}

		i->loadText(i->getText(), i->getSprite()->getPosition(), i->getSprite()->getGlobalBounds().width, i->getSprite()->getGlobalBounds().height);
	}
}

std::string Menu::checkButtons(sf::RenderWindow& _window, SoundManager& sounds) {

	for (std::vector<Button>::iterator i = buttons.begin(); i != buttons.end(); i++) {
		if (i->getSprite()->getGlobalBounds().contains(sf::Vector2f(_window.mapPixelToCoords(sf::Mouse::getPosition(_window))))) {
			if (!i->mouseIsOver()) {
				i->setMouseOver(true);
				sounds.playSound("menu.hover");
			}
			_window.draw(*i->getOverlaySprite());

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			return i->getId();
			}
		}
		else {
			if (i->mouseIsOver()) {
				i->setMouseOver(false);
			}
		}
	}
	return "";
}

Menu* Menu::addButton(std::string id_, std::string text_, sf::Vector2f position_, Button::ButtonType type_) {
	Button button(id_, text_, position_, type_);
	buttons.push_back(button);
	return this;
}
