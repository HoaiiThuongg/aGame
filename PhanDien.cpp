#include "PhanDien.h"

int PhanDien::updateSpeed = 0;
int PhanDien::updateSpeedBig = 0;

PhanDien::PhanDien(const LoaderParams* pParams, int scale,int frame,int speeds) :
	SDLGameObject(pParams, scale),frames(frame),speed(speeds)
{
}

void PhanDien::update()
{
	if (switchh)
	{
		currentRow = 1;

		if (m_position.getX() +width > 800 || m_position.getX()<0) {
			swX = -swX;
		}
		if (m_position.getY() < 0 || m_position.getY() + height > 640) {
			swY = -swY;
		}

		m_velocity.setX(swX);
		m_velocity.setY(swY);
		if (m_position.getX() + width * scale >= 800)
		{
			m_position.setX(800 - width * scale);
		}
		if (m_position.getX() <= 0)
		{
			m_position.setX(0);
		}
		if (m_position.getY() + height * scale >= 640)
		{
			m_position.setY(640 - height * scale);
		}
		if (m_position.getY() <= 0)
		{
			m_position.setY(0);
		}
	}
	else
	{
		m_velocity.setX(-speed - updateSpeed);
	}

	if (!switchh && m_position.getX() < -50)
	{
		appear = false;
	}
	currentFrame = (SDL_GetTicks() / 200) % frames;
	SDLGameObject::update();
}

void PhanDien::updateCatus()
{
	if (switchh)
	{
		currentRow = 1;
	}

	if (m_position.getX() < -width )
	{
		m_position.setX(1500);
		appear = true;
	}

	m_velocity.setX(-speed - updateSpeed);
	currentFrame = (SDL_GetTicks() / 200) % frames;
	SDLGameObject::update();
}

void PhanDien::updateBigOcState()
{
	m_velocity.setX(-speed - updateSpeed);
	currentFrame = (SDL_GetTicks() / 200) % frames;
	SDLGameObject::update();
	if (m_position.getX() < 0) appear = false;
}

void PhanDien::updateBigOc()
{
	if (m_position.getX() >=500)
	{
		m_velocity.setX(-speed - updateSpeedBig);
		m_velocity.setY(0);
	}
	else
	{
		m_velocity.setX(0);
		if (m_position.getY() < 0 || m_position.getY() > 640 - height * scale)
		{
			speed = -speed;
			updateSpeedBig = -updateSpeedBig;
		}
		m_velocity.setY( speed + updateSpeedBig);
	}
	currentFrame = (SDL_GetTicks() / 200) % frames;
	SDLGameObject::update();
}

void PhanDien::updateSpecial(int y)
{
	if (switchh)
	{
		currentRow = 1;

		if ( m_position.getX() + width > 800 || m_position.getX()<0) {
			swX = -swX;
		}
		if (m_position.getY() < 0 || m_position.getY() + height > 640) {
			swY = -swY;
		}

		m_velocity.setX(swX);
		m_velocity.setY(swY);
		if (m_position.getX() + width * scale >= 800)
		{
			m_position.setX(800 - width * scale);
		}
		if (m_position.getX() <= 0)
		{
			m_position.setX(0);
		}
		if (m_position.getY() + height * scale >= 640)
		{
			m_position.setY(640 - height * scale);
		}
		if (m_position.getY() <= 0)
		{
			m_position.setY(0);
		}
	}

	if (!switchh && m_position.getX() < width)
	{
		appear = false;
	}
	currentFrame = (SDL_GetTicks() / 200) % frames;

	if(!switchh)
	{
		if (m_position.getX() < width)
		{
			appear = false;
		}
		currentFrame = (SDL_GetTicks() / 200) % frames;
		m_velocity.setX(-speed - updateSpeed);

		if (y > m_position.getY())
		{
			m_velocity.setY(1);
		}
		else if (y < m_position.getY())
		{
			m_velocity.setY(-1);
		}
		else
		{
			m_velocity.setY(0);
		}
	}

	
	SDLGameObject::update();
}

void PhanDien::dead1() {}

void PhanDien::draw()
{
	if(appear)
	SDLGameObject::draw();
}

void PhanDien::clean()
{
	PDSound.Clean();
	SDLGameObject::clean();
}

void PhanDien::diRa()
{
	m_velocity.setY(-50);
	SDLGameObject::update();
}