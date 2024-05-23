#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "DrawPic.h"
#include "Button.h"
#include "InputHandle.h"
#include "TTF.h"
#include "BossState.h"
#include "MenuState.h"
#include "SnakeState.h"

class GameObject;

class DieuTraState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_dieuTraID; }
private:
	static void TL1();
	static void TL2();
	static void TL3();
	static void TL4();
	static void Next();

	static void Back()
	{
		TheGame::Instance()->getStateMachine()->changeState(new MenuState);
	}

	static void toSnake()
	{
		TheGame::Instance()->getStateMachine()->changeState(new SnakeState);
	}

	static void Return()
	{
		state = 0;
	}

	static void m_toBossState()
	{
		TheGame::Instance()->getStateMachine()->changeState(new BossState);
	}

	static const std::string s_dieuTraID;
	std::vector<Button*> m_dieuTra;
	std::vector<GameObject*> m_hinhAnh;

	static int s1Ok, s2Ok, s3Ok, s4Ok;
	static int state;

	Button* returnn;
	Button* snake;
	Button* toBossState;
	Button* next;

	TTF DTWrite;
	DrawPic* key1;
	DrawPic* key1Next;
	DrawPic* key2;
	DrawPic* key3;
	DrawPic* key4;
	DrawPic* day1;
	DrawPic* day2;
	DrawPic* day3;

	DrawPic* chuot;
	DrawPic* bgr;
	Vector2D* mouse = TheInputHandler::Instance()
		->getMousePosition();

	enum dieuTra_state
	{
		chuaMo = 0,
		MoNhungChuaMua = 1,
		DaMua = 2
	};
};