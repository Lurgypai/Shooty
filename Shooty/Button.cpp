#include "stdafx.h"
#include "Button.h"
#include "FileNotFoundException.h"

Button::Button(std::string id_, std::string text_, sf::Vector2f position_, Button::ButtonType type_) : id(id_), text(text_), type(type_) {
	sprite.setPosition(position_);
}

std::string Button::getId() {
	return id;
}

std::string Button::getText() {
	return text;
}

void Button::loadTexture(std::string fileLocation, int originX, int originY, int width, int height) {
	if (!texture.loadFromFile(fileLocation, sf::IntRect(originX, originY, width, height))) {
		FileNotFoundException e;
		throw e;
	}
	sprite.setTexture(texture);
}

void Button::loadOverlayTexture(std::string fileLocation, int originX, int originY, int width, int height) {
	if(!overlay.loadFromFile(fileLocation, sf::IntRect(originX, originY, width, height))) {
		FileNotFoundException e;
		throw e;
	}
	overlaySprite.setTexture(overlay);
	overlaySprite.setPosition(sprite.getPosition());
}

void Button::loadText(std::string text_, sf::Vector2f position, int width, int height) {
	if (!font.loadFromFile("resources/fonts/m20.ttf")) {
		FileNotFoundException e;
		throw e;
	}
	sfText = sf::Text(text, font, 192);
	sfText.setScale(.125, .125);
	sfText.setOutlineColor(sf::Color::Black);
	sfText.setFillColor(sf::Color::Black);
	sfText.setOrigin(sfText.getLocalBounds().width / 2, sfText.getGlobalBounds().top);
	sfText.setPosition(position.x + width/2, position.y + 3);
}

sf::Sprite* Button::getSprite() {
	return &sprite;
}

sf::Text* Button::getSfText() {
	return &sfText;
}

sf::Sprite * Button::getOverlaySprite() {
	return &overlaySprite;
}

bool Button::mouseIsOver(){
	return mouseOver;
}

void Button::setMouseOver(bool over_) {
	mouseOver = over_;
}

Button::ButtonType Button::getType() {
	return type;
}
