#pragma once
#include <GL\glew.h>
#include <SDL\SDL.h>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Input_Manager.h"

enum class GameState{PLAY, EXIT};


class MainGame
{
public:

	MainGame();
	~MainGame();

	void run();

	
	
private:
	void processInput();
	void gameLoop();
	void initSystems();

	SDL_Window* _window;
	int _screenWidth = 480;
	int _screenHeight = 360;
	GameState _gameState;

	char c;
	bool Typing;
	std::string stream;

};

