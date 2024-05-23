#include "DinoState.h"
#include <iostream>
#include "GameObject.h"
#include "TextureManager.h"
#include "Dino.h"
#include "InputHandle.h"
#include "GameOverState.h"
#include "Background.h"
#include "PhanDien.h"
#include "ChangeCharacterState.h"
#include "Button.h"
#include "TTF.h"
#include "MenuState.h"
#include "Octopus.h"
#include "DrawPic.h"
#include "BossState.h"

bool DinoState::choi = false;
const std::string DinoState::s_playID = "DinoPLAY";
void DinoState::update()
{
	if (chet == "lenThienDang")
	{
		lenThienDang();
		dino->dead();
		if (dino->getPosition().getY() < 0)
		{
			TheGame::Instance()->getStateMachine()->changeState(new GameOverState());
		}
	}
	else if (chet == "bye")
	{
		bye();
		dino->dead();
		if (dino->getPosition().getY() < 0)
		{
			TheGame::Instance()->getStateMachine()->changeState(new GameOverState());
		}
	}
	else
	{
		bgrDino.update();
		dino->update();
		catus->updateCatus();
		bay->bay();
		key->drawKey();

		if (catus->getPosition().getX() == 0)
		{
			//doKho++;
		}

		if (doKho == 4)
		{
			catus->updateSpeed = 2;
			bgrDino.speed = 2;
		}
		for (int i = 0; i < m_dan.size(); i++)
		{
			m_dan[i]->update();
		}

		for (int i = 0; i < m_doc.size(); i++)
		{
			m_doc[i]->danDoc();
		}

		for (int i = 0; i < place.size(); i++)
		{
			place[i]->update();
		}

		if ((oc->frame()) == 12)
		{
			if (m_dan.size() == 0)
			{
				Bullet* d = new Bullet(new LoaderParams(200, 445, 10, 8, "bullet"), 2, 7);
				m_dan.push_back(d);
			}
		}

		if ((bay->getPosition().getX() >= dino->getPosition().getX() - 5 &&
			bay->getPosition().getX() <= dino->getPosition().getX() + 5))
		{
			if (m_doc.size() == 0)
			{
				Bullet* d = new Bullet(new LoaderParams(dino->getPosition().getX(), 30, 10, 8, "bullet"), 2, 3);
				m_doc.push_back(d);
				DSSound.PlayKhoDo();
			}
		}

		if (m_dan.size() != 0 && m_dan[0]->getX() >= 800)
		{
			m_dan.clear();
		}

		if (m_doc.size() != 0 && m_doc[0]->getY() >= 450)
		{
			m_doc.clear();
		}
		dinoWrite.UpdateStatic();
		if (checkVa(dino->getPosition().getX(), dino->getPosition().getY(),
			dino->getWidth(), dino->getHeight(),
			catus->getPosition().getX(), catus->getPosition().getY(),
			catus->getWidth(), catus->getHeight()))
		{
			chet = "bye";
		}

		if (checkVa(dino->getPosition().getX(), dino->getPosition().getY(),
			dino->getWidth(), dino->getHeight(),
			oc->getPosition().getX(), oc->getPosition().getY(),
			oc->getWidth()-50, oc->getHeight()-50))
		{
			chet = "bye";
		}

		if (m_dan.size() != 0)
		{
			if (checkVa(dino->getPosition().getX(), dino->getPosition().getY(),
				dino->getWidth(), dino->getHeight(),
				m_dan[0]->getPosition().getX(), m_dan[0]->getPosition().getY(),
				m_dan[0]->getWidth(), m_dan[0]->getHeight()))
			{
				chet = "lenThienDang";
				DSSound.PlayExplode();
			}
		}

		if (m_doc.size() != 0)
		{
			if (checkVa(dino->getPosition().getX(), dino->getPosition().getY(),
				dino->getWidth(), dino->getHeight(),
				m_doc[0]->getPosition().getX(), m_doc[0]->getPosition().getY(),
				m_doc[0]->getWidth(), m_doc[0]->getHeight()))
			{
				chet = "lenThienDang";
				DSSound.PlayExplode();
			}
		}
		if (checkVa(dino->getPosition().getX(), dino->getPosition().getY(),
			dino->getWidth(), dino->getHeight(),
			key->getPosition().getX(), key->getPosition().getY(),
			key->getWidth(), key->getHeight()))
		{
			TTF::food++;
			key->isKey = false;
		}

	}
	for (int i = 0; i < m_dinoButton.size(); i++)
	{
		m_dinoButton[i]->update();
	}
}

void DinoState::render()
{
	bgrDino.draw();
	catus->draw();	
	dino->draw();
	oc->draw();
	bay->draw();
	key->draw();

	for (int i = 0; i < m_dan.size(); i++)
	{
		m_dan[i]->draw();
	}
	for (int i = 0; i < m_doc.size(); i++)
	{
		m_doc[i]->draw();
	}
	for (int i = 0; i < place.size(); i++)
	{
		place[i]->draw();
	}

	for (int i = 0; i < m_dinoButton.size(); i++)
	{
		m_dinoButton[i]->draw();
	}

	dinoWrite.WriteNumber(TTF::coin, 430, 53);
	dinoWrite.WriteNumber(TTF::food, 640, 53);

}

bool DinoState::onEnter()
{
	if(ChangeCharacterState::pathID == "")
	{
		ChangeCharacterState::pathID = "image/KhungLongFrames.png";
		ChangeCharacterState::width = 25;
		ChangeCharacterState::height = 25;
		ChangeCharacterState::frames = 9;
	}
	bgrDino.load(2462, 640, "image/backGround1.png", "bgrdino",5);
	if (!TheTextureManager::Instance()->load(ChangeCharacterState::pathID,
		"khungLong", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/catus.png",
		"catus1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Back.png",
		"Back", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/Octopus.png",
		"Octopus", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/Bullet.png",
		"bullet", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/AlienBay.png",
		"bay", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load bay";
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/CoinPlace.png",
		"cPlace", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/KeyPlace.png",
		"kPlace", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Key.png",
		"key", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* backButon = new Button(new LoaderParams(600, 500, 39, 33, "Back"), 2, Back);
	m_dinoButton.push_back(backButon);

	catus = new PhanDien(new LoaderParams(1200, 430, 25, 25, "catus1"), 2,1,5);
	dino = new Dino(new LoaderParams(400, 425 , 
		ChangeCharacterState::width, ChangeCharacterState::height, "khungLong"),2
		,ChangeCharacterState::frames);
	oc = new Octopus(new LoaderParams(0, 315, 72, 55, "Octopus"), 3,15);

	bay = new Octopus(new LoaderParams(2000, 30, 132, 162, "bay"), 1,1);

	GameObject* coinPlace = new DrawPic(new LoaderParams(400, 30, 64, 32, "cPlace"), 2, 1);
	GameObject* keyPlace = new DrawPic(new LoaderParams(600, 30, 64, 32, "kPlace"), 2, 1);
	key = new DrawPic(new LoaderParams(800, 400, 26, 24, "key"), 1, 1);

	place.push_back(coinPlace);
	place.push_back(keyPlace);

	std::cout << "entering PlayState\n";
	return true;
}

bool DinoState::onExit()
{
	DSSound.resume();
	DSSound.Clean();
	GameOverState::PathNguoiRaDi = ChangeCharacterState::pathID;
	GameOverState::width = ChangeCharacterState::width;
	GameOverState::height = ChangeCharacterState::height;
	GameOverState::frame = ChangeCharacterState::frames;
	dinoWrite.UpdateStatic();

	bgrDino.clean();
	dino->clean();
	catus->clean();
	oc->clean();
	bay->clean();
	key->clean();

	for (int i = 0; i < m_dinoButton.size(); i++)
	{
		m_dinoButton[i]->clean();
	}
	m_dinoButton.clear();

	for (int i = 0; i < m_dan.size(); i++)
	{
		m_dan[i]->clean();
	}
	m_dan.clear();

	for (int i = 0; i < m_doc.size(); i++)
	{
		m_doc[i]->clean();
	}
	m_doc.clear();

	for (int i = 0; i < place.size(); i++)
	{
		place[i]->clean();
	}
	place.clear();
	dinoWrite.Clean();
	std::cout << "exiting DinoState\n";
	return true;
}

bool DinoState::checkVa(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	if (x1 + w1 >= x2 &&
		x2 + w2 >= x1 &&
		y1 + h1 >= y2 &&
		y2 + h2 >= y1)
		return true;

	return false;
}

void DinoState::Back()
{
	choi = false;
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}