#include "stdafx.h"
#include "PlayableSound.h"
#include "FileNotFoundException.h"

PlayableSound::PlayableSound(std::string file) {
	if (!buffer.loadFromFile(file)) {
		FileNotFoundException e;
		throw e;
	}
}

void PlayableSound::play() {
	sound.setBuffer(buffer);
	sound.play();
}

void PlayableSound::stop() {
	sound.stop();
}
