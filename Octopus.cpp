#include "Octopus.h"
#include "InputHandle.h"
#include "ChangeCharacterState.h"

Octopus::Octopus(const LoaderParams* pParams, int scale, int frame) :
	SDLGameObject(pParams, scale), frames(frame)
{}

void Octopus::draw()
{
	currentFrame = (SDL_GetTicks() / 200) % frames;
	SDLGameObject::draw();
}

void Octopus::bay()
{
	if (m_position.getX() <= 300)
	{
		tocDo *=-1;
	}
	if (m_position.getX() > 2000)
	{
		tocDo *=-1;
	}

	m_velocity.setX(tocDo);
	SDLGameObject::update();
}

void Octopus::update()
{
	SDLGameObject::update();
}

void Octopus::clean()
{
	SDLGameObject::clean();
}
