#pragma once
#include "SDLGameObject.h"
#include "Vector2D.h"
#include "InputHandle.h"
#include"Sound.h"
#include <vector>
#include <iostream>

class Snake : public SDLGameObject
{
public:
    Snake(const LoaderParams* pParams, int scale, int frame, int speeds);

    void updateCon(Snake* player);
    void updateFood();
    void updateBomb(int x, int y);
    void updateExplode(int x,int y);
    void frame0()
    {
        currentFrame = 0;
    }
 
    bool isno() { return currentFrame == frame - 1; }

    virtual void update();

    void draw();
    virtual void clean();

    bool appear = true;
private:
    Sound SSound;
    int speed, frame;
    bool chuyenHuong = false;

    std::vector<std::string> buoc = { "none" };
    std::string jump = "none";
    void handleInput();

    void generateRandomPosition();
};