#pragma once
#include "GameState.h"
#include "TTF.h"
#include "DrawPic.h"
#include "Button.h"
#include "Sound.h"

class GameObject;

class EnterName : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_enterNameID; }

	static std::string name;
private:
	DrawPic* bgr;
	Button* back;
	TTF code;
	Sound ENSound;

	static void Back();

	static const std::string s_enterNameID;
	Uint32 frameStart, frameTime;
	TTF_Font* font;
};