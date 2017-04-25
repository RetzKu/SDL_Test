#include "Game.h"



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
			Mouse.x(evnt.motion.x);
			Mouse.y(evnt.motion.y);
			break;
		case SDL_TEXTINPUT:
			/*if (_x < 250 && _y < 250)
			{
				
				Typing = true;
				c = *evnt.text.text;
				std::cout << c;
				stream.push_back(c);

				if (c == ' ')
				{
					std::cout << stream;
					stream.clear();
					Typing = false;
				}
			}
			else if(_x > 250 && _y > 250)
			{ 
				SDL_StopTextInput();
			}
			break;*/
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

