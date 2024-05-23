#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include<iostream>
#include <vector>
#include "GameObject.h"
#include "GameStateMachine.h"
#include "Sound.h"

class Game
{
public:
    Game();
    ~Game();

    bool init(const char* title, int xpos, int ypos, int width,
        int height, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();

    bool running() { return isRunning; }

    static SDL_Event event;

    static Game* Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }

    SDL_Renderer* getRenderer() const { return renderer; }

    static Game* s_pInstance;
    GameStateMachine* getStateMachine() { return m_pGameStateMachine; }
private:
    GameStateMachine* m_pGameStateMachine;
    SDL_Window* win;
    SDL_Renderer* renderer;
    Sound gameSound;

    bool isRunning;
};
typedef Game TheGame;