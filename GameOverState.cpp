#include "GameOverState.h"
#include "Game.h"
#include "DinoState.h"
#include "MenuState.h"
#include "TextureManager.h"
#include "Button.h"
#include "SpaceState.h"
#include "DrawPic.h"
#include "TTF.h"

std::string GameOverState::PathNguoiRaDi;
int GameOverState::width;
int GameOverState::height;
int GameOverState::frame;

const std::string GameOverState::s_gameOverID = "GAMEOVER";
void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new
		MenuState());
}
void GameOverState::s_exit()
{
	TheGame::Instance()->clean();
}
void GameOverState::s_menuToSpace()
{
	TheGame::Instance()->getStateMachine()->changeState(new SpaceState());
}

void GameOverState::s_menuToDino()
{
	TheGame::Instance()->getStateMachine()->changeState(new DinoState());
}
bool GameOverState::onEnter()
{
	bgr = new DrawPic(new LoaderParams(0, 0, 800, 640, "bgrGO"), 1, 1);
	//GOSSound.PlayBye();
	GOSSound.resume();
	if (!TheTextureManager::Instance()->load("image/Menu.png",
		"menu", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/Quit.png",
		"exit", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/CoinPlace.png",
		"cPlace", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/KeyPlace.png",
		"kPlace", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Sky.jpg",
		"bgrGO", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load(PathNguoiRaDi,
		"nguoiRaDi", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/MainPlay.png",
		"playSpace", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/DinoState.png",
		"playDino", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	nguoiRaDi = new DrawPic(new LoaderParams(350, 640, width, height, "nguoiRaDi"),3,frame);

	GameObject* button1 = new Button(new LoaderParams(150, 250,
		64, 32, "menu"),2, s_gameOverToMain);
	GameObject* button2 = new Button(new LoaderParams(150, 400,
		64, 32, "exit"),2, s_exit);
	GameObject* button3 = new Button(new LoaderParams(500, 200, 96,
		64, "playSpace"), 2, s_menuToSpace);
	GameObject* button4 = new Button(new LoaderParams(500, 350, 53,
		32, "playDino"), 3, s_menuToDino);

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	m_gameObjects.push_back(button3);
	m_gameObjects.push_back(button4);

	GameObject* coinPlace = new DrawPic(new LoaderParams(400, 30, 64, 32, "cPlace"), 2, 1);
	GameObject* keyPlace = new DrawPic(new LoaderParams(600, 30, 64, 32, "kPlace"), 2, 1);
	m_gameObjects.push_back(coinPlace);
	m_gameObjects.push_back(keyPlace);
	std::cout << "entering GameOverState\n";
	return true;
}

bool GameOverState::onExit()
{
	bgr->clean();
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	nguoiRaDi->clean();
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	std::cout << "exiting GameOverState\n";
	return true;
}

void GameOverState::update()
{
	bgr->update();
	nguoiRaDi->updateDie();
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void GameOverState::render()
{
	bgr->draw();
	nguoiRaDi->draw();
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	goWrite.WriteNumber(TTF::coin, 430, 53);
	goWrite.WriteNumber(TTF::food, 650, 53);
}