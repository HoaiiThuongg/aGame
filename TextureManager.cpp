#include "TextureManager.h"
#include "MenuState.h"

TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* renderer)
{
	SDL_Surface* sur = IMG_Load(fileName.c_str());

	if (sur == 0) return false;

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, sur);

	SDL_FreeSurface(sur);

	if (texture != 0) {
		m_text[id] = texture;
		return true;
	}

	return false;

}

void TextureManager::draw(std::string id, int x, int y, int w, int h, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
	SDL_Rect srect, dest;

	srect.x = 0;
	srect.y = 0;
	srect.w = dest.w = w;
	srect.h = dest.h = h;

	dest.x = x;
	dest.y = y;

	SDL_RenderCopyEx(renderer, m_text[id], &srect, &dest, 0, 0, flip);
}

void TextureManager::drawBgr(std::string id, int x, int y, int w, int h, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
	SDL_Rect srect, dest;
	srect.x = x;
	srect.y = y;
	srect.w = w;
	srect.h = h;

	dest.x = 0;
	dest.y = 0;
	dest.w = w ;
	dest.h = h ;

	SDL_RenderCopyEx(renderer, m_text[id], &srect, &dest, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int w, int h, int scale, int currentFrame, int currentR, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
	SDL_Rect srect, dest;
	srect.x = w * currentFrame;
	srect.y = h * currentR;
	srect.w = w;
	srect.h = h;

	dest.x = x;
	dest.y = y;
	dest.w = w * scale;
	dest.h = h * scale;

	SDL_RenderCopyEx(renderer, m_text[id], &srect, &dest, 0, 0, flip);
}

void TextureManager::drawMau(std::string id, int xpos, int ypos, int xSrc, int ySrc, 
	int w, int h, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
	SDL_Rect srect, dest;
	srect.x = xSrc;
	srect.y = ySrc;
	srect.w = w;
	srect.h = h;

	dest.x = xpos;
	dest.y = ypos;
	dest.w = w ;
	dest.h = h ;

	SDL_RenderCopyEx(renderer, m_text[id], &srect, &dest, 0, 0, flip);
}

void TextureManager::drawXanh(std::string id, int x, int y, int w, int h, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
	SDL_Rect srect, dest;
	srect.x = x;
	srect.y = y;
	srect.w = w;
	srect.h = h;

	dest.x = 300;
	dest.y = 40;
	dest.w = w;
	dest.h = h;

	SDL_RenderCopyEx(renderer, m_text[id], &srect, &dest, 0, 0, flip);
}

void TextureManager::clearFromTextureMap(std::string id)
{
	m_text.erase(id);
}