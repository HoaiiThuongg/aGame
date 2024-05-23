#include "SnakeState.h"
#include "InputHandle.h"
#include "Snake.h"
#include "TextureManager.h".
#include "DieuTraState.h"
#include "GameOverState.h"


const std::string SnakeState::s_SnakeStateID = "SnakeState";
void SnakeState::update()
{
	if(! no->appear)
	{
		head->update();
		food->updateFood();
		for (int i = 0; i < bom.size(); i++)
		{
			bom[i]->updateBomb(head->getPosition().getX(), head->getPosition().getY());
		}
		back->update();
		for (int i = 0; i < tail.size(); i++)
		{
			if (i == 0)
			{
				tail[i]->updateCon(head);
			}
			else
			{
				tail[i]->updateCon(tail[i - 1]);
			}
		}

		if (checkVa(head->getPosition().getX(), head->getPosition().getY(), head->getWidth(), head->getHeight(),
			food->getPosition().getX(), food->getPosition().getY(), food->getWidth(), food->getHeight()))
		{
			food->appear = false;
			if (tail.size() == 0)
			{
				Snake* con = new Snake(new LoaderParams(head->getPosition().getX(), head->getPosition().getY(),
					20, 62, "tail"), 1, 4, speed);
				tail.push_back(con);
			}
			else
			{
				Snake* con = new Snake(new LoaderParams(tail[tail.size() - 1]->getPosition().getX(), tail[tail.size() - 1]->getPosition().getY(),
					20, 62, "tail"), 1, 4, speed);
				tail.push_back(con);
			}
			eat++;
			people++;
		}

		if (eat != 0 && eat % 4 == 0)
		{
			bom[0]->appear = false;
			eat++;
		}

		for (int i = 0; i < bom.size(); i++)
		{
			if (checkVa(head->getPosition().getX(), head->getPosition().getY(), head->getWidth(), head->getHeight(),
				bom[i]->getPosition().getX(), bom[i]->getPosition().getY(), bom[i]->getWidth(), bom[i]->getHeight()))
			{
				no->appear = true;
				no->frame0();
				SnakeSound.PlayExplode();
				x = bom[i]->getPosition().getX();
				y = bom[i]->getPosition().getY();
				break;
			}
			if (checkVa(food->getPosition().getX(), food->getPosition().getY(), food->getWidth(), food->getHeight(),
				bom[i]->getPosition().getX(), bom[i]->getPosition().getY(), bom[i]->getWidth(), bom[i]->getHeight()))
			{
				food->appear = false;
			}
		}

		if (eat == 10)
		{
			if (!checkVa(food->getPosition().getX(), food->getPosition().getY(), food->getWidth(), food->getHeight(),
				600,500,16,24))
			{
				Snake* bomb = new Snake(new LoaderParams(600, 500,
					16, 24, "bomb"), 2, 2, 5);
				bom.push_back(bomb);
			}
			else
			{
				Snake* bomb = new Snake(new LoaderParams(300, 500,
					16, 24, "bomb"), 2, 2, 5);
				bom.push_back(bomb);
			}
			eat++;
		}
		if (eat == 15)
		{
			if (!checkVa(food->getPosition().getX(), food->getPosition().getY(), food->getWidth(), food->getHeight(),
				600, 500, 16, 24))
			{
				Snake* bomb = new Snake(new LoaderParams(300, 100,
					16, 24, "bomb"), 2, 2, 5);
				bom.push_back(bomb);
			}
			else
			{
				Snake* bomb = new Snake(new LoaderParams(200, 600,
					16, 24, "bomb"), 2, 2, 5);
				bom.push_back(bomb);
			}
			eat++;
		}
	}
	else if (no->appear)
	{
		no->updateExplode(x - 70, y - 75);
		if (no->isno())
		{
			TheGame::Instance()->getStateMachine()->changeState(new GameOverState);
		}
	}
}
void SnakeState::render()
{
	for (int i = 0; i < anh.size(); i++)
	{
		anh[i]->draw();
	}
	for (int i = tail.size() - 1; i >=0; i--)
	{
		tail[i]->draw();
	}
	head->draw();
	food->draw();
	back->draw();
	for (int i = 0; i < bom.size(); i++)
	{
		bom[i]->draw();
	}
	no->draw();
	SnakeWrite.WriteNumber(people, 680,70);
	SnakeWrite.WriteNumber(TTF::coin, 680, 170);
	SnakeWrite.WriteNumber(TTF::food,680, 270); 
}

bool SnakeState::onEnter()
{
	if (!TheTextureManager::Instance()->load("image/walking.png",
		"head", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/walking2.png",
		"tail", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/run.png",
		"Run", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/Back.png",
		"Back", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/bomb.png",
		"bomb", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/explode.png",
		"no", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/SnakePlace.png",
		"rPlace", TheGame::Instance()->getRenderer()))
	{
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

	if (!TheTextureManager::Instance()->load("image/bgrSnake.png",
		"bgr", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	back = new Button(new LoaderParams(680, 550, 39,
		33, "Back"), 2, Back);
	head = new Snake(new LoaderParams(200, 300,
		20,62, "head"),1,4,speed);
	Snake* bomb = new Snake(new LoaderParams(500, 500,
		16, 24, "bomb"), 2, 2, 5);

	bom.push_back(bomb);

	food = new Snake(new LoaderParams(400, 400,
		20, 62, "tail"), 1, 4, speed);
	no = new Snake(new LoaderParams(900, 400,
		134, 144, "no"),1, 5, 0);
	no->appear = false;

	DrawPic* bgr = new DrawPic(new LoaderParams(0, 0, 640, 640, "bgr"),1, 1);
	DrawPic* khungRan = new DrawPic(new LoaderParams(650, 50, 64, 32, "rPlace"), 2, 1);
	DrawPic* khungTien = new DrawPic(new LoaderParams(650, 150, 64, 32, "cPlace"), 2, 1);  
	DrawPic* khungKey = new DrawPic(new LoaderParams(650,250, 64, 32, "kPlace"), 2, 1);

	anh.push_back(bgr);
	anh.push_back(khungRan);
	anh.push_back(khungTien);
	anh.push_back(khungKey);

	std::cout << "entering SnakeState\n";
	return true;
}

bool SnakeState::onExit()
{
	SnakeSound.PlayBye();
	GameOverState::PathNguoiRaDi = "image/walking.png";
	GameOverState::width = 20;
	GameOverState::height = 62;
	GameOverState::frame = 4;

	for (int i = 0; i < tail.size(); i++)
	{
		tail[i]->clean();
	}
	tail.clear();

	head->clean();
	food->clean();
	back->clean();
	no->clean();
	
	for (int i = 0; i < anh.size(); i++)
	{
		anh[i]->clean();
	}
	anh.clear();
	for (int i = 0; i < bom.size(); i++)
	{
		bom[i]->clean();
	}
	bom.clear();
	no->clean();
	std::cout << "exiting SnakeState\n";
	SnakeWrite.Clean();
	return true;
}

bool SnakeState::checkVa(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	if (x1 + w1 > x2 &&
		x2 + w2 > x1 &&
		y1 + h1 > y2 &&
		y2 + h2 > y1)
		return true;
	return false;
}

void SnakeState::Back()
{
	TheGame::Instance()->getStateMachine()->changeState( new DieuTraState);
}