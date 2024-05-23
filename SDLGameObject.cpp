#include "SDLGameObject.h"
#include "TextureManager.h"
#include "InputHandle.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) :
	GameObject(pParams), m_position(pParams->getX(), pParams->getY()), m_velocity(0, 0)
{
	width = pParams->getWidth();
	height = pParams->getHeight();
	textureID = pParams->getTextureID();
	currentRow = 0;
	currentFrame = 0;
	scale = 1;
}

SDLGameObject::SDLGameObject(const LoaderParams* pParams, int s) :
	GameObject(pParams), m_position(pParams->getX(), pParams->getY()), m_velocity(0, 0)
{
	width = pParams->getWidth();
	height = pParams->getHeight();
	textureID = pParams->getTextureID();
	currentRow = 0;
	currentFrame = 0;
	scale = s;
}

void SDLGameObject::draw()
{
	if (m_velocity.getX() < 0)
	{
		TextureManager::Instance()->drawFrame(textureID,
			(Uint32)m_position.getX(), (Uint32)m_position.getY(),
			width, height,scale, currentFrame, currentRow,
			TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
	}
	else
	{
		TextureManager::Instance()->drawFrame(textureID,
			(Uint32)m_position.getX(), (Uint32)m_position.getY(),
			width, height,scale, currentFrame, currentRow,
			TheGame::Instance()->getRenderer());
	}
}

void SDLGameObject::draw(SDL_RendererFlip r)
{
	TextureManager::Instance()->drawFrame(textureID,
	(Uint32)m_position.getX(), (Uint32)m_position.getY(),
	width, height, scale, currentFrame, currentRow,
	TheGame::Instance()->getRenderer(),r);
}

void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
}

void SDLGameObject::clean()
{
	TextureManager::Instance()->clearFromTextureMap(textureID);
}