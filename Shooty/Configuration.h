#pragma once
#include "stdafx.h"

class Config {
private:
	int width;
	int height;
	int fps;

	static const int baseWidth = 480;
	static const int baseHeight = 270;
public:
	Config::Config(int width_, int height_, int fps_);

	int getWidth() const;
	int getHeight() const;
	int getFPS() const;
	static int getBaseHeight();
	static int getBaseWidth();

	int getHeightRatio();
	int getWidthRatio();

	void setWidth(int width_);
	void setHeight(int heigth_);
	void setFPS(int fps_);

	void reScale(sf::RenderWindow& window);
};