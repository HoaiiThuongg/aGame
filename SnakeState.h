#pragma once
#include "GameState.h"
#include "TTF.h"
#include "DrawPic.h"
#include "Button.h"
#include "Snake.h"
#include "Button.h"
#include "TTF.h"
#include "Sound.h"

class GameObject;

class SnakeState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_SnakeStateID; }

private:
	Snake* head;
	Snake* food;
	Snake* no;
	Button* back;

	Sound SnakeSound;
	TTF SnakeWrite;
	int eat = 0;
	int people = 0;
	int x = 0, y = 0;
	int speed = 5;

	static void Back();

	bool checkVa(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
	static const std::string s_SnakeStateID;

	std::vector<Snake*> tail;
	std::vector<Snake*> bom;
	std::vector<DrawPic*> anh;
};