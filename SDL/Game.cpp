#include "Game.h"



mouse_Pos* Mouse = new mouse_Pos(0,0);

MainGame::MainGame()
{
	_window = nullptr;
	_gameState = GameState::PLAY;

}


MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems();
	gameLoop();

	SDL_DestroyWindow(_window);
	delete Mouse;
	
}

void MainGame::processInput()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{

		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;

		case SDL_MOUSEMOTION:
			Mouse->Get_M_Location(evnt.motion.x, evnt.motion.y);
			Mouse->Box(250, 270, 100, 100);
			break;

		case SDL_TEXTINPUT:

			c = *evnt.text.text;
			std::cout << c;
			stream.push_back(c);

			std::cout << stream;
			stream.clear();
			SDL_StopTextInput();

			break;
		}
	}
}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		processInput();
	}
}

void MainGame::initSystems()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_CreateWindow("Beli", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
}

