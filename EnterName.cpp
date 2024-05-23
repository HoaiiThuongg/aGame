#include "EnterName.h"
#include "TTF.h"
#include "Game.h"
#include "InputHandle.h"
#include "DrawPic.h"
#include "TextureManager.h"

const std::string EnterName::s_enterNameID = "EnterName";

const int FPS = 60;
const int DELAY_TIME = 9000.0f / FPS;
std::string EnterName::name = "";

void EnterName::update()
{
    bgr->update();
    if (name.length() <= 10)
    {
        std::string abc = "";
        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {
            abc = "A";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_B)) {
            abc = "B";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_C)) {
            abc = "C";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D)) {
            abc = "D";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_E)) {
            abc = "E";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_F)) {
            abc = "F";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_G)) {
            abc = "G";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_H)) {
            abc = "H";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_I)) {
            abc = "I";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_J)) {
            abc = "J";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_K)) {
            abc = "K";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_L)) {
            abc = "L";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_M)) {
            abc = "M";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_N)) {
            abc = "N";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_O)) {
            abc = "O";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_P)) {
            abc = "P";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Q)) {
            abc = "Q";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_R)) {
            abc = "R";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)) {
            abc = "S";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_T)) {
            abc = "T";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_U)) {
            abc = "U";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_V)) {
            abc = "V";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W)) {
            abc = "W";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_X)) {
            abc = "X";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Y)) {
            abc = "Y";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z)) {
            abc = "Z";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_1)) {
            abc = "1";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_0)) {
            abc = "0";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_0)) {
            abc = "0";
        }

        if (abc != "")
        {
            frameTime = SDL_GetTicks() - frameStart;
            if (frameTime < DELAY_TIME)
            {
                return;
            }
            frameStart = SDL_GetTicks();
            name += abc;
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
        {
            frameTime = SDL_GetTicks() - frameStart;
            if (frameTime < DELAY_TIME)
            {
                return;
            }
            frameStart = SDL_GetTicks();
            name += ' ';
        }
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_BACKSPACE) && name.length() > 0)
    {
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < DELAY_TIME)
        {
            return;
        }
        frameStart = SDL_GetTicks();
        name.pop_back();
    }

    back->update();
}
void EnterName::render()
{
    SDL_Color textColor = { 0, 0, 0 };
    SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(TheGame::Instance()->getRenderer());
    bgr->draw();
    back->draw();
    SDL_Surface* surface = TTF_RenderText_Solid(font, name.c_str(), textColor);

    if (surface == nullptr)
    {
        return ;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(TheGame::Instance()->getRenderer(), surface);
    SDL_Rect dstRect = { 250, 300, surface->w, surface->h };
    SDL_RenderCopy(TheGame::Instance()->getRenderer(), texture, NULL, &dstRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);

    SDL_RenderPresent(TheGame::Instance()->getRenderer());
}

bool EnterName::onEnter()
{
    ENSound.PlayYourName();
    if (!TheTextureManager::Instance()->load("image/yourName1.png",
        "bgrEnter", TheGame::Instance()->getRenderer()))
    {
        std::cout << "fail to load phg3";
        return false;
    }
    if (!TheTextureManager::Instance()->load("image/Back.png",
        "Back", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    bgr = new DrawPic(new LoaderParams(0, 0, 800, 640, "bgrEnter"), 1, 1);

    frameStart = 0.0f;
    font = TTF_OpenFont("Font/poxel.ttf", 24);
    if (font == nullptr)
    {
        return false;
    }

    back = new Button(new LoaderParams(400, 500, 39,
        33, "Back"), 2, Back);

    std::cout << "enter enter name\n";
	return true;
}

bool EnterName::onExit()
{
    if (name == "") name = "";
    std::ofstream playerName("font/playerName.txt");
    playerName << name;
    playerName.close();
    bgr->clean();
    back->clean();
    TTF_CloseFont(font);
    TTF_Quit();
    if (name == "HOAI THUONG")
    {
        TTF::coin += 100;
        TTF::food += 50;
        ENSound.PlayCoinSound();
    }
    code.UpdateStatic();

    std::cout << "exit enter name\n";
	return true;
}

void EnterName::Back()
{
    TheGame::Instance()->getStateMachine()->popState();
}