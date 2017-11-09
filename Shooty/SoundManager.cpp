#include "stdafx.h"
#include "SoundManager.h"

SoundManager::SoundManager(void) {
	for (std::string& string : currentSounds) {
		string = "";
	}
	PlayableSound hover("resources/sounds/playable/menu/Hover.ogg");

	PlayableSound countdown("resources/sounds/playable/gui/Countdown.ogg");
	PlayableSound go("resources/sounds/playable/gui/Go.ogg");
	PlayableSound points("resources/sounds/playable/gui/Points.ogg");

	PlayableSound circleshoot("resources/sounds/playable/game/enemy/CircleShoot.ogg");
	PlayableSound rockethit("resources/sounds/playable/game/enemy/RocketHit.ogg");
	PlayableSound squareshoot("resources/sounds/playable/game/enemy/SquareShoot.ogg");
	PlayableSound triangleshoot("resources/sounds/playable/game/enemy/TriangleShoot.ogg");


	PlayableSound damaged("resources/sounds/playable/game/player/Damaged.ogg");
	PlayableSound dash("resources/sounds/playable/game/player/Dash.ogg");
	PlayableSound death("resources/sounds/playable/game/player/Death.ogg");
	PlayableSound hit("resources/sounds/playable/game/player/Hit.ogg");
	PlayableSound shoot("resources/sounds/playable/game/player/Shoot.ogg");

	sounds.insert(std::pair<std::string, PlayableSound>("menu.hover", hover)); //done

	sounds.insert(std::pair<std::string, PlayableSound>("gui.countdown", countdown));
	sounds.insert(std::pair<std::string, PlayableSound>("gui.go", go));
	sounds.insert(std::pair<std::string, PlayableSound>("gui.points", points)); 

	sounds.insert(std::pair<std::string, PlayableSound>("enemy.circleshoot", circleshoot)); //done
	sounds.insert(std::pair<std::string, PlayableSound>("enemy.rockethit", rockethit)); //done
	sounds.insert(std::pair<std::string, PlayableSound>("enemy.squareshoot", squareshoot)); //done
	sounds.insert(std::pair<std::string, PlayableSound>("enemy.triangleshoot", triangleshoot)); //done

	sounds.insert(std::pair<std::string, PlayableSound>("player.damaged", damaged)); //done
	sounds.insert(std::pair<std::string, PlayableSound>("player.dash", dash)); //done
	sounds.insert(std::pair<std::string, PlayableSound>("player.death", death)); //done
	sounds.insert(std::pair<std::string, PlayableSound>("player.hit", hit)); //done
	sounds.insert(std::pair<std::string, PlayableSound>("player.shoot", shoot)); //done
}

void SoundManager::playSound(std::string key) {
	for (std::string id : currentSounds) {
		if (id == key) {
			sounds.at(key).stop();
			sounds.at(key).play();
			return;
		}
	}
	if (sounds.find(currentSounds[0]) != sounds.end())
		sounds.at(currentSounds[0]).stop();

	currentSounds[0] = currentSounds[1];
	currentSounds[1] = currentSounds[2];
	currentSounds[2] = currentSounds[3];
	currentSounds[3] = currentSounds[4];
	currentSounds[4] = currentSounds[5];
	currentSounds[5] = currentSounds[6];
	currentSounds[6] =  key;

	sounds.at(key).play();
}
