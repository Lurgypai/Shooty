#include "stdafx.h"
#include "LevelManager.h"
#include "EnemyBase.h"

LevelManager::LevelManager(void) : isLevelRunning(false), totalLevels(0), loading(false) {}

void LevelManager::addLevel(std::shared_ptr<Level> level) {

	levels.push_back(level);

	totalLevels++;
}

void LevelManager::load(int startLevel) {

	currentLevel = startLevel - 1;
	//level 1
	Level level1 = Level(1);
	Wave wave1_0, wave1_1, wave1_2, wave1_3, wave1_4, wave1_5;
	//1-0
	wave1_0.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 40));

	std::shared_ptr<Wave> wave1_0_ = std::make_shared<Wave>(wave1_0);
	//1-1
	wave1_1.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 210));
	std::shared_ptr<Wave> wave1_1_ = std::make_shared<Wave>(wave1_1);
	//1-2
	wave1_2.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 20));
	wave1_2.addEnemy(EnemyBase::SQUARE, sf::Vector2f(220, 40));
	wave1_2.addEnemy(EnemyBase::SQUARE, sf::Vector2f(260, 40));
	std::shared_ptr<Wave> wave1_2_ = std::make_shared<Wave>(wave1_2);
	//1-3
	wave1_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 250));
	wave1_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(220, 230));
	wave1_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(260, 230));
	std::shared_ptr<Wave> wave1_3_ = std::make_shared<Wave>(wave1_3);
	//1-4
	wave1_4.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 135));
	wave1_4.addEnemy(EnemyBase::SQUARE, sf::Vector2f(220, 135));
	wave1_4.addEnemy(EnemyBase::SQUARE, sf::Vector2f(260, 135));
	std::shared_ptr<Wave> wave1_4_ = std::make_shared<Wave>(wave1_4);
	//1-5
	wave1_5.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(240, 135));
	wave1_5.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 60));
	wave1_5.addEnemy(EnemyBase::SQUARE, sf::Vector2f(225, 75));
	wave1_5.addEnemy(EnemyBase::SQUARE, sf::Vector2f(255, 75));
	std::shared_ptr<Wave> wave1_5_ = std::make_shared<Wave>(wave1_5);

	//1
	level1.addWave(wave1_0_);	level1.addWave(wave1_1_);	level1.addWave(wave1_2_);	level1.addWave(wave1_3_);	level1.addWave(wave1_4_);	level1.addWave(wave1_5_);
	std::shared_ptr<Level> level1_ = std::make_shared<Level>(level1);

	//level 2
	Level level2 = Level(2);
	Wave wave2_0, wave2_1, wave2_2, wave2_3, wave2_4, wave2_5;
	//2-0
	wave2_0.addEnemy(EnemyBase::SQUARE, sf::Vector2f(220, 60));
	wave2_0.addEnemy(EnemyBase::SQUARE, sf::Vector2f(260, 60));
	std::shared_ptr<Wave> wave2_0_ = std::make_shared<Wave>(wave2_0);
	//2-1
	wave2_1.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 230));
	wave2_1.addEnemy(EnemyBase::SQUARE, sf::Vector2f(210, 220));
	wave2_1.addEnemy(EnemyBase::SQUARE, sf::Vector2f(270, 220));
	wave2_1.addEnemy(EnemyBase::SQUARE, sf::Vector2f(220, 60));
	wave2_1.addEnemy(EnemyBase::SQUARE, sf::Vector2f(260, 60));
	std::shared_ptr<Wave> wave2_1_ = std::make_shared<Wave>(wave2_1);
	//2-2
	wave2_2.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(240, 30));
	wave2_2.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(365, 135));
	wave2_2.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(115, 135));
	wave2_2.addEnemy(EnemyBase::SQUARE, sf::Vector2f(230, 240));
	wave2_2.addEnemy(EnemyBase::SQUARE, sf::Vector2f(250, 240));
	std::shared_ptr<Wave> wave2_2_ = std::make_shared<Wave>(wave2_2);
	//2-3
	wave2_3.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(240, 30));
	wave2_3.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(355, 135));
	wave2_3.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(125, 135));
	wave2_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 240));
	wave2_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(210, 210));
	wave2_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(270, 210));
	std::shared_ptr<Wave> wave2_3_ = std::make_shared<Wave>(wave2_3);
	//2-4
	wave2_4.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(240, 30));
	wave2_4.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(240, 240));
	wave2_4.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(140, 60));
	wave2_4.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(340, 60));
	wave2_4.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(140, 210));
	wave2_4.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(340, 210));
	std::shared_ptr<Wave> wave2_4_ = std::make_shared<Wave>(wave2_4);
	//2-5
	wave2_5.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(240, 30));
	wave2_5.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(240, 240));
	wave2_5.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(115, 135));
	wave2_5.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(365, 135));
	wave2_5.addEnemy(EnemyBase::SQUARE, sf::Vector2f(230, 115));
	wave2_5.addEnemy(EnemyBase::SQUARE, sf::Vector2f(230, 145));
	wave2_5.addEnemy(EnemyBase::SQUARE, sf::Vector2f(250, 115));
	wave2_5.addEnemy(EnemyBase::SQUARE, sf::Vector2f(250, 145));
	std::shared_ptr<Wave> wave2_5_ = std::make_shared<Wave>(wave2_5);
	//2
	level2.addWave(wave2_0_);	level2.addWave(wave2_1_);	level2.addWave(wave2_2_);	level2.addWave(wave2_3_); level2.addWave(wave2_4_); level2.addWave(wave2_5_);
	std::shared_ptr<Level> level2_ = std::make_shared<Level>(level2);

	//level 3
	Level level3 = Level(3);
	Wave wave3_0, wave3_1, wave3_2, wave3_3;
	//3-0
	wave3_0.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 135));
	wave3_0.addEnemy(EnemyBase::SQUARE, sf::Vector2f(220, 135));
	wave3_0.addEnemy(EnemyBase::SQUARE, sf::Vector2f(260, 135));
	wave3_0.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 115));
	wave3_0.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 155));
	std::shared_ptr<Wave> wave3_0_ = std::make_shared<Wave>(wave3_0);
	//3-1
	wave3_1.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(225, 150));
	wave3_1.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(225, 120));
	wave3_1.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(255, 150));
	wave3_1.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(255, 120));
	wave3_1.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 35));
	wave3_1.addEnemy(EnemyBase::SQUARE, sf::Vector2f(220, 35));
	wave3_1.addEnemy(EnemyBase::SQUARE, sf::Vector2f(270, 35));
	std::shared_ptr<Wave> wave3_1_ = std::make_shared<Wave>(wave3_1);
	//3-2
	wave3_2.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(240, 135));
	wave3_2.addEnemy(EnemyBase::SQUARE, sf::Vector2f(220, 135));
	wave3_2.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(200, 135));
	wave3_2.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 115));
	wave3_2.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(240, 95));
	wave3_2.addEnemy(EnemyBase::SQUARE, sf::Vector2f(260, 135));
	wave3_2.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(280, 135));
	wave3_2.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 155));
	wave3_2.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(240, 175));
	std::shared_ptr<Wave> wave3_2_ = std::make_shared<Wave>(wave3_2);
	//3-3
	wave3_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(220, 60));
	wave3_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(230, 60));
	wave3_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 60));
	wave3_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(250, 60));
	wave3_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(260, 60));
	wave3_3.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(215, 210));
	wave3_3.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(265, 210));
	wave3_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(115, 135));
	wave3_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(365, 135));
	std::shared_ptr<Wave> wave3_3_ = std::make_shared<Wave>(wave3_3);
	//3
	level3.addWave(wave3_0_); 	level3.addWave(wave3_1_);	level3.addWave(wave3_2_);	level3.addWave(wave3_3_);
	std::shared_ptr<Level> level3_ = std::make_shared<Level>(level3);

	//level 4
	Level level4 = Level(4);
	Wave wave4_0, wave4_1, wave4_2, wave4_3, wave4_4;
	//4-0
	wave4_0.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(240, 50));
	std::shared_ptr<Wave> wave4_0_ = std::make_shared<Wave>(wave4_0);
	//4-1
	wave4_1.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(240, 135));
	wave4_1.addEnemy(EnemyBase::SQUARE, sf::Vector2f(220, 135));
	wave4_1.addEnemy(EnemyBase::SQUARE, sf::Vector2f(260, 135));
	std::shared_ptr<Wave> wave4_1_ = std::make_shared<Wave>(wave4_1);

	//4-2
	wave4_2.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(180, 135));
	wave4_2.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(300, 135));
	wave4_2.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 75));
	wave4_2.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 135));
	wave4_2.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 195));
	std::shared_ptr<Wave> wave4_2_ = std::make_shared<Wave>(wave4_2);
	//4-3
	wave4_3.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(170, 65));
	wave4_3.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(170, 205));
	wave4_3.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(310, 65));
	wave4_3.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(310, 205));
	wave4_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 125));
	wave4_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 145));
	std::shared_ptr<Wave> wave4_3_ = std::make_shared<Wave>(wave4_3);
	//4-4
	wave4_4.addEnemy(EnemyBase::SQUARE, sf::Vector2f(200, 135));
	wave4_4.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(160, 135));
	wave4_4.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 175));
	wave4_4.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(240, 215));
	wave4_4.addEnemy(EnemyBase::SQUARE, sf::Vector2f(280, 135));
	wave4_4.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(320, 135));
	wave4_4.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 95));
	wave4_4.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(240, 55));
	std::shared_ptr<Wave> wave4_4_ = std::make_shared<Wave>(wave4_4);
	//4
	level4.addWave(wave4_0_); 	level4.addWave(wave4_1_);	level4.addWave(wave4_2_);	level4.addWave(wave4_3_);	level4.addWave(wave4_4_);
	std::shared_ptr<Level> level4_ = std::make_shared<Level>(level4);
	//level 5
	Level level5 = Level(5);
	Wave wave5_0, wave5_1, wave5_2, wave5_3, wave5_4, wave5_5, wave5_6;
	//5-0
	wave5_0.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(240, 135));
	wave5_0.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(240, 195));
	wave5_0.addEnemy(EnemyBase::SQUARE, sf::Vector2f(300, 135));
	wave5_0.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 75));
	wave5_0.addEnemy(EnemyBase::SQUARE, sf::Vector2f(180, 135));
	std::shared_ptr<Wave> wave5_0_ = std::make_shared<Wave>(wave5_0);
	//5-1
	wave5_1.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(200, 200));
	wave5_1.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(280, 200));
	wave5_1.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(200, 105));
	wave5_1.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(280, 105));
	wave5_1.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(240, 40));
	std::shared_ptr<Wave> wave5_1_ = std::make_shared<Wave>(wave5_1);

	//5-2
	wave5_2.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(240, 55));
	wave5_2.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(160, 135));
	wave5_2.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(320, 135));
	wave5_2.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(230, 230));
	wave5_2.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(250, 230));
	wave5_2.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 210));
	std::shared_ptr<Wave> wave5_2_ = std::make_shared<Wave>(wave5_2);
	//5-3
	wave5_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(200, 40));
	wave5_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(220, 40));
	wave5_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 40));
	wave5_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(260, 40));
	wave5_3.addEnemy(EnemyBase::SQUARE, sf::Vector2f(280, 40));
	wave5_3.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(225, 200));
	wave5_3.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(255, 200));
	wave5_3.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(240, 165));
	std::shared_ptr<Wave> wave5_3_ = std::make_shared<Wave>(wave5_3);
	//5-4
	wave5_4.addEnemy(EnemyBase::SQUARE, sf::Vector2f(200, 230));
	wave5_4.addEnemy(EnemyBase::SQUARE, sf::Vector2f(220, 230));
	wave5_4.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 230));
	wave5_4.addEnemy(EnemyBase::SQUARE, sf::Vector2f(260, 230));
	wave5_4.addEnemy(EnemyBase::SQUARE, sf::Vector2f(280, 230));
	wave5_4.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(225, 70));
	wave5_4.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(255, 70));
	wave5_4.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(240, 105));
	std::shared_ptr<Wave> wave5_4_ = std::make_shared<Wave>(wave5_4);
	//5-5
	wave5_5.addEnemy(EnemyBase::SQUARE, sf::Vector2f(270, 230));
	wave5_5.addEnemy(EnemyBase::SQUARE, sf::Vector2f(250, 230));
	wave5_5.addEnemy(EnemyBase::SQUARE, sf::Vector2f(230, 230));
	wave5_5.addEnemy(EnemyBase::SQUARE, sf::Vector2f(210, 230));
	wave5_5.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(240, 30));
	wave5_5.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(180, 50));
	wave5_5.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(300, 50));
	wave5_5.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(240, 135));
	std::shared_ptr<Wave> wave5_5_ = std::make_shared<Wave>(wave5_5);
	//5-6
	wave5_5.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(240, 50));
	wave5_5.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(325, 135));
	wave5_5.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(240, 220));
	wave5_5.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(155, 135));
	wave5_5.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(200, 135));
	wave5_5.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(280, 135));
	wave5_5.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 75));
	wave5_5.addEnemy(EnemyBase::SQUARE, sf::Vector2f(300, 195));
	wave5_5.addEnemy(EnemyBase::SQUARE, sf::Vector2f(180, 195));
	std::shared_ptr<Wave> wave5_6_ = std::make_shared<Wave>(wave5_6);
	level5.addWave(wave5_0_); 	level5.addWave(wave5_1_);	level5.addWave(wave5_2_);	level5.addWave(wave5_3_);	level5.addWave(wave5_4_);	level5.addWave(wave5_5_);
	//5
	std::shared_ptr<Level> level5_ = std::make_shared<Level>(level5);

	//level 6
	Level level6 = Level(6);
	Wave wave6_0, wave6_1, wave6_2;
	//6-0
	wave6_0.addEnemy(EnemyBase::SQUARE, sf::Vector2f(240, 135));
	std::shared_ptr<Wave> wave6_0_ = std::make_shared<Wave>(wave6_0);
	//6-1
	wave6_1.addEnemy(EnemyBase::TRIANGLE, sf::Vector2f(240, 135));
	std::shared_ptr<Wave> wave6_1_ = std::make_shared<Wave>(wave6_1);
	//6-2
	wave6_2.addEnemy(EnemyBase::CIRCLE, sf::Vector2f(240, 135));
	std::shared_ptr<Wave> wave6_2_ = std::make_shared<Wave>(wave6_2);
	//6
	level6.addWave(wave6_0_);	level6.addWave(wave6_1_);	level6.addWave(wave6_2_);
	level6.setHasBoss(true);
	std::shared_ptr<Level> level6_ = std::make_shared<Level>(level6);
	//add levels
	addLevel(level1_);
	addLevel(level2_);
	addLevel(level3_);
	addLevel(level4_);
	addLevel(level5_);
	addLevel(level6_);
}

bool LevelManager::update(EntityManager * manager) {
		if (!levels.at(currentLevel)->isStarted()) {
			levels.at(currentLevel)->spawnWave(manager);
			levels.at(currentLevel)->setStarted(true);
			manager->reload();
			isLevelRunning = true;
		}
		else if (levels.at(currentLevel)->checkCurrentWaveComplete()) {
			if (isLevelRunning == true) {
				isLevelRunning = false;
				delay.restart();
			}
			if (delay.getElapsedTime().asSeconds() >= DELAY) {
				levels.at(currentLevel)->advanceWave(manager);
				manager->reload();
				delay.restart();
				isLevelRunning = true;

				if (levels.at(currentLevel)->isComplete()) {
					if (currentLevel != totalLevels - 1) {
						currentLevel++;
						loading = true;
					}
					else {
						return true;
					}
				}
			}
		}
		else if (levels.at(currentLevel)->getHasBoss() && levels.at(currentLevel)->isFinalWave()) {
			if (manager->checkBossDead())
				return true;
		}
		else if (levels.at(currentLevel)->getCurrentWave() != nullptr && !levels.at(currentLevel)->checkCurrentWaveComplete() && !levels.at(currentLevel)->getCurrentWave()->getCompleted()) {
			levels.at(currentLevel)->spawnWave(manager);
			manager->reload();
		}
		return false;
}

void LevelManager::setLevel(int levelId) {
	currentLevel = levelId;
}

void LevelManager::nextLevel() {
	currentLevel++;
}

void LevelManager::setLoading(bool loading_) {
	loading = loading_;
}

int LevelManager::getLevel() const {
	return currentLevel;
}

bool LevelManager::isLoading()
{
	return loading;
}

void LevelManager::reset() {
	levels.clear();
	isLevelRunning = false;
	totalLevels = 0;
	loading = false;
}
