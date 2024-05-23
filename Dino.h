#pragma once
#include "SDLGameObject.h"
#include "Sound.h"

class Dino : public SDLGameObject
{
public:
	Dino(const LoaderParams* pParams,int scale,int frame);
	Dino(const LoaderParams* pParams, int scale, int frame, int gr);
	virtual void draw();
	virtual void update();
	virtual void clean();
	void dead();

	void changeRow0() { currentRow = 0; }
	void changeRow2() { currentRow = 2; }
private:
	int ground;
	int frames;
	void Jump();
	Sound DinoSound;
};
