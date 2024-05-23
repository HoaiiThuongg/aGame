#include "Bullet.h"
#include "InputHandle.h"

int Bullet::banTruot = 0;

Bullet::Bullet(const LoaderParams* pParams, int scale) :
	SDLGameObject(pParams, scale)
{
	frames = 1;
	speed = 10;
}

Bullet::Bullet(const LoaderParams* pParams, int scale,int speeds) :
	SDLGameObject(pParams, scale), speed(speeds),frames(1)
{
}

Bullet::Bullet(const LoaderParams* pParams, int scale, int speeds,int fr) :
	SDLGameObject(pParams, scale), speed(speeds),frames(fr)
{
}

void Bullet::update()
{
	if (m_position.getX() > 800 || m_position.getX() < 0 )
	{
		banTruot++;
		validDan = false;
	}

	if (validDan)
	{
		m_velocity.setX(speed);
		currentFrame = (SDL_GetTicks() / 200) % frames;
		SDLGameObject::update();
	}

	if (banTruot >= 15)
	{
		banTruot = 0;
	}
}

void Bullet::danDoc()
{
	if (m_position.getY() >= 450 )
	{
		validDan = false;
	}

	if (validDan)
	{
		m_velocity.setY(speed);
		SDLGameObject::update();
	}

}

void Bullet::draw()
{
	if(validDan)
	SDLGameObject::draw();
}

void Bullet::clean()
{
	if (!validDan)
	SDLGameObject::clean();

	BulletSound.Clean();
}
