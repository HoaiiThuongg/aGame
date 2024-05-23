#pragma once

#include "Game.h"
#include <map>
class TextureManager
{
public:
	bool load(std::string fileName, std::string id, SDL_Renderer* renderer);
	//draw
	void draw(std::string id, int x, int y, int w, int h, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	//draw frame
	void drawFrame(std::string id, int x, int y, int w, int h,int scale, int currentR, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawBgr(std::string id, int x, int y, int w, int h, SDL_Renderer* renderer, SDL_RendererFlip flip);
	void drawXanh(std::string id, int x, int y, int w, int h, SDL_Renderer* renderer, SDL_RendererFlip flip);
	void drawMau(std::string id,int xpos,int ypos, int xSrc, int ySrc, int w, int h, SDL_Renderer* renderer, SDL_RendererFlip flip);
	std::map<std::string, SDL_Texture*> m_text;

	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}

		return s_pInstance;
	}
	TextureManager() {}

	static TextureManager* s_pInstance;
	void clearFromTextureMap(std::string id);
};

typedef TextureManager TheTextureManager;