#pragma once
#include "TextureManager.h"
#include "SDLGameObject.h"

class Background
{
public:
	void load(int w, int h,std::string file,std::string ID);
	void load(int w, int h, std::string file, std::string ID,int speeds);
	void load(int w, int h, std::string file, std::string ID, int speeds, int x, int y);

	void draw();
	void drawXanh();
	void drawMau(int x, int y);

	void update();
	void updateMau(int speed);
	void updateXanh();

	void clean();
	void dead();

	int returnMau()
	{
		return xPos;
	}

	int speed;
	bool isDie() { return die; }

private:
	int scale = 1;
	bool die = false;
	int xPos=0,yPos=0, width, height;
	std::string path;
	std::string id;
};
