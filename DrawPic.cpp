#include "DrawPic.h"
#include "Spaceship.h"

DrawPic::DrawPic(const LoaderParams* pParams, int scale, int frame) :
	SDLGameObject(pParams, scale), frames(frame)
{}

DrawPic::DrawPic(const LoaderParams* pParams, int scale, int frame,std::string id) :
	SDLGameObject(pParams, scale), frames(frame),iD(id)
{}

void DrawPic::update()
{
	currentFrame = (SDL_GetTicks() / 200) % frames;
	SDLGameObject::update();
}

void DrawPic::updateMoney()
{
	if (m_position.getX() + width * scale < 0 || isKey == false)
	{
		m_position.setX(2000);
		m_position.setY(SDL_GetTicks() % 600 +50);
		isKey = true;
	}
	m_velocity.setX(-2);
	currentFrame = (SDL_GetTicks() / 200) % frames;
	SDLGameObject::update();
}

void DrawPic::updateBossState()
{
	if(currentFrame != 0)
	{
		bool ay = false;
		if (currentFrame == 1) ay = true;
		currentFrame = (SDL_GetTicks() / 1000) % frames;
		if (ay && currentFrame == 0 ) currentFrame = 1;
		SDLGameObject::update();
	}
}

void DrawPic::Cam()
{
	m_velocity.setY(5);
	currentFrame = (SDL_GetTicks() / 200) % frames;
	if (m_position.getY() >= 425)
	{
		raChuong = true;
		m_position.setY(425);
		currentRow = 1;
	}
	if (!isKey)
	{
		m_position.setY(10); isKey = true; raChuong = false; currentRow = 0;
	}
	SDLGameObject::update();
}

void DrawPic::CamChuong()
{
	if (currentRow == 0)
	{
		isKey = true;
		bool is(false);
		if (currentFrame == 0) is = true;
		currentFrame = (SDL_GetTicks() / 500) % frames;
		if (is && currentFrame == frames - 1) currentFrame = 0;
		if (currentFrame == frames - 1) currentRow++;
	}
	else if (currentRow == 1)
	{
		currentFrame = (SDL_GetTicks() / 200) % frames;
		m_velocity.setX(5);
	}

	if (!isKey)
	{
		m_position.setX(120); currentRow = 0; currentFrame = 0; m_velocity.setX(0);
	}
	SDLGameObject::update();
}

void DrawPic::Xanh()
{
	m_velocity.setY(5);
	currentFrame = (SDL_GetTicks() / 200) % frames;
	if (m_position.getY() >= 100)
	{
		raChuong = true;
		m_position.setY(100);
	}
	if (!isKey)
	{
		m_position.setY(10); isKey = true; raChuong = false; currentRow = 0;
	}
	SDLGameObject::update();
}

void DrawPic::XanhChuong()
{
	currentFrame = (SDL_GetTicks() / 200) % frames;

	m_velocity.setX(5);
	m_velocity.setY(3);
	
	if (m_position.getY()>=425)
	{
		isKey = false;
	}
	SDLGameObject::update();
}



void DrawPic::draw()
{
	if (isKey)
	{
		SDLGameObject::draw(r);
	}
}

void DrawPic::updateDie()
{
	m_velocity.setY(-3);
	currentRow = 2;
	currentFrame = (SDL_GetTicks() / 200) % frames;
	if (m_position.getY() <= 320)
	{
		m_position.setY(320);
	}
	SDLGameObject::update();
}

void DrawPic::updateChuot(int x, int y)
{
	if (x != m_position.getX() || y != m_position.getY())
	{
		currentRow = 0;
	}
	else
	{
		currentRow = 1;
	}
	m_position.setX(x);
	m_position.setY(y);
	
	currentFrame = (SDL_GetTicks() / 200) % frames;
	SDLGameObject::update();
}

void DrawPic::drawFlip()
{
	if (Spaceship::i == 1)
	{
		r = SDL_FLIP_HORIZONTAL;
	}
	else
	{
		r = SDL_FLIP_NONE;
	}
	SDLGameObject::draw(r);
}

void DrawPic::drawKey()
{
	if (m_position.getX() <= 0 || isKey == false)
	{
		m_position.setX(800);
		isKey = true;
	}
	m_velocity.setX(-5);
	SDLGameObject::update();
}

void DrawPic::clean()
{
	SDLGameObject::clean();
}