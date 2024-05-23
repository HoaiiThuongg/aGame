#pragma once
#include "SDL.h"
#include <vector>
#include "Vector2D.h"
#include "SDLGameObject.h"

const int m_joystickDeadZone = 10000;
enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* s_pInstance;

	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void update();
	void clean();

	void initialiseJoysticks();
	bool joysticksInitialised() {
		return m_bJoysticksInitialised;
	}

	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);

	bool getButtonState(int joy, int buttonNumber)
	{
		return m_buttonStates[joy][buttonNumber];
	}

	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}

	Vector2D* getMousePosition()
	{
		return m_mousePosition;
	}

	bool isKeyDown(SDL_Scancode key);



private:
	Vector2D* m_mousePosition = new Vector2D(0, 0);
	std::vector<SDL_Joystick*> m_joysticks;
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	bool m_bJoysticksInitialised;
	std::vector<std::vector<bool>> m_buttonStates;
	std::vector<bool> m_mouseButtonStates;

	InputHandler() {};
	~InputHandler() {}

	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	void onJoystickAxisMove(SDL_Event& event);
	void onJoystickButtonDown(SDL_Event& event);
	void onJoystickButtonUp(SDL_Event& event);

};
typedef InputHandler TheInputHandler;