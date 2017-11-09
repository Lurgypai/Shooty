#pragma once
#include "stdafx.h"
#include "Level.h"

class LevelManager {
private:
	std::vector<std::shared_ptr<Level>>	levels;
	int currentLevel;
	int totalLevels;
	bool isLevelRunning;
	bool loading;
	sf::Clock delay;
	const float DELAY = 2.0;
public:
	LevelManager(void);
	void addLevel( std::shared_ptr<Level> level);
	void load(int startLevel);
	bool update(EntityManager* manager);
	void setLevel(int levelId);
	void nextLevel();
	void setLoading(bool loading_);
	int getLevel() const;
	bool isLoading();
	void reset();
};