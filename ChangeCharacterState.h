#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include "TTF.h" 
#include "Sound.h"
#include "DrawPic.h"

class GameObject;

class ChangeCharacterState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_characterID; }

	static std::string pathID;
	static std::string pathPhgID;
	static int phgWidth, phgHeight, phgFrames;
	static std::string pathAvaID;
	static std::string pathSpaceID;
	static int width, height,frames;
	static int state;
	static int speed;

	static int phg2Ok;
	static int phg3Ok;
	static int phg4Ok;
	static int kl2Ok;
	static int gun2Ok;
	static int loaiDan;
	static int menuw, menuh;

	static std::string pathGunID;
	static int widthG, heightG, framesG;
private:
	static const std::string s_characterID;
	TTF chaWrite;
	Sound CCSound;
	static DrawPic* here;

	static void phg1();
	static void phg2();
	static void phg3();
	static void phg4();

	static void KLCam();
	static void KLXanh();

	static void gun01();
	static void gun02();
	
	static void nv();
	static void kl();
	static void dan();

	static void Back();
	std::vector<GameObject*> button;
	std::vector<GameObject*> state1;
	std::vector<GameObject*> state2;
	std::vector<GameObject*> state3;

	enum CC_state
	{
		ChuaMua = 0,
		DaMua = 1,
		DaXuLy = 2
	};
};