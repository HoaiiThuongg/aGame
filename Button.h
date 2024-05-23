#pragma once
#include "SDLGameObject.h"

class Button : public SDLGameObject
{
public:
	Button(const LoaderParams* pParams, void (*callback)());
	Button(const LoaderParams* pParams,int s, void (*callback)());
	virtual void draw();
	virtual void update();
	virtual void clean();
	void (*m_callback)();
	int returnRow()
	{
		return currentRow;
	}
	void changeRow0()
	{
		currentRow = 0;
	}
	void changeRow1()
	{
		currentRow = 1;
	}
	void changeRow2()
	{
		currentRow = 2;
	}
private:
	bool m_bReleased;
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
};