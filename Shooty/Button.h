#pragma once
#include "stdafx.h"

class Button {
public:
	enum ButtonType {
		SMALL, LARGE
	};

private:
	std::string id;
	std::string fileName;
	std::string text;

	sf::Sprite sprite;
	sf::Texture texture;

	sf::Sprite overlaySprite;
	sf::Texture overlay;

	sf::Text sfText;
	sf::Font font;

	ButtonType type;
	bool mouseOver;
public:
	Button::Button(std::string id_, std::string text_, sf::Vector2f position_, ButtonType type_);
	std::string getId();
	std::string getText();

	void loadTexture(std::string fileLocation, int originX, int originY, int width, int height);
	void loadOverlayTexture(std::string fileLocation, int originX, int originY, int width, int height);
	void loadText(std::string text_, sf::Vector2f position, int width, int height);

	sf::Sprite* getSprite();
	sf::Text* getSfText();

	sf::Sprite* getOverlaySprite();

	bool mouseIsOver();
	void setMouseOver(bool over_);

	ButtonType getType();
};