#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "SDL_ttf.h"
#include "Game.h"

class TTF
{
public:
	void Init()
	{
		if (TTF_Init() == -1)
		{
			std::cout << "SDL_ttf could not initialize! " << std::endl;
			return;
		}

		font = TTF_OpenFont("Font/arial.ttf", 24);
		if (font == nullptr)
		{
			printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
			return;
		}

		textColor = { 255, 255, 255 };
	}

	void readFile();

	void Update(int score)
	{
		std::string diem = std::to_string(score);
		const char* soDiem = diem.c_str();

		textSurface = TTF_RenderText_Solid(font, soDiem, textColor);

		if (textSurface == nullptr)
		{
			std::cout << "fail to load text Surface!" << std::endl;
			return;
		}
	}

	void Update(std::string what)
	{
		const char* whut = what.c_str();

		textSurface = TTF_RenderText_Solid(font, whut, textColor);

		if (textSurface == nullptr)
		{
			std::cout << "fail to load text Surface!" << std::endl;
			return;
		}
	}

	void UpdateStatic()
	{
		if (coin > 9999) coin = 9999;
		if (food > 9999) food = 9999;

		std::ofstream coinFile("font/coin.txt");

		if (!coinFile.is_open()) {
			std::cerr << "Fail to open coinFile" << std::endl;
			return;
		}
		coinFile << coin;
		coinFile.close();

		std::ofstream foodFile("font/food.txt");

		if (!foodFile.is_open()) {
			std::cerr << "Fail to open foodFile" << std::endl;
			return;
		}
		foodFile << food;
		foodFile.close();
	}

	void WriteNumber(int number, int x, int y)
	{
		Init();
		Update(number);
		SDL_Rect dtRect = { x,y,textSurface->w,textSurface->h };
		texture = SDL_CreateTextureFromSurface(Game::Instance()->getRenderer(), textSurface);
		SDL_RenderCopy(Game::Instance()->getRenderer(), texture, NULL, &dtRect);
	}

	void Write(int x, int y,std::string what)
	{
		Init();
		Update(what);
		SDL_Rect dtRect = { x,y,textSurface->w,textSurface->h };
		texture = SDL_CreateTextureFromSurface(Game::Instance()->getRenderer(), textSurface);
		SDL_RenderCopy(Game::Instance()->getRenderer(), texture, NULL, &dtRect);
	}

	void Clean()
	{
		SDL_FreeSurface(textSurface);
		SDL_DestroyTexture(texture);
		TTF_CloseFont(font);
		TTF_Quit();
	}

	static TTF* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TTF();
			return s_pInstance;
		}

		return s_pInstance;
	}
	static TTF* s_pInstance;

	static int food, coin;
private:
	
	TTF_Font* font;
	SDL_Color textColor;
	SDL_Surface* textSurface;
	SDL_Texture* texture;

};