#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include "Background.h"
#include "Dino.h"
#include "PhanDien.h"
#include "TTF.h"
#include "Octopus.h"
#include "Bullet.h"
#include "DrawPic.h"
#include "Sound.h"

class GameObject;

class DinoState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	static bool choi ;
	virtual std::string getStateID() const { return s_playID; }
private:
	Background bgrDino;
	Dino* dino;
	PhanDien* catus;
	Octopus* oc;
	Octopus* bay;
	TTF dinoWrite;
	DrawPic* key;
	Sound DSSound;

	std::string chet = "song";

	static void Back();
	static const std::string s_playID;
	std::vector<GameObject*> m_dinoButton;
	std::vector<GameObject*> place;
	std::vector<Bullet*> m_dan;
	std::vector<Bullet*> m_doc;

	bool checkVa(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
	bool music = true;
	void lenThienDang()
	{
		if(music)
		{
			DSSound.pause();
			DSSound.PlayLenThienDangSound();
			music = false;
		}
	}
	void bye()
	{
		if(music)
		{
			DSSound.pause();
			DSSound.PlayBye();
			music = false;
		}
	}

	int doKho = 0;
};