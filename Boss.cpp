#include "Boss.h"

Boss::Boss(const LoaderParams* pParams, int scale, int frame) :
	SDLGameObject(pParams, scale) , frames(frame)
{}

void Boss::draw()
{
	SDLGameObject::draw();
}

void Boss::dead()
{
	
}

void Boss::update(std::string trangThai)
{
	if (trangThai == "trungDan")
	{
		currentRow = 2;
	}

	if (currentRow == 2)
	{
		currentFrame = (SDL_GetTicks() / 200) % frames;

		if (currentFrame == frames - 1)
		{
			currentRow = 0;
		}
	}
	else if (trangThai == "de")
	{
		currentRow = 1;
		currentFrame = (SDL_GetTicks() / 200) % frames;

		if (currentFrame == frames - 1)
		{
			currentRow = 0;
		}
	}
	else
	{
		currentRow = 0;
		currentFrame = (SDL_GetTicks() / 200) % frames;
	}
	

	SDLGameObject::update();
}

void Boss::clean()
{
	SDLGameObject::clean();
}
