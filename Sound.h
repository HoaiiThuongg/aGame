#pragma once
#include "SDL_mixer.h"
#include "SDL.h"
#include <map>
#include <string>
#include <iostream>

class Sound
{
public:
	static std::string pathMusic ;
	static bool onMusic;
	static bool onChunk;

	void PlayJumpSound()
	{
		if(onChunk)
		{
			chunk = Mix_LoadWAV("sound/JumpVideoGame.wav");
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayMenuSound()
	{
		if(onMusic)
		{
			music = Mix_LoadMUS(pathMusic.c_str());
			Mix_PlayMusic(music, -1);
		}
	}

	void PlayCCSound()
	{
		if(onChunk)
		{
			chunk = Mix_LoadWAV("sound/adventure.mp3");
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayWSound()
	{
		if (onChunk)
		{
			chunk = Mix_LoadWAV("sound/win.mp3");
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayGunSound()
	{
		if(onChunk)
		{
			chunk = Mix_LoadWAV("sound/gun.mp3");
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayCoinSound()
	{
		if(onChunk)
		{
			chunk = Mix_LoadWAV("sound/coin.wav");
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayOcSound()
	{
		if(onChunk)
		{
			chunk = Mix_LoadWAV("sound/oc.mp3");
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayDieSound()
	{
		if (onChunk)
		{
			chunk = Mix_LoadWAV("sound/die.mp3");
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayLenThienDangSound()
	{
		if(onMusic)
		{
			chunk = Mix_LoadWAV("sound/lenThienDang.mp3");
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayExplode()
	{
		if (onChunk)
		{
			chunk = Mix_LoadWAV("sound/explode.mp3");
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayTruotFive()
	{
		if (onChunk)
		{
			if(rand == 0)
			{
				chunk = Mix_LoadWAV("sound/banTruotFive.mp3");
			}
			else if (rand == 1)
			{
				chunk = Mix_LoadWAV("sound/vdkinang.mp3");
			}
			else if (rand == 2)
			{
				chunk = Mix_LoadWAV("sound/cau.mp3");
			}
			Mix_PlayChannel(-1, chunk, 0);
			rand++;
			if (rand == 4) rand = 0;
		}
	}

	void PlayKhoDo()
	{
		if (onChunk)
		{
			chunk = Mix_LoadWAV("sound/khoDo.mp3");
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayBye()
	{
		if (onChunk)
		{
			chunk = Mix_LoadWAV("sound/bye.mp3");
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayYourName()
	{
		if (onChunk)
		{
			chunk = Mix_LoadWAV("sound/yourName.mp3");
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayKhec()
	{
		if (onChunk)
		{
			chunk = Mix_LoadWAV("sound/khec.mp3");
			Mix_PlayChannel(-1, chunk, 0);
		}
	}


	void PlayoiDoiOi()
	{
		if (onChunk)
		{
			chunk = Mix_LoadWAV("sound/oiDoiOi.mp3");
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void PlayChonDie()
	{
		if (onChunk)
		{
			chunk = Mix_LoadWAV("sound/chonDie.mp3");
			Mix_PlayChannel(-1, chunk, 0);
		}
	}

	void Clean()
	{
		Mix_FreeChunk(chunk);
	}

	void Clear()
	{
		Mix_FreeMusic(music);
		Mix_CloseAudio();
	}

	void resume()
	{
		if(onMusic)
		Mix_ResumeMusic();
	}

	void pause()
	{
		Mix_PauseMusic();
	}
	void changeMusic(std::string path)
	{
		pathMusic = path;
	}
private:
	int rand = 0;
	Mix_Music* music;
	Mix_Chunk* chunk;
};