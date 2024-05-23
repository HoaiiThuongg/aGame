#pragma once
#include "GameState.h"
#include "TTF.h"
#include <iostream>
#include <vector>
#include "DrawPic.h"
#include "Sound.h"

class GameObject;
class GameOverState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_gameOverID; }
	bool ok = false;

	static std::string PathNguoiRaDi;
	static int width;
	static int height;
	static int frame;

private:
	DrawPic* bgr;
	DrawPic* nguoiRaDi;
	Sound GOSSound;
	static void s_gameOverToMain();
	static void s_exit();
	static void s_menuToDino();
	static void s_menuToSpace();
	static const std::string s_gameOverID;
	std::vector<GameObject*> m_gameObjects;
	TTF goWrite;
};