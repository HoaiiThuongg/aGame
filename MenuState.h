#pragma once
#include"GameState.h"
#include <vector>
#include "GameObject.h"
#include "TextureManager.h"
#include "TTF.h"
#include "Background.h"
#include "DrawPic.h"
#include "Sound.h"
#include "Spaceship.h"
#include "Button.h"

class MenuState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }
private:
	Background bgrMenu;
	TTF menuWrite;
	DrawPic* avatar;
	Sound menuSound;
	DrawPic* dino;
	Spaceship* phiHanhGia;

	DrawPic* thu;
	Button* xbutton;

	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
	static void s_menuToDino();
	static void s_menuToSpace();
	static void s_menuToChangeCharacter();
	static void s_exitFromMenu();
	static void s_menuToEnterName();
	static void s_HuongDan();
	static void s_DieuTra();
	static void s_Music();
	static void s_Thu();
	static void returnn();

	enum
	{
		koThu = 0,
		Thu = 1
	};
	static int trangThai;
};