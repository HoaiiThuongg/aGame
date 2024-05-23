#include "Game.h"
#include"TextureManager.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "InputHandle.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "DinoState.h"
#include "TTF.h"
#include "EnterName.h"

SDL_Event Game::event;

Game* Game::s_pInstance = 0;

GameStateMachine* m_pGameStateMachine;

Game::Game()
{}

Game::~Game()
{}


bool Game::init(const char* title, int xpos, int ypos, int width,
	int height, int flags)
{
	int fl = 0;
	if(flags) fl = 1;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		win = SDL_CreateWindow("Thuong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, fl);
		renderer = SDL_CreateRenderer(win, -1, 0);

		isRunning = true;
	}
	else
	{
		isRunning = false;
		return false;
	}

	TheInputHandler::Instance()->initialiseJoysticks();
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());
	gameSound.PlayMenuSound();
	return true;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	m_pGameStateMachine->render();
	SDL_RenderPresent(renderer);
}

void Game::update()
{
	m_pGameStateMachine->update();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new MenuState());
	}
}

void Game::clean()
{
	gameSound.Clear();
	gameSound.Clean();
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}