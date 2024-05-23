#pragma once
#include "SDLGameObject.h"

class Spaceship : public SDLGameObject
{
public:
	Spaceship(const LoaderParams* pParams, int scale,int frame,int speeds);
	virtual void draw();
	virtual void update();
	virtual void clean();
	void dead();
	bool quayPhai()
	{
		if (r == SDL_FLIP_HORIZONTAL) return false;
		return true;
	}
	int returnscale()
	{
		return scale;
	}
	static int i;

private:
	SDL_RendererFlip r = SDL_FLIP_NONE;
	int speed;
	int frames;
	void HandleInput();
};

typedef Spaceship TheSpaceship;