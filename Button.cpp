#include "Button.h"
#include "SDLGameObject.h"
#include "InputHandle.h"

Button::Button(const LoaderParams* pParams, void (*callback)()) 
	: SDLGameObject(pParams), m_callback(callback)
{
	currentFrame = MOUSE_OUT; // start at frame 0
}

Button::Button(const LoaderParams* pParams,int s, void (*callback)()
) : SDLGameObject(pParams,s), m_callback(callback)
{
	currentFrame = MOUSE_OUT; // start at frame 0
}

void Button::draw()
{
	SDLGameObject::draw(); // use the base class drawing
}

void Button::update()
{
	Vector2D* pMousePos = TheInputHandler::Instance()
		->getMousePosition();
	if (pMousePos->getX() < (m_position.getX() + width*scale)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + height*scale)
		&& pMousePos->getY() > m_position.getY())
	{
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)
			&& m_bReleased)
		{
			currentFrame = CLICKED;
			m_callback(); // call our callback function
			m_bReleased = false;
		}
		else if (!TheInputHandler::Instance()
			->getMouseButtonState(LEFT))
		{
			m_bReleased = true;
			currentFrame = MOUSE_OVER;
		}
	}
	else
	{
		currentFrame = MOUSE_OUT;
	}
}


void Button::clean()
{
	SDLGameObject::clean();
}