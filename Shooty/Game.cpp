#include "stdafx.h"
#include "Game.h"
#include "PlayerBullet.h"
#include "EnemyBase.h"
#include "LevelManager.h"
#include "FileNotFoundException.h"

Game::Game(void) : default(1080, 720, 60) {
	loopState();
}

void Game::start() {
	window.create(sf::VideoMode(default.getWidth(), default.getHeight()), "Shooty"//,
		//sf::Style::Fullscreen
		);
	window.setFramerateLimit(default.getFPS());
	state = Game::PRELOADING;
}

void Game::loopState() {
	while (Game::state != Game::EXITING) {
		switch (state)
		{
		case Game::STARTING:
			start();
			break;
		case Game::PRELOADING:
			preLoad();
			break;
		case Game::MAINMENU:
			mainMenu();
			break;
		case Game::LOADING:
			load();
			break;
		case Game::RUNNING:
			loopRunning();
			break;
		case Game::ADVANCING:
			advance();
			break;
		case Game::POINTS:
			points();
			break;
		case Game::PAUSED:
			pause();
			break;
		case Game::LOSE:
			lose();
			break;
		case Game::WIN:
			win();
			break;
		case Game::EXITING:
			close();
			break;
		default:
			state = Game::STARTING;
			break;
		}
	}
}

void Game::loopRunning() {
	while (state == Game::RUNNING) {
		if (levelManager.isLoading()) {
			state = Game::POINTS;
			levelManager.setLoading(false);
		}
		if (gameClock.getElapsedTime().asSeconds() >= ((float)1 / default.getFPS())) {
			bool win(false);
			gameClock.restart();
			window.clear(sf::Color::Black);
			win = levelManager.update(&entityManager);
			entityManager.update(window, arena, soundManager);
			Gui.update(*entityManager.getPlayer());

			arena.draw(window);
			entityManager.draw(window);
			Gui.draw(window);
			window.display();

			if (entityManager.getPlayer()->getDead()) {
				static int respawnTimer = 0;
				respawnTimer++;
				if (respawnTimer == 59) {
					respawnTimer = 0;
					state = GameState::LOSE;
				}
			}
			if (win)
				state = GameState::WIN;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			state = Game::PAUSED;
		}
		sf::Event event;
		while (window.pollEvent(event));
	}
}

void Game::pause() {
	while (state != Game::RUNNING && state != Game::EXITING) {
		if (gameClock.getElapsedTime().asSeconds() >= ((float)1 / default.getFPS())) {
			window.clear(sf::Color::Black);
			arena.draw(window);
			entityManager.draw(window);
			PauseMenu.renderMenu(window);
			std::string response = PauseMenu.checkButtons(window, soundManager);
			if (response == "exit") {
				state = Game::EXITING;
			}
			if (response == "resume") {
				state = Game::RUNNING;
			}
			window.display();
			sf::Event event;
			while (window.pollEvent(event));
			gameClock.restart();
		}
	}
}

void Game::close() {
	window.close();
}

void Game::load() {
	window.clear(sf::Color::Black);
	window.display();

	levelManager.load(1);
	
	entityManager.load(player, User, soundManager);

	arena.load();

	Gui.load();

	AdvanceScreen.load();
	PointsScreen.load();

	PauseMenu.addButton("exit", "Leave", sf::Vector2f(124, 138), Button::SMALL);
	PauseMenu.addButton("resume", "Play", sf::Vector2f(246, 138), Button::SMALL);
	PauseMenu.loadMenu(window);

	LoseMenu.addButton("exit", "Leave", sf::Vector2f(124, 138), Button::SMALL);
	LoseMenu.addButton("retry", "Retry", sf::Vector2f(246, 138), Button::SMALL);
	LoseMenu.loadMenu(window);

	WinMenu.addButton("exit", "Leave", sf::Vector2f(124, 210), Button::SMALL);
	WinMenu.addButton("again", "Retry", sf::Vector2f(246, 210), Button::SMALL);
	WinMenu.loadMenu(window);
	state = Game::RUNNING;
}

void Game::preLoad() {
	if (!titleTexture.loadFromFile("resources/images/shooty.png")) {
		FileNotFoundException e;
		throw e;
	}
	title.setTexture(titleTexture);
	title.setOrigin(title.getLocalBounds().width / 2, title.getLocalBounds().height / 2);
	title.setPosition(240, 80);

	//create the main menu
	MainMenu.addButton("play", "Play", sf::Vector2f(120, 160), Button::LARGE);
	MainMenu.addButton("exit", "Leave", sf::Vector2f(185, 197), Button::SMALL);

	MainMenu.loadMenu(window);

	soundManager = SoundManager();

	window.setVerticalSyncEnabled(true);
	default.reScale(window);

	state = Game::MAINMENU;
}

void Game::mainMenu() {
	while (state != Game::LOADING && state != Game::EXITING) {
		if (gameClock.getElapsedTime().asSeconds() >= ((float)1 / default.getFPS())) {
			window.clear(sf::Color::Black);
			MainMenu.renderMenu(window);
			window.draw(title);
			std::string response = MainMenu.checkButtons(window, soundManager);
			if (response == "exit") {
				state = Game::EXITING;
			}
			if (response == "play") {
				state = Game::LOADING;
			}
			window.display();
			checkCloseWindow();
			gameClock.restart();
		}
	}
}

void Game::advance() {
	while (state == Game::ADVANCING) {
		window.clear(sf::Color::Black);
		AdvanceScreen.update(*entityManager.getPlayer(), levelManager.getLevel(), soundManager);
		arena.draw(window);
		AdvanceScreen.draw(window);
		window.display();
		if (AdvanceScreen.getState() == AdvanceScreen::State::EXIT) {
			AdvanceScreen.reset();
			state = RUNNING;
		}
		sf::Event event;
		while (window.pollEvent(event));
	}
}

void Game::points() {
	while (state == Game::POINTS) {

		window.clear(sf::Color::Black);

		PointsScreen.update(*entityManager.getPlayer(), levelManager.getLevel(), soundManager);
		if (PointsScreen.getState() == PointsScreen::State::EXIT) {
			PointsScreen.reset();
			state = ADVANCING;
			break;
		}
		PointsScreen.draw(window);

		window.display();

		sf::Event event;
		while (window.pollEvent(event));
	}
}

void Game::lose() {
	while (state != Game::PRELOADING && state != Game::EXITING) {
		if (gameClock.getElapsedTime().asSeconds() >= ((float)1 / default.getFPS())) {
			window.clear(sf::Color::Black);
			arena.draw(window);
			entityManager.draw(window);
			LoseMenu.renderMenu(window);
			std::string response = LoseMenu.checkButtons(window, soundManager);
			if (response == "exit") {
				state = Game::EXITING;
			}
			if (response == "retry") {
				reset();
				state = Game::PRELOADING;
			}
			window.display();
			gameClock.restart();

			sf::Event event;
			while (window.pollEvent(event));
		}
	}
}

void Game::win() {
	while (state == GameState::WIN) {
			window.clear(sf::Color::Black);
			winScreen.update(*entityManager.getPlayer(), soundManager);
			winScreen.draw(window);
			WinMenu.renderMenu(window);
			std::string response = WinMenu.checkButtons(window, soundManager);
			if (response == "exit") {
				state = Game::EXITING;
			}
			if (response == "again") {
				reset();
				state = Game::PRELOADING;
			}
			window.display();
			gameClock.restart();

			sf::Event event;
			while (window.pollEvent(event));
	}
}

void Game::reset() {
	player.reset();
	entityManager.reset();
	levelManager.reset();
	User.setCurrentPoints(0);
}


void Game::checkCloseWindow() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			state = EXITING;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		state = EXITING;
	}
}

sf::RenderWindow* Game::getWindow() {
	return &window;
}

sf::Clock* Game::getClock() {
	return &gameClock;
}

/*
Work on what you want as you feel like it.
However... START LEADS TO COMPLETION
do not leave a part unfinisehd and start a different part
so we got a few things. Except gfx
---Menus---
	-main and pause.
	-create pause and config. may need new button types
	--configuration of the game (resolution, volume): needs refining
	-sliders? (probably not)
---gameplay---

	---------FINISH MANAGER---------

	-objects
		-enemy base
			-shooting (normal speed, pew pew pew) -done
			-surround (slow, beeeeearszzzzhh) -done
			-homing (turret no moving, chunk)  -done
			-boss (all three, slow movement)
		-bullets
			-straight -done
			-expanding circle -done
			-homing -done
	-visuals
		-bars
			-health
			-shield
			-progress
		-timer
	-sound
		-research
---downtime---
	-startup splash of Shooty
	-loading everything
	-game over
	-pause -done
---Graphics---
	-charcter (looks like a clicker) -done
	-enemies (square shoots, circle area attacks, triangle homes, and hexagon is boss)
	-arena
		-big octagon -done
		-definite walls, possible inside outline, outside decor -done
---tutorial/dev time---
	-REQUIRES COMPLETEION OF GAMEPLAY
	-dev chatting
	-objects for explaining
---levels---
	-6, with a fake seven
	-in between time show the time left, and score which is determined by the time taken and the damage taken, combos through no hits
	-wave system. timer pauses during downtime.
	-bar for total enemies left.

---FINALS---
	--cleanup. You WILL do this before release.
	-look through from start to finish. clean it. fix methods. add methods. change methods. CHECK YOUR POINTERS.
	-bug fixing. Oscar beta. Possibly others.
*/