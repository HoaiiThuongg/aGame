#include "Dino.h"
#include "InputHandle.h"
#include "ChangeCharacterState.h"

std::string jump = "none";
int maxJump = 250;
bool ban = false;
int jumpNhay = 8;

Dino::Dino(const LoaderParams* pParams,int scale,int frame) :
	SDLGameObject(pParams,scale),frames(frame)
{
	ground = 475;
}

Dino::Dino(const LoaderParams* pParams, int scale, int frame,int gr) :
	SDLGameObject(pParams, scale), frames(frame),ground(gr)
{}

void Dino::Jump()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		if (m_position.getY() == ground - height*scale)
		{
			jump = "jump";
			DinoSound.PlayJumpSound();
		}
	}
}

void Dino::draw()
{
	SDLGameObject::draw();
}

void Dino::dead() 
{
	m_velocity.setY(-4);
	m_velocity.setX(0);
	currentRow = 2;
	currentFrame = 0;
	SDLGameObject::update();
}

void Dino::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	Jump();
	currentFrame = (SDL_GetTicks() / 200) % frames;
	if (jump == "jump")
	{
		m_velocity.setY(-jumpNhay);
		if (m_position.getY() < maxJump) jump = "down";
	}

	else if (jump == "down")
	{
		m_velocity.setY(jumpNhay);
		if (m_position.getY() > ground - height * scale)
		{
			jump = "none";
			m_velocity.setY(0);
		}
	}

	if (jump == "none")
	{
		m_position.setY(ground - height * scale);

	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(5);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-5);
	}

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

	SDLGameObject::update();
}

void Dino::clean()
{
	DinoSound.Clean();
	SDLGameObject::clean();
}
