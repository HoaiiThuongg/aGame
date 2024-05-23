#include "WinState.h"
#include "TextureManager.h"
#include "MenuState.h"

const std::string WinState::s_winState = "winState";

void WinState::update()
{
	for (int i = 0; i < button.size(); i++)
	{
		button[i]->update();
	}
}

void WinState::render()
{
	bgr.draw();
	for (int i = 0; i < button.size(); i++)
	{
		button[i]->draw();
	}
}

bool WinState::onEnter()
{
	WSound.pause();
	WSound.PlayWSound();
	if (!TheTextureManager::Instance()->load("image/WinState.png",
		"bgrWS", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

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

	bgr.load(800, 640, "image/WinState.png", "bgrWS");
	Button* button1 = new Button(new LoaderParams(70, 260,
		64, 32, "menu"), 2, s_gameOverToMain);
	Button* button2 = new Button(new LoaderParams(590, 260,
		64, 32, "exit"), 2, s_exit);

	button.push_back(button1);
	button.push_back(button2);

	return true;
}

bool WinState::onExit()
{
	WSound.resume();
	WSound.Clean();
	bgr.clean();
	for (int i = 0; i < button.size(); i++)
	{
		button[i]->clean();
	}
	button.clear();
	return true;
}

void WinState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new
		MenuState());
}
void WinState::s_exit()
{
	TheGame::Instance()->clean();
}