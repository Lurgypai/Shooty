#pragma once
#include "stdafx.h"
#include "EntityPlayer.h"
#include "EnemyBase.h"

class EnemyBase;
class AIComponent {
public:
	virtual void update(sf::RenderWindow& window, EnemyBase* entity, Player* player, const Arena& arena, SoundManager& sounds) = 0;
};