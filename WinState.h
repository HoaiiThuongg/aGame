#pragma once
#include "GameState.h"
#include "TTF.h"
#include "Background.h"
#include "Button.h"

class GameObject;

class WinState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_winState; }

	static std::string name;
private:
	Background bgr;
	Sound WSound;
	static const std::string s_winState;
	std::vector<Button*> button;

	static void s_gameOverToMain();
	static void s_exit();
};