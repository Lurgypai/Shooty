#pragma once
#include "stdafx.h"
#include "Wave.h"

class Level {
private:
	int id;
	std::string title;
	int currentWave;
	int totalWaves;
	std::vector<std::shared_ptr<Wave>> waves;
	bool started;
	bool completed;
	bool hasBoss;
public:
	Level(void);
	Level(int id_);
	void addWave(const std::shared_ptr<Wave> wave);
	std::shared_ptr<Wave> getCurrentWave();
	void setCurrentWave(int wave_);
	void spawnWave(EntityManager* manager);
	void advanceWave(EntityManager* manager);
	bool checkCurrentWaveComplete();
	bool isStarted();
	bool isComplete();
	void setStarted(bool started_);
	void setComplete(bool completed_);
	void setHasBoss(bool hasBoss_);
	bool getHasBoss();
	bool isFinalWave();
	int getId() const;
};