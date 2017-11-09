#pragma once
#include "stdafx.h"
#include "EntityPlayer.h"
#include "EnemyBase.h"
#include "IAIComponent.h"

class AIHexaComponent : public AIComponent {
public:
	void update(sf::RenderWindow& window, EnemyBase* entity, Player* player, const Arena& arena, SoundManager& sounds);
	
private:
	int attackTime = 0;
	int attackWait = 15;
	int dashFrame = 0;
	int dashFrames = 20;
};