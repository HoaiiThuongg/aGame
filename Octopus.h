#pragma once
#pragma once
#include "SDLGameObject.h"

class Octopus : public SDLGameObject
{
public:
	Octopus(const LoaderParams* pParams, int scale, int frame);
	virtual void draw();
	virtual void update();
	virtual void clean();
	void bay();
	int frame() { return currentFrame; }
private:
	int frames;
	int tocDo = -5;
};