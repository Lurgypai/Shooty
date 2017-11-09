#pragma once
#include "stdafx.h"
#include "PlayableSound.h"

class SoundManager {
public:
	SoundManager(void);
	void playSound(std::string key);
private:
	std::map<std::string, PlayableSound> sounds;
	std::string currentSounds[7];
};
/*
observer
sound manager as well

manager
can create and load in all its stuff when its instantiated
it will have playsound functionality
sounds will have string ids, only one of each sound played at a time, up to... 7 sounds at once?

observer
watches and waits
gets back all the sound event types, and plays the respective sounds therough th manager
holds the even enums

necessary sounds:
-menu
 -hover
 -click
-gui
 -regain dash
 -points menu proceed
 -countdown
 -go
-game
	-enemy
	 -square shoot
	 -triangle shoot
	 -rocket hit
	 -circle shoot
	-player
	 -shoot
	 -get hit
	 -hit enemy
	 -die

	add to update methods for everything that needs it
*/