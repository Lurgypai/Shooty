#pragma once
#include "stdafx.h"
#include "EntityPlayer.h"
#include "EnemyBase.h"
#include "IAIComponent.h"

class AISquareComponent : public AIComponent {
private:
	int angleModifier;
public:
	void update(sf::RenderWindow& window, EnemyBase* entity, Player* player, const Arena& arena, SoundManager& sounds);
};