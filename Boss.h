#pragma once
#include "SDLGameObject.h"

class Boss : public SDLGameObject
{
public:
	Boss(const LoaderParams* pParams, int scale, int frame);
	virtual void draw();
	virtual void update(std::string trangThai);
	virtual void clean();
	void dead();
private:
	int frames;
	std::string doo;
};
