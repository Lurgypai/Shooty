#pragma once
#include "stdafx.h"
#include "SFML\Audio.hpp"

class PlayableSound {
public:
	PlayableSound(std::string file);
	void play();
	void stop();
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
};