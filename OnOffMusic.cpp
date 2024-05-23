#include "OnOffMusic.h"
#include "DrawPic.h"
#include "Button.h"
#include "TextureManager.h"
#include "Sound.h"

const std::string OnOffMusic::s_OOMID = "onOffMusic";
Sound OnOffMusic::OOS;
Button* OnOffMusic::off;
Button* OnOffMusic::offNote;

void OnOffMusic::update()
{
	monkey->update();
	for (int i = 0; i < button.size(); i++)
	{
		button[i]->update();
	}
}

void OnOffMusic::render()
{
	bgr->draw();
	monkey->draw();
	for (int i = 0; i < button.size(); i++)
	{
		button[i]->draw();
	}
}
bool OnOffMusic::onEnter()
{
	if (!TheTextureManager::Instance()->load("image/MusicBgr.png",
		"OOSBgr", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Back.png",
		"Back", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/off.png",
		"off", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/offNote.png",
		"offNote", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/metMoiSound.png",
		"met", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/truMua.png",
		"mua", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/bumChac.png",
		"bolero", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/que.png",
		"que", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/mo.png",
		"mo", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/dance.png",
		"dance", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	bgr = new DrawPic(new LoaderParams(0, 0, 800, 640, "OOSBgr"), 1, 1);
	monkey = new DrawPic(new LoaderParams(200, 200, 44, 44, "dance"), 1,6);

	off = new Button(new LoaderParams(100, 100, 26, 15, "off"), 2, Off);
	offNote = new Button(new LoaderParams(100, 150, 10, 13, "offNote"), 3, OffNote);

	Button* truMua = new Button(new LoaderParams(350, 150, 74, 31, "mua"), 2, toTruMua);
	Button* metMoi = new Button(new LoaderParams(350, 250, 74, 31, "met"), 2, toMetMoi);
	Button* queToi = new Button(new LoaderParams(550, 150, 74, 31, "que"), 2, toQueToi);
	Button* bumChac = new Button(new LoaderParams(550, 250, 74, 31, "bolero"), 2, toBumChac);
	Button* mo = new Button(new LoaderParams(450, 350, 74, 31, "mo"), 2, toMo);

	Button* back = new Button(new LoaderParams(500, 500, 39, 33, "Back"), 2, Back);

	button.push_back(off);
	button.push_back(offNote);
	button.push_back(truMua);
	button.push_back(metMoi);
	button.push_back(queToi);
	button.push_back(bumChac);
	button.push_back(mo);
	button.push_back(back);

	if (!Sound::onMusic)
	{
		off->changeRow1();
	}

	if (!Sound::onChunk)
	{
		offNote->changeRow1();
	}

	return true;
}

bool OnOffMusic::onExit()
{
	bgr->clean();
	monkey->clean();
	off->clean();
	offNote->clean();

	for (int i = 0; i < button.size(); i++)
	{
		button[i]->clean();
	}
	button.clear();
	return true;
}

void OnOffMusic::Off()
{
	if(off->returnRow() == 0)
	{
		Sound::onMusic = false;
		OOS.pause();
		off->changeRow1();
	}
	else if (off->returnRow() == 1)
	{
		Sound::onMusic = true;
		OOS.resume();
		off->changeRow0();
	}
}

void OnOffMusic::OffNote()
{
	if (offNote->returnRow() == 0)
	{
		Sound::onChunk = false;
		offNote->changeRow1();
	}
	else if (offNote->returnRow() == 1)
	{
		Sound::onChunk = true;
		offNote->changeRow0();
	}
}

void OnOffMusic::toTruMua()
{
	Sound::pathMusic = "sound/truMua.mp3";
	OOS.PlayMenuSound();
}

void OnOffMusic::toMetMoi()
{
	Sound::pathMusic = "sound/metMoi.mp3";
	OOS.PlayMenuSound();
}

void OnOffMusic::toQueToi()
{
	Sound::pathMusic = "sound/queToiRemix.mp3";
	OOS.PlayMenuSound();
}

void OnOffMusic::toBumChac()
{
	Sound::pathMusic = "sound/boleroBungChac.mp3";
	OOS.PlayMenuSound();
}

void OnOffMusic::toMo()
{
	Sound::pathMusic = "sound/giacMoTrua.mp3";
	OOS.PlayMenuSound();
}

void OnOffMusic::Back()
{
	TheGame::Instance()->getStateMachine()->popState();
}