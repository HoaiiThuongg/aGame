#include "MenuState.h"
#include "DinoState.h"
#include <iostream>
#include "TextureManager.h"
#include "Button.h"
#include "GameObject.h"
#include "Sound.h"
#include "SpaceState.h"
#include "ChangeCharacterState.h"
#include "TTF.h"
#include "Dino.h"
#include "Spaceship.h"
#include "DrawPic.h"
#include "GameOverState.h"
#include "EnterName.h"
#include "HuongDan.h"
#include "DieuTraState.h"
#include "WinState.h"
#include "OnOffMusic.h"
#include "SnakeState.h"

int MenuState::trangThai = koThu;

const std::string MenuState::s_menuID = "MENU";
void MenuState::update()
{
	bgrMenu.update();
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	phiHanhGia->update();
	dino->updateChuot(phiHanhGia->getPosition().getX() - 60,
		phiHanhGia->getPosition().getY() + 30);

	if (trangThai == Thu)
	{
		xbutton->update();
	}
}
void MenuState::render()
{
	bgrMenu.draw();
	avatar->drawFlip();
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	menuWrite.WriteNumber(TTF::coin, 430, 53);
	menuWrite.WriteNumber(TTF::food, 640, 53);
	std::ifstream playerName("font/playerName.txt");

	getline(playerName, EnterName::name);
	playerName.close();

	if (EnterName::name == "") 
	{
		menuWrite.Write(160, 12, "Enter your name");
	}
	else if(EnterName::name == "HOAI THUONG")
	{
		menuWrite.Write(160, 42, EnterName::name);
		menuWrite.Write(150, 85, "Hello Sad Girl :<");
	}
	else
	{
		std::string loiMuonNoi = "Hello " + EnterName::name + " !";
		menuWrite.Write(160, 42, EnterName::name);
		menuWrite.Write(150, 85, loiMuonNoi);
	}
	phiHanhGia->draw();
	dino->drawFlip();

	if (trangThai == Thu)
	{
		thu->draw();
		xbutton->draw();
	}
}
bool MenuState::onEnter()
{
	if (ChangeCharacterState::pathPhgID == "")
	{
		ChangeCharacterState::pathPhgID = "image/PhiHanhGia1.png";
		ChangeCharacterState::pathAvaID = "image/avaPHG1.png";
		ChangeCharacterState::menuw = 22;
		ChangeCharacterState::menuh = 32;
		ChangeCharacterState::phgFrames = 4;
		ChangeCharacterState::pathGunID = "image/aka.png";
	}
	if (ChangeCharacterState::pathID == "")
	{
		ChangeCharacterState::pathID = "image/KhungLongFrames.png";
		ChangeCharacterState::width = 25;
		ChangeCharacterState::height = 25;
		ChangeCharacterState::frames = 9;
	}
	bgrMenu.load(2142,640,"image/bg.jpg", "bgr");
	if (!TheTextureManager::Instance()->load("image/MainPlay.png",
		"playSpace", TheGame::Instance()->getRenderer())) 
	{
		std::cout << "fail to load in MenuState" << std::endl;
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/DinoState.png",
		"playDino", TheGame::Instance()->getRenderer()))
	{
		return false;
		std::cout << "fail to load in MenuState" << std::endl;

	}
	if (!TheTextureManager::Instance()->load("image/Quit.png",
		"exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
		std::cout << "fail to load in MenuState" << std::endl;

	}
	if (!TheTextureManager::Instance()->load("image/Shop.png",
		"changeCharacter", TheGame::Instance()->getRenderer()))
	{
		return false;
		std::cout << "fail to load in MenuState" << std::endl;
	}

	if (!TheTextureManager::Instance()->load("image/DT.png",
		"DTButton", TheGame::Instance()->getRenderer()))
	{
		return false;
		std::cout << "fail to load in MenuState" << std::endl;
	}

	//phg
	if (!TheTextureManager::Instance()->load(ChangeCharacterState::pathPhgID,
		"phg", TheGame::Instance()->getRenderer()))
	{
		return false;
		std::cout << "fail to load in MenuState" << std::endl;

	}
	//kl
	if (!TheTextureManager::Instance()->load(ChangeCharacterState::pathID,
		"khungLong", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg3";
		return false;
		std::cout << "fail to load in MenuState" << std::endl;

	}
	//ava
	if (!TheTextureManager::Instance()->load(ChangeCharacterState::pathAvaID,
		"ava", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load in MenuState" << std::endl;
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/CoinPlace.png",
		"cPlace", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg3";
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/KeyPlace.png",
		"kPlace", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg3";
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/NamePlace.png",
		"nPlace", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg3";
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/HuongDanButton.png",
		"hdBtoon", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg3";
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/thu.png",
		"thu", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/music.png",
		"musicBtoon", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/thuNgo.png",
		"thuBgr", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Xbutton.png",
		"x", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* button1 = new Button(new LoaderParams(400, 200, 96,
		64, "playSpace"),2, s_menuToSpace);
	GameObject* button2 = new Button(new LoaderParams(600, 200, 53,
		32, "playDino"), 3, s_menuToDino);
	GameObject* button3 = new Button(new LoaderParams(400, 400, 96,
		49, "changeCharacter"), 2, s_menuToChangeCharacter);
	GameObject* button4 = new Button(new LoaderParams(600, 500, 64,
		32, "exitbutton"),2, s_exitFromMenu);
	GameObject* button5 = new Button(new LoaderParams(16, 300, 29,
		31, "hdBtoon"), 2, s_HuongDan);
	GameObject* button6 = new Button(new LoaderParams(16, 200, 33,
		29, "DTButton"), 2, s_DieuTra);
	GameObject* button7 = new Button(new LoaderParams(16, 400, 33,
		29, "musicBtoon"), 2, s_Music);
	GameObject* button8 = new Button(new LoaderParams(150, 125, 37,
		29, "thu"), 1, s_Thu);

	avatar = new DrawPic(new LoaderParams(10, 30, 64, 64, "ava"), 2,1);
	phiHanhGia = new Spaceship(new LoaderParams(200, 400,
		ChangeCharacterState::menuw, ChangeCharacterState::menuh, "phg"), 3,
		ChangeCharacterState::phgFrames, 4);
	dino = new DrawPic(new LoaderParams(phiHanhGia->getPosition().getX() - 60,
		phiHanhGia->getPosition().getY()+30, ChangeCharacterState::width, 
		ChangeCharacterState::height,
		"khungLong"),2, ChangeCharacterState::frames);

	GameObject* coinPlace = new DrawPic(new LoaderParams(400, 30, 64, 32, "cPlace"), 2, 1);
	GameObject* keyPlace = new DrawPic(new LoaderParams(600, 30, 64, 32, "kPlace"), 2, 1);

	GameObject* namePlace = new Button(new LoaderParams(150, 40, 220,
		40, "nPlace"), 1, s_menuToEnterName);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	m_gameObjects.push_back(button3);
	m_gameObjects.push_back(button4);
	m_gameObjects.push_back(button5);
	m_gameObjects.push_back(button6);
	m_gameObjects.push_back(button7);
	m_gameObjects.push_back(button8);
	m_gameObjects.push_back(namePlace);
	m_gameObjects.push_back(coinPlace);
	m_gameObjects.push_back(keyPlace);
	menuWrite.readFile();

	thu = new DrawPic(new LoaderParams(150, 50,493,521,"thuBgr"),1,1);
	xbutton = new Button(new LoaderParams(250, 150, 26, 26, "x"), 1, returnn);

	Spaceship::i = 0;
	std::cout << "entering MenuState\n";
	return true;
}
bool MenuState::onExit()
{
	avatar->clean();
	dino->clean();
	phiHanhGia->clean();
	thu->clean();
	xbutton->clean();
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	menuWrite.Clean();

	TheTextureManager::Instance()->clearFromTextureMap("playSpace");

	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_menuToSpace()
{
	TheGame::Instance()->getStateMachine()->changeState(new SpaceState());
}

void MenuState::s_menuToDino()
{
	TheGame::Instance()->getStateMachine()->changeState(new DinoState());
}

void MenuState::s_menuToChangeCharacter()
{
	TheGame::Instance()->getStateMachine()->changeState(new ChangeCharacterState());
}

void MenuState::s_menuToEnterName()
{
	TheGame::Instance()->getStateMachine()->pushState(new EnterName());
}

void MenuState::s_HuongDan()
{
	TheGame::Instance()->getStateMachine()->pushState(new HuongDan());
}

void MenuState::s_DieuTra()
{
	TheGame::Instance()->getStateMachine()->changeState(new DieuTraState());
}

void MenuState::s_Music()
{
	TheGame::Instance()->getStateMachine()->pushState(new OnOffMusic());
}

void MenuState::s_Thu()
{
	trangThai = Thu;
}

void MenuState::returnn()
{
	trangThai = koThu;
}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->clean();
}