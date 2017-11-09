#include "stdafx.h"
#include "Configuration.h"

Config::Config(int width_, int height_, int fps_) : width(width_), height(height_), fps(fps_) {
}

int Config::getWidth() const {
	return width;
}

int Config::getHeight() const {
	return height;
}

int Config::getFPS() const{
	return fps;
}

int Config::getBaseHeight() {
	return baseHeight;
}

int Config::getBaseWidth() {
	return baseWidth;
}

int Config::getHeightRatio() {
	return height / baseHeight;
}

int Config::getWidthRatio() {
	return width / baseWidth;
}

void Config::setWidth(int width_) {
	width = width_;
}

void Config::setHeight(int height_) {
	height = height_;
}

void Config::setFPS(int fps_) {
	fps = fps_;
}

void Config::reScale(sf::RenderWindow & window) {
	sf::View view = window.getDefaultView();
	view.zoom((float)baseWidth / width);
	view.setCenter(baseWidth/2, baseHeight/2);
	window.setView(view);
}
