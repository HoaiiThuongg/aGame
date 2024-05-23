#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include "Bullet.h";
#include "Spaceship.h";
#include "PhanDien.h"
#include "Background.h"
#include "Spaceship.h"
#include "TTF.h"
#include "Sound.h"
#include "DrawPic.h"

class GameObject;

class SpaceState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }
private:
	static const std::string s_playID;

	std::vector<GameObject*> button;
	std::vector<Bullet*> m_bullet;
	std::vector<Bullet*> m_danDuoi;
	std::vector<PhanDien*> m_thuong;
	std::vector<PhanDien*> m_moi;
	std::vector<PhanDien*> m_xanhchuoi;

	Background spaceBgr;
	Spaceship* spaceship;
	DrawPic* gun;
	TTF spaceWrite;
	Sound SSSound;
	DrawPic* money;
	PhanDien* bigOc;

	static void Back();

	bool music = true;

	void lenThienDang()
	{
		if (music)
		{
			SSSound.pause();
			SSSound.PlayBye();
			music = false;
		}
	}
	void Ban(int loaiDan);

	bool checkVa(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

	enum
	{
		normal = 0,
		bigBoss = 1,
		die = 2
	};

	bool banDanDuoi = false;
	int dem = 0;
	int gioihan = 100;
	int mauBig = 100;
	int cheDo = normal;
	int kill = 0;
};