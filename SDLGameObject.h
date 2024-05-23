#pragma once
#include "GameObject.h"
#include "Vector2D.h"
#include "LoaderParams.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	SDLGameObject(const LoaderParams* pParams,int s);
	virtual void draw();
	virtual void update();
	virtual void clean();

	virtual void draw(SDL_RendererFlip r);

	Vector2D& getPosition() { return m_position; }
	int getWidth() { return width*scale; }
	int getHeight() { return height*scale; }

protected:
	int scale;
	int width;
	int height;
	int currentRow;
	int currentFrame;
	std::string textureID;

	Vector2D m_velocity;
	Vector2D m_position;
	Vector2D m_acceleration;
};