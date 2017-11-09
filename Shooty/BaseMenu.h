#pragma once
#include "stdafx.h"
#include "Button.h"
#include "Configuration.h"
#include "SoundManager.h"

class Menu {
private:
	std::vector<Button> buttons;
public:
	void renderMenu(sf::RenderWindow& _window);
	void loadMenu(sf::RenderWindow& _window);
	std::string checkButtons(sf::RenderWindow& _window, SoundManager& sounds);
	Menu* addButton(std::string id_, std::string text_, sf::Vector2f position_, Button::ButtonType type_);
};
