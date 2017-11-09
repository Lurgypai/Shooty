#pragma once
#include "stdafx.h"
#include "BaseMenu.h"
#include "Configuration.h"
#include "EntityPlayer.h"
#include "Arena.h"
#include "EntityManager.h"
#include "LevelManager.h"
#include "Gui.h"
#include "AdvanceScreen.h"
#include "PointsScreen.h"
#include "User.h"
#include "SoundManager.h"
#include "WinScreen.h"

class Game {
private:
	enum GameState {
		STARTING, LOADING, RUNNING, EXITING, PAUSED, MAINMENU, PRELOADING, POINTS, ADVANCING, LOSE, WIN
	};

	sf::RenderWindow window;
	sf::Clock gameClock;
	GameState state;

	Menu MainMenu;
	Menu PauseMenu;
	Menu LoseMenu;
	Menu WinMenu;

	Gui Gui;
	PointsScreen PointsScreen;
	AdvanceScreen AdvanceScreen;
	WinScreen winScreen;

	Config default;

	Player player;
	Arena arena;

	EntityManager entityManager;
	LevelManager levelManager;

	SoundManager soundManager;

	User User;

	sf::Texture titleTexture;
	sf::Sprite title;

	void start();
	void loopState();
	void loopRunning();
	void pause();
	void close();
	void load();
	void preLoad();
	void mainMenu();
	void advance();
	void points();
	void lose();
	void win();

	void reset();
public:
	Game::Game();

	void checkCloseWindow();
	sf::RenderWindow* getWindow();
	sf::Clock* getClock();
};