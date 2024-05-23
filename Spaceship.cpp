#include "Spaceship.h"
#include "InputHandle.h"

int Spaceship::i = 0;

Spaceship::Spaceship(const LoaderParams* pParams, int scale,int frame,int speeds) :
	SDLGameObject(pParams, scale),frames(frame),speed(speeds)
{}

void Spaceship::HandleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-speed);
		currentRow = 1;
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(speed);
		currentRow = 1;
		r = SDL_FLIP_NONE;
		i = 0;
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-speed);
		currentRow = 1;
		r = SDL_FLIP_HORIZONTAL;
		i = 1;
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(speed);
		currentRow = 1;
	}

	if (!TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)
		&& !TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)
		&& !TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)
		&& !TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		currentRow = 0;
	}
}

void Spaceship::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	if (m_position.getX() +width*scale >= 800)
	{
		m_position.setX(800 - width *scale);
	}
	if (m_position.getX() <= 0)
	{
		m_position.setX(0);
	}
	if (m_position.getY() + height*scale >= 640)
	{
		m_position.setY(640 - height*scale);
	}
	if (m_position.getY() <= 0)
	{
		m_position.setY(0);
	}
	HandleInput();
	SDLGameObject::update();
}

void Spaceship::draw()
{
	currentFrame = (SDL_GetTicks() / 200) % frames;
	SDLGameObject::draw(r); 
}

void Spaceship::clean()
{
	SDLGameObject::clean();
}

void Spaceship::dead()
{
	m_velocity.setY(-3);
	m_velocity.setX(0);
	currentRow = 2;
	currentFrame = 0;
	SDLGameObject::update();
}