#include "BossState.h"
#include "TextureManager.h"
#include "ChangeCharacterState.h"
#include "Boss.h"
#include "PhanDien.h"
#include "InputHandle.h"
#include "GameOverState.h"
#include "WinState.h"
#include "Spaceship.h"

const std::string BossState::s_bossID = "BOSSSTATE";

bool BossState::checkVa(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	if (x1 + w1 > x2 &&
		x2 + w2 > x1 &&
		y1 + h1 > y2 &&
		y2 + h2 > y1)
		return true;

	return false;
}

void BossState::update()
{
	bgr.update();

	for (int i = 0; i < ChucNang.size(); i++)
	{
		if (ChucNang[i]->isFrame0())
		{
			if (ChucNang[i] ->ID() =="khung1" && TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_1) && CamChuong->isKey == false)
			{
				chuong.push_back("chuong1");
				ChucNang[i]->changeFrame();
			}
			if (ChucNang[i]->ID() == "khung2" && TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_2) && XanhPiuPiu.size() == 0)
			{
				chuong.push_back("chuong2");
				ChucNang[i]->changeFrame();
				DrawPic* d1 = new DrawPic(new LoaderParams(160, 100, 14, 13, "CamChuongPiuPiu"), 2, 4);
				DrawPic* d2 = new DrawPic(new LoaderParams(200, 130, 14, 13, "CamChuongPiuPiu"), 2, 4);
				DrawPic* d3 = new DrawPic(new LoaderParams(170, 150, 14, 13, "CamChuongPiuPiu"), 2, 4);
				DrawPic* d4 = new DrawPic(new LoaderParams(250, 170, 14, 13, "CamChuongPiuPiu"), 2, 4);
				XanhPiuPiu.push_back(d1);
				XanhPiuPiu.push_back(d2);
				XanhPiuPiu.push_back(d3);
				XanhPiuPiu.push_back(d4);
			}
		}
		else
		{
			ChucNang[i]->updateBossState();
		}
	}

	for (int i = 0; i < XanhPiuPiu.size(); i++)
	{
		XanhPiuPiu[i]->XanhChuong();
	}

	int iq = SDL_GetTicks() % 5000;

	if (iq >= 100 && iq <= 1000)
	{
		trthaiboss = "de";
	}
	else
	{
		trthaiboss = "binhThuong";
	}

	for (auto it = Chuong.begin(); it != Chuong.end(); it++)
	{
		auto chucnang1 = std::find(chuong.begin(), chuong.end(), "chuong1");
		if (it->first->ID()=="chuong1"&&chucnang1 != chuong.end())
		{
			it->first->Cam();
			if (it->first->raChuong)
				CamChuong->CamChuong();
			it->second = true;

			if (CamChuong->getPosition().getX() >= 650)
			{
				CamChuong->isKey = false;
				it->first->isKey = false;
				it->first->Cam();
				CamChuong->CamChuong();
				mauChua.updateMau(20);
				trthaiboss = "trungDan";
				it->second = false;
				chuong.erase(chucnang1);
			}
		}
		auto chucnang2 = std::find(chuong.begin(), chuong.end(), "chuong2");
		if (it->first->ID() == "chuong2" && chucnang2 != chuong.end())
		{
			it->first->Xanh();
			it->second = true;
			if (XanhPiuPiu.size() != 0)
			{
				if (XanhPiuPiu[XanhPiuPiu.size() - 1]->getPosition().getY() >= 400)
				{
					XanhPiuPiu[XanhPiuPiu.size() - 1]->XanhChuong();
					XanhPiuPiu.pop_back();
					mauChua.updateMau(10);
					trthaiboss = "trungDan";
				}
				if (XanhPiuPiu.size() == 0)
				{
					it->first->isKey = false;
					it->first->Xanh();
					it->second = false;
					chuong.erase(chucnang2);
				}
			}
		}
	}

	me->update();
	boss->update(trthaiboss);
	if (m_con.size() == 0 && trthaiboss == "de")
	{
		PhanDien* con = new PhanDien(new LoaderParams(580, conYpos, 54, 61, "con"),conScale, 6,5);
		m_con.push_back(con);
	}
	for (int i = 0; i < m_con.size(); i++)
	{
		m_con[i]->update();
		if (checkVa(m_con[i]->getPosition().getX(), m_con[i]->getPosition().getY(), m_con[i]->getWidth(), m_con[i]->getHeight()
			, me->getPosition().getX(), me->getPosition().getY(), me->getWidth(), me->getHeight()))
		{
			mauMe.updateMau(2);
			m_con[i]->changeRow1();
			me->changeRow2();
			if (la)
			{
				BSSpound.PlayoiDoiOi();
				la = false;
			}
		}
		else
		{
			la = true;
			m_con[i]->changeRow0();
			me->changeRow0();
		}
		if (m_con[i]->appear == false)
		{
			m_con.erase(m_con.begin() + i);
		}
	}

	if (checkVa(boss->getPosition().getX(), boss->getPosition().getY(), boss->getWidth(), boss->getHeight()
		, me->getPosition().getX(), me->getPosition().getY(), me->getWidth(), me->getHeight()))
	{
		mauMe.updateMau(2);
		me->changeRow2();
		BSSpound.PlayKhec();
	}

	an->updateCatus();

	if (mauMe.isDie())
	{
		TheGame::Instance()->getStateMachine()->changeState(new GameOverState());
	}

	if (mauChua.isDie())
	{
		TheGame::Instance()->getStateMachine()->changeState(new WinState());
	}

	if (checkVa(me->getPosition().getX(), me->getPosition().getY(), me->getWidth(), me->getHeight(),
		an->getPosition().getX(), an->getPosition().getY(), an->getWidth(), an->getHeight()) && an->appear)
	{
		an->appear = false;
		mauMe.updateMau(-20);
		BSSpound.PlayKhec();
	}

	if (mauChua.returnMau() == 200)
	{
		conScale = 3;
		conYpos -= 61;
		mauChua.updateMau(1);
		BSSpound.PlayoiDoiOi();
	}
}

void BossState::render()
{
	bgr.draw();
	boss->draw();
	mauChua.drawMau(boss->getPosition().getX()-10,boss->getPosition().getY()-30);

	me->draw();
	mauMe.drawMau(me->getPosition().getX() - 5, me->getPosition().getY() - 20);

	for (int i = 0; i< ChucNang.size(); i++)
	{
		ChucNang[i]->draw();
	}
	int j = 0;

	auto chucnang1 = std::find(chuong.begin(), chuong.end(), "chuong1");
	for (auto it = Chuong.begin(); it != Chuong.end(); it++)
	{
		if(it->second==true)
		{
			it->first->draw();
		}
		if (chucnang1 != chuong.end()&&it->first->raChuong)
			CamChuong->draw();
	}
	for (int i = 0; i < XanhPiuPiu.size(); i++)
	{
		XanhPiuPiu[i]->draw();
	}
	for (int i = 0; i < m_con.size(); i++)
	{
		m_con[i]->draw();
	}
	an->draw();
}

bool BossState::onEnter()
{
	if (!TheTextureManager::Instance()->load("image/Con.png",
		"con", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/fullFrames.png",
		"boss", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load(ChangeCharacterState::pathPhgID,
		"me", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/CamKhung.png",
		"kl1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/XanhKhung.png",
		"kl2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/CamChuong.png",
		"klChuong1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/XanhChuong.png",
		"klChuong2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/CamChuongPiuPiu.png",
		"CamChuongPiuPiu", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/XanhChuongPiuPiu.png",
		"XanhChuongPiuPiu", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/apple.png",
		"tao", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	bgr.load(3446, 640, "image/backgroundBS.png", "bossBgr");

	me = new Dino(new LoaderParams(10, ChangeCharacterState::menuh,
		ChangeCharacterState::menuw, ChangeCharacterState::menuh, "me"), 3,
		ChangeCharacterState::phgFrames,510);

	mauMe.load(200, 5, "image/mauMe.png", "mauMe");

	boss = new Boss(new LoaderParams(500, 370, 302, 213, "boss"), 1, 6);
	mauChua.load(600, 10, "image/mauChua.png", "mauChua");

	DrawPic * kl1 = new DrawPic(new LoaderParams(50, 10, 27, 27, "kl1"), 3, 6,"khung1");
	ChucNang.push_back(kl1);
	DrawPic* kl2 = new DrawPic(new LoaderParams(150, 15, 33, 24, "kl2"), 3, 9,"khung2");
	ChucNang.push_back(kl2);

	DrawPic* kl1C = new DrawPic(new LoaderParams(50, 10, 25, 25, "klChuong1"), 3,3,"chuong1");
	Chuong[kl1C] = false;
	DrawPic* kl2C = new DrawPic(new LoaderParams(150, 15, 31, 22, "klChuong2"), 3, 3,"chuong2");
	Chuong[kl2C] = false;

	an = new PhanDien(new LoaderParams(800, 380, 15, 18, "tao"),2,2,3);

	CamChuong = new DrawPic(new LoaderParams(120, 450, 14, 13, "CamChuongPiuPiu"), 2, 4);
	CamChuong->isKey = false;

	return true;
}

bool BossState::onExit()
{
	bgr.clean();
	mauMe.clean();
	mauChua.clean();
	me->clean();
	boss->clean();
	an->clean();
	CamChuong->clean();

	for (int i = 0; i < m_con.size(); i++)
	{
		m_con[i]->clean();
	}
	m_con.clear();

	for (int i = 0; i < XanhPiuPiu.size(); i++)
	{
		XanhPiuPiu[i]->clean();
	}
	XanhPiuPiu.clear();
	for (auto it = Chuong.begin(); it != Chuong.end(); it++)
	{
		it->first->clean();
	}
	Chuong.clear();

	for (int i = 0;i<ChucNang.size();i++)
	{
		ChucNang[i]->clean();
	}
	ChucNang.clear();	
	chuong.clear();

	GameOverState::PathNguoiRaDi = ChangeCharacterState::pathPhgID;
	GameOverState::width = ChangeCharacterState::menuw;
	GameOverState::height = ChangeCharacterState::menuh;
	GameOverState::frame = ChangeCharacterState::phgFrames;

	return true;
}