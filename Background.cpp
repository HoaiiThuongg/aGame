#include "Background.h"
#include "InputHandle.h"

void Background::load(int w, int h, std::string fileName, std::string ID)
{
	width = w;
	height = h;
	path = fileName;
	id = ID;
	TextureManager::Instance()->load(path, id, Game::Instance()->getRenderer());
	speed = 5;
}

void Background::load(int w, int h, std::string fileName, std::string ID,int speeds)
{
	width = w;
	height = h;
	path = fileName;
	id = ID;
	TextureManager::Instance()->load(path, id, Game::Instance()->getRenderer());
	speed = speeds;
}

void Background::load(int w, int h, std::string file, std::string ID, int speeds, int x, int y)
{
	width = w;
	height = h;
	path = file;
	id = ID;
	TextureManager::Instance()->load(path, id, Game::Instance()->getRenderer());
	speed = 5;
	xPos = w-x; yPos = h-y;
}

void Background::updateXanh()
{
	xPos -= speed;
	yPos -= speed;

	if (xPos <+95 >= width>=0)
	{
		xPos = width - 95;
		yPos = height - 60;
	}
}
void Background::drawXanh()
{
	TextureManager::Instance()->drawXanh(id,xPos,yPos,95,60, Game::Instance()->getRenderer(), SDL_FLIP_NONE);
}

void Background::draw()
{
	TextureManager::Instance()->drawBgr(id, xPos, yPos, 800, 640,Game::Instance()->getRenderer(),SDL_FLIP_NONE);
}

void Background::drawMau(int x,int y)
{
	TextureManager::Instance()->drawMau(id, x, y, xPos, yPos,width/2,height,
		Game::Instance()->getRenderer(), SDL_FLIP_NONE);
}

void Background::update()
{
	xPos += speed;

	if (xPos + 800 >= width)
	{
		xPos = 0;
	}
}

void Background::updateMau(int speed)
{
	xPos += speed;

	if(xPos >= width/2)
	die = true;
}

void Background::dead(){}

void Background::clean()
{
	TextureManager::Instance()->clearFromTextureMap(id);
}
