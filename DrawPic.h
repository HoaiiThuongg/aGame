#pragma once
#include "SDLGameObject.h"

class DrawPic :public SDLGameObject
{
public:
	DrawPic(const LoaderParams* pParams, int scale, int frame);
	DrawPic(const LoaderParams* pParams, int scale, int frame ,std::string id);
	virtual void update();

	void updateMoney();
	void updateDie();


	void updateBossState();
	void updateChuot(int x, int y);
	void changeFrame() { currentFrame=1; }
	void Cam();
	void CamChuong();
	void Xanh();
	void XanhChuong();

	virtual void draw();
	void drawFlip();
	virtual void clean();

	void drawKey();
	bool isKey = true;
	bool isFrame0()
	{
		return currentFrame == 0;
	}
	bool raChuong = false;
	std::string ID() { return iD; }
	bool appear = true;

private:
	std::string iD="";
	int frames;
	SDL_RendererFlip r = SDL_FLIP_NONE;
};