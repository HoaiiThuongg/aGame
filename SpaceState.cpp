#include "SpaceState.h"
#include <iostream>
#include "GameObject.h"
#include "TextureManager.h"
#include "Dino.h"
#include "InputHandle.h"
#include "GameOverState.h"
#include "Spaceship.h"
#include "Background.h"
#include "PhanDien.h"
#include "Bullet.h"
#include "MenuState.h"
#include "InputHandle.h"
#include <cstdlib> 
#include "TTF.h" 
#include "Button.h"
#include "ChangeCharacterState.h"
#include "DrawPic.h"

const std::string SpaceState::s_playID = "PLAY";
void SpaceState::Ban(int loaiDan)
{
	if (loaiDan == 0)
	{
		int n = 1;
		if (!spaceship->quayPhai())
		{
			n = -1;
		}
		Bullet* bullet;
		if (m_bullet.size() != 0)
		{
			if (spaceship->quayPhai())
			{
				if ((spaceship->getPosition().getX() + 300) < (m_bullet[m_bullet.size() - 1])->getPosition().getX())
				{
					bullet = new Bullet(new LoaderParams(gun->getPosition().getX() + gun->getWidth(),
						gun->getPosition().getY()
						, 11, 8, "bullet"), 1, n * 10);
					m_bullet.push_back(bullet);
					SSSound.PlayGunSound();
				}
			}
			else
			{
				if ((spaceship->getPosition().getX() - 300) > (m_bullet[m_bullet.size() - 1])->getPosition().getX())
				{
					bullet = new Bullet(new LoaderParams(gun->getPosition().getX(),
						gun->getPosition().getY()
						, 11, 8, "bullet"), 1, n * 10);
					m_bullet.push_back(bullet);
					SSSound.PlayGunSound();
				}

			}

		}
		else
		{
			if (n == 1)
			{
				bullet = new Bullet(new LoaderParams(gun->getPosition().getX() + gun->getWidth(),
					gun->getPosition().getY()
					, 11, 8, "bullet"), 1, n * 10);
				m_bullet.push_back(bullet);
				SSSound.PlayGunSound();
			}
			else
			{
				bullet = new Bullet(new LoaderParams(gun->getPosition().getX(),
					gun->getPosition().getY()
					, 11, 8, "bullet"), 1, n * 10);
				m_bullet.push_back(bullet);
				SSSound.PlayGunSound();
			}
		}
	}
	else if (loaiDan == 1)
	{
		int n = 1;
		if (!spaceship->quayPhai())
		{
			n = -1;
		}
		Bullet* bullet1;
		Bullet* bullet2;
		Bullet* bullet3;
		if (m_bullet.size() != 0)
		{
			if (n == 1)
			{
				if ((gun->getPosition().getX() + 300) < (m_bullet[m_bullet.size() - 1])->getPosition().getX())
				{
					bullet1 = new Bullet(new LoaderParams(gun->getPosition().getX() + gun->getWidth(),
						gun->getPosition().getY()
						, 11, 8, "bullet"), 1, n * 10);
					bullet2 = new Bullet(new LoaderParams(gun->getPosition().getX() + gun->getWidth() - 10,
						gun->getPosition().getY() + 20
						, 11, 8, "bullet"), 1, n * 10);
					bullet3 = new Bullet(new LoaderParams(gun->getPosition().getX() + gun->getWidth() - 10,
						gun->getPosition().getY() - 20
						, 11, 8, "bullet"), 1, n * 10);
					m_bullet.push_back(bullet1);
					m_bullet.push_back(bullet2);
					m_bullet.push_back(bullet3);
					SSSound.PlayGunSound();
				}
			}
			else
			{
				if ((gun->getPosition().getX() - 300) > (m_bullet[m_bullet.size() - 1])->getPosition().getX())
				{
					bullet1 = new Bullet(new LoaderParams(gun->getPosition().getX(),
						gun->getPosition().getY()
						, 11, 8, "bullet"), 1, n * 10);
					bullet2 = new Bullet(new LoaderParams(gun->getPosition().getX() + 10,
						gun->getPosition().getY() + 20
						, 11, 8, "bullet"), 1, n * 10);
					bullet3 = new Bullet(new LoaderParams(gun->getPosition().getX() + 10,
						gun->getPosition().getY() - 20
						, 11, 8, "bullet"), 1, n * 10);
					m_bullet.push_back(bullet1);
					m_bullet.push_back(bullet2);
					m_bullet.push_back(bullet3);
					SSSound.PlayGunSound();
				}
			}

		}
		else
		{
			if (n == 1)
			{
				bullet1 = new Bullet(new LoaderParams(gun->getPosition().getX() + gun->getWidth(),
					gun->getPosition().getY()
					, 11, 8, "bullet"), 1, n * 10);
				bullet2 = new Bullet(new LoaderParams(gun->getPosition().getX() + gun->getWidth() - 10,
					gun->getPosition().getY() + 20
					, 11, 8, "bullet"), 1, n * 10);
				bullet3 = new Bullet(new LoaderParams(gun->getPosition().getX() + gun->getWidth() - 10,
					gun->getPosition().getY() - 20
					, 11, 8, "bullet"), 1, n * 10);
				m_bullet.push_back(bullet1);
				m_bullet.push_back(bullet2);
				m_bullet.push_back(bullet3);
				SSSound.PlayGunSound();
			}
			else
			{
				bullet1 = new Bullet(new LoaderParams(gun->getPosition().getX(),
					gun->getPosition().getY()
					, 11, 8, "bullet"), 1, n * 10);
				bullet2 = new Bullet(new LoaderParams(gun->getPosition().getX() + 10,
					gun->getPosition().getY() + 20
					, 11, 8, "bullet"), 1, n * 10);
				bullet3 = new Bullet(new LoaderParams(gun->getPosition().getX() + 10,
					gun->getPosition().getY() - 20
					, 11, 8, "bullet"), 1, n * 10);
				m_bullet.push_back(bullet1);
				m_bullet.push_back(bullet2);
				m_bullet.push_back(bullet3);
				SSSound.PlayGunSound();
			}
		}
	}
}

void SpaceState::update()
{
	//phan dien
	if (spaceship->quayPhai())
	{
		gun->updateChuot(spaceship->getPosition().getX() + (spaceship->getWidth() / 2) - 10,
			30 + spaceship->getPosition().getY());
	}
	else
	{
		gun->updateChuot(spaceship->getPosition().getX() + (spaceship->getWidth() / 2) - 45,
			30 + spaceship->getPosition().getY());
	}
	for (int i = 0; i < button.size(); i++)
	{
		button[i]->update();
	}
	if (cheDo == normal)
	{
		if (m_moi.size() != 0)
		{
			if (200 > (m_moi[m_moi.size() - 1])->getPosition().getX())
			{
				int y = (SDL_GetTicks() % 5 + 1) * 100;
				PhanDien* octopus = new PhanDien(new LoaderParams(800, y, 13, 16, "ocMoi"), 2, 4, 1);
				m_moi.push_back(octopus);
			}
		}
		else
		{
			int y = (SDL_GetTicks() % 5 + 1) * 100;
			PhanDien* octopus = new PhanDien(new LoaderParams(800, y, 13, 16, "ocMoi"), 2, 4, 1);
			m_moi.push_back(octopus);
		}

		if (m_thuong.size() != 0)
		{
			if (400 > (m_thuong[m_thuong.size() - 1])->getPosition().getX())
			{
				int y = (SDL_GetTicks() % 5 + 1) * 100;
				PhanDien* octopus = new PhanDien(new LoaderParams(800, y, 13, 16, "octopus"), 1, 4, 3);
				m_thuong.push_back(octopus);
			}
		}
		else
		{
			int y = (SDL_GetTicks() % 5 + 1) * 100;
			PhanDien* octopus = new PhanDien(new LoaderParams(800, y, 13, 16, "octopus"), 1, 4, 3);
			m_thuong.push_back(octopus);
		}

		if (m_xanhchuoi.size() != 0)
		{
			if (400 > (m_xanhchuoi[m_xanhchuoi.size() - 1])->getPosition().getX())
			{
				int y = (SDL_GetTicks() % 10 + 1) * 50;
				PhanDien* xanhchuoi = new PhanDien(new LoaderParams(800, y, 13, 16, 1, "ocXanhChuoi"), 2, 4, 2);
				m_xanhchuoi.push_back(xanhchuoi);
			}
		}
		else
		{
			int y = (SDL_GetTicks() % 10 + 1) * 50;
			PhanDien* xanhchuoi = new PhanDien(new LoaderParams(800, y, 13, 16, 1, "ocXanhChuoi"), 2, 4, 2);
			m_xanhchuoi.push_back(xanhchuoi);
		}

		spaceBgr.update();
		spaceship->update();
		money->updateMoney();
		// check va cham
		for (int i = 0; i < m_thuong.size(); i++)
		{
			if (m_thuong[i]->appear == true)
			{
				for (int j = 0; j < m_bullet.size(); j++)
				{
					if (m_bullet[j]->validDan == true)
					{
						if (checkVa(m_thuong[i]->getPosition().getX(), m_thuong[i]->getPosition().getY(),
							m_thuong[i]->getWidth(), m_thuong[i]->getHeight(),
							m_bullet[j]->getPosition().getX(), m_bullet[j]->getPosition().getY(),
							m_bullet[j]->getWidth(), m_bullet[j]->getHeight()))
						{
							m_thuong[i]->appear = false;
							m_bullet[j]->validDan = false;
							if (!m_thuong[i]->switchh)
							{
								SSSound.PlayOcSound();
							}
							kill++;
							Bullet::banTruot = 0;
						}
					}
				}
			}
		}

		for (int i = 0; i < m_moi.size(); i++)
		{
			if (m_moi[i]->appear == true)
			{
				for (int j = 0; j < m_bullet.size(); j++)
				{
					if (m_bullet[j]->validDan == true)
					{
						if (checkVa(m_moi[i]->getPosition().getX(), m_moi[i]->getPosition().getY(),
							m_moi[i]->getWidth(), m_moi[i]->getHeight(),
							m_bullet[j]->getPosition().getX(), m_bullet[j]->getPosition().getY(),
							m_bullet[j]->getWidth(), m_bullet[j]->getHeight()))
						{
							if (!m_moi[i]->switchh)
							{
								SSSound.PlayOcSound();
							}
							m_moi[i]->switchh = true;
							m_bullet[j]->validDan = false;
							kill++;
							Bullet::banTruot = 0;
						}
					}
				}
				if (m_moi[i]->switchh == true)
				{
					if (checkVa(m_moi[i]->getPosition().getX(), m_moi[i]->getPosition().getY(),
						m_moi[i]->getWidth(), m_moi[i]->getHeight(),
						spaceship->getPosition().getX(), spaceship->getPosition().getY(),
						spaceship->getWidth(), spaceship->getHeight()))
					{
						TTF::coin++;
						m_moi[i]->appear = false;
						SSSound.PlayCoinSound();
					}
				}
			}
		}
		for (int i = 0; i < m_xanhchuoi.size(); i++)
		{
			if (m_xanhchuoi[i]->appear == true)
			{
				for (int j = 0; j < m_bullet.size(); j++)
				{
					if (m_bullet[j]->validDan == true)
					{
						if (checkVa(m_xanhchuoi[i]->getPosition().getX(), m_xanhchuoi[i]->getPosition().getY(),
							m_xanhchuoi[i]->getWidth(), m_xanhchuoi[i]->getHeight(),
							m_bullet[j]->getPosition().getX(), m_bullet[j]->getPosition().getY(),
							m_bullet[j]->getWidth(), m_bullet[j]->getHeight()))
						{
							if (!m_xanhchuoi[i]->switchh)
							{
								SSSound.PlayOcSound();
							}
							m_xanhchuoi[i]->switchh = true;
							m_bullet[j]->validDan = false;
							kill++;
							Bullet::banTruot = 0;
						}
					}
				}
				if (m_xanhchuoi[i]->switchh == true)
				{
					if (checkVa(m_xanhchuoi[i]->getPosition().getX(), m_xanhchuoi[i]->getPosition().getY(),
						m_xanhchuoi[i]->getWidth(), m_xanhchuoi[i]->getHeight(),
						spaceship->getPosition().getX(), spaceship->getPosition().getY(),
						spaceship->getWidth(), spaceship->getHeight()))
					{
						TTF::coin++;
						m_xanhchuoi[i]->appear = false;
						SSSound.PlayCoinSound();
					}
				}
			}
		}
		//bullet
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
		{
			Ban(ChangeCharacterState::loaiDan);
		}

		for (int i = 0; i < m_bullet.size(); i++)
		{
			m_bullet[i]->update();
		}
		//check Die
		for (int i = 0; i < m_thuong.size(); i++)
		{
			if (m_thuong[i]->switchh == false &&
				checkVa(spaceship->getPosition().getX(), spaceship->getPosition().getY(),
					spaceship->getWidth(), spaceship->getHeight(),
					m_thuong[i]->getPosition().getX(), m_thuong[i]->getPosition().getY(),
					m_thuong[i]->getWidth(), m_thuong[i]->getHeight()))
			{
				cheDo = die;
				SSSound.PlayDieSound();
			}
		}

		for (int i = 0; i < m_moi.size(); i++)
		{
			if (m_moi[i]->switchh == false &&
				checkVa(spaceship->getPosition().getX(), spaceship->getPosition().getY(),
					spaceship->getWidth(), spaceship->getHeight(),
					m_moi[i]->getPosition().getX(), m_moi[i]->getPosition().getY(),
					m_moi[i]->getWidth(), m_moi[i]->getHeight()))
			{
				cheDo = die;
				SSSound.PlayDieSound();
			}
		}

		for (int i = 0; i < m_xanhchuoi.size(); i++)
		{
			if (m_xanhchuoi[i]->switchh == false &&
				checkVa(spaceship->getPosition().getX(), spaceship->getPosition().getY(),
					spaceship->getWidth(), spaceship->getHeight(),
					m_xanhchuoi[i]->getPosition().getX(), m_xanhchuoi[i]->getPosition().getY(),
					m_xanhchuoi[i]->getWidth(), m_xanhchuoi[i]->getHeight()))
			{
				cheDo = die;
				SSSound.PlayDieSound();
			}
		}

		if (money->isKey && checkVa(spaceship->getPosition().getX(), spaceship->getPosition().getY(),
			spaceship->getWidth(), spaceship->getHeight(),
			money->getPosition().getX(), money->getPosition().getY(),
			money->getWidth(), money->getHeight()))
		{
			money->isKey = false;
			TTF::coin += 10;
			SSSound.PlayCoinSound();
		}


		//update di chuyen
		for (int i = 0; i < m_thuong.size(); i++)
		{
			m_thuong[i]->updateSpecial(spaceship->getPosition().getY());
		}

		for (int i = 0; i < m_moi.size(); i++)
		{
			m_moi[i]->updateSpecial(spaceship->getPosition().getY());
		}

		for (int i = 0; i < m_xanhchuoi.size(); i++)
		{
			m_xanhchuoi[i]->update();
		}

		//diRaaaa
		for (int i = 0; i < m_bullet.size(); i++)
		{
			for (int j = 0; j < m_moi.size(); j++)
			{
				if (m_bullet[i]->getPosition().getY() >= m_moi[j]->getPosition().getY()
					&& m_bullet[i]->getPosition().getY() <= m_moi[j]->getPosition().getY() + m_moi[j]->getHeight()
					&& m_bullet[i]->getPosition().getX() < m_moi[j]->getPosition().getX()
					&& m_moi[j]->getPosition().getX() - m_bullet[i]->getPosition().getX() < 20
					&& m_moi[j]->getPosition().getY() >= spaceship->getPosition().getY()
					&& m_moi[j]->getPosition().getY() <= spaceship->getPosition().getY() + spaceship->getHeight()
					&& m_moi[j]->switchh == false)
				{
					m_moi[j]->diRa();
				}
			}
		}

		//write
		spaceWrite.UpdateStatic();

		//xoa dan hu
		if (m_bullet.size() != 0)
		{
			if (m_bullet[0]->validDan == false)
			{
				m_bullet.erase(m_bullet.begin() + 0);
			}
		}

		for (int i = 0; i < m_thuong.size(); i++)
		{
			if (m_thuong[i]->appear == false)
			{
				m_thuong.erase(m_thuong.begin() + i);
			}
		}

		for (int i = 0; i < m_moi.size(); i++)
		{
			if (m_moi[i]->appear == false)
			{
				m_moi.erase(m_moi.begin() + i);
			}
		}

		for (int i = 0; i < m_xanhchuoi.size(); i++)
		{
			if (m_xanhchuoi[i]->appear == false)
			{
				m_xanhchuoi.erase(m_xanhchuoi.begin() + i);
			}
		}

		if (kill == 10)
		{
			cheDo = bigBoss;
			SSSound.PlayChonDie();
		}
	}
	else if (cheDo == die)
	{
		lenThienDang();
		spaceship->dead();
		if (spaceship->getPosition().getY() <= 0)
		{
			TheGame::Instance()->getStateMachine()->changeState(new GameOverState);
		}
	}
	else if (cheDo == bigBoss)
	{
		bigOc->updateBigOc();
		spaceBgr.update();
		spaceship->update();
		money->update();

		for (int i = 0; i < m_bullet.size(); i++)
		{
			m_bullet[i]->update();
		}
		for (int i = 0; i < m_thuong.size(); i++)
		{
			m_thuong[i]->updateBigOcState();
		}

		for (int i = 0; i < m_moi.size(); i++)
		{
			m_moi[i]->updateBigOcState();
		}

		for (int i = 0; i < m_xanhchuoi.size(); i++)
		{
			m_xanhchuoi[i]->updateBigOcState();
		}
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
		{
			Ban(ChangeCharacterState::loaiDan);
		}

		//check ban trung
		if (money->isKey && checkVa(spaceship->getPosition().getX(), spaceship->getPosition().getY(),
			spaceship->getWidth(), spaceship->getHeight(),
			money->getPosition().getX(), money->getPosition().getY(),
			money->getWidth(), money->getHeight()))
		{
			money->isKey = false;
			TTF::coin += 50;
			SSSound.PlayCoinSound();
		}
		for (int i = 0; i < m_bullet.size(); i++)
		{
			if (checkVa(m_bullet[i]->getPosition().getX(), m_bullet[i]->getPosition().getY(),
				m_bullet[i]->getWidth(), m_bullet[i]->getHeight(),
				bigOc->getPosition().getX(), bigOc->getPosition().getY(),
				bigOc->getWidth(), bigOc->getHeight()))
			{
				mauBig--;
				m_bullet[i]->validDan = false;
			}
		}

		for (int i = 0; i < m_thuong.size(); i++)
		{
			if (m_thuong[i]->appear == true)
			{
				for (int j = 0; j < m_bullet.size(); j++)
				{
					if (m_bullet[j]->validDan == true)
					{
						if (checkVa(m_thuong[i]->getPosition().getX(), m_thuong[i]->getPosition().getY(),
							m_thuong[i]->getWidth(), m_thuong[i]->getHeight(),
							m_bullet[j]->getPosition().getX(), m_bullet[j]->getPosition().getY(),
							m_bullet[j]->getWidth(), m_bullet[j]->getHeight()))
						{
							m_thuong[i]->appear = false;
							m_bullet[j]->validDan = false;
							if (!m_thuong[i]->switchh)
							{
								SSSound.PlayOcSound();
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < m_moi.size(); i++)
		{
			if (m_moi[i]->appear == true)
			{
				for (int j = 0; j < m_bullet.size(); j++)
				{
					if (m_bullet[j]->validDan == true)
					{
						if (checkVa(m_moi[i]->getPosition().getX(), m_moi[i]->getPosition().getY(),
							m_moi[i]->getWidth(), m_moi[i]->getHeight(),
							m_bullet[j]->getPosition().getX(), m_bullet[j]->getPosition().getY(),
							m_bullet[j]->getWidth(), m_bullet[j]->getHeight()))
						{
							if (!m_moi[i]->switchh)
							{
								SSSound.PlayOcSound();
							}
							m_moi[i]->appear = false;
						}
					}
				}
			}
		}


		for (int i = 0; i < m_xanhchuoi.size(); i++)
		{
			if (m_xanhchuoi[i]->appear == true)
			{
				for (int j = 0; j < m_bullet.size(); j++)
				{
					if (m_bullet[j]->validDan == true)
					{
						if (checkVa(m_xanhchuoi[i]->getPosition().getX(), m_xanhchuoi[i]->getPosition().getY(),
							m_xanhchuoi[i]->getWidth(), m_xanhchuoi[i]->getHeight(),
							m_bullet[j]->getPosition().getX(), m_bullet[j]->getPosition().getY(),
							m_bullet[j]->getWidth(), m_bullet[j]->getHeight()))
						{
							if (!m_xanhchuoi[i]->switchh)
							{
								SSSound.PlayOcSound();
							}
							m_xanhchuoi[i]->appear = false;
							m_bullet[j]->validDan = false;
						}
					}
				}
			}
		}

		for (int i = 0; i < m_danDuoi.size(); i++)
		{
			if (checkVa(m_danDuoi[i]->getPosition().getX(), m_danDuoi[i]->getPosition().getY(),
				m_danDuoi[i]->getWidth(), m_danDuoi[i]->getHeight(),
				spaceship->getPosition().getX(), spaceship->getPosition().getY(),
				spaceship->getWidth(), spaceship->getHeight()))
			{
				cheDo = die;
			}
		}

		for (int i = 0; i < m_xanhchuoi.size(); i++)
		{
			if (checkVa(m_xanhchuoi[i]->getPosition().getX(), m_xanhchuoi[i]->getPosition().getY(),
				m_xanhchuoi[i]->getWidth(), m_xanhchuoi[i]->getHeight(),
				spaceship->getPosition().getX(), spaceship->getPosition().getY(),
				spaceship->getWidth(), spaceship->getHeight()))
			{
				if (m_xanhchuoi[i]->switchh == true)
				{
					TTF::coin++;
					m_xanhchuoi[i]->appear = false;
					SSSound.PlayCoinSound();
				}
				else
				{
					cheDo = die;
				}
			}
		}
		for (int i = 0; i < m_moi.size(); i++)
		{
			if (checkVa(m_moi[i]->getPosition().getX(), m_moi[i]->getPosition().getY(),
				m_moi[i]->getWidth(), m_moi[i]->getHeight(),
				spaceship->getPosition().getX(), spaceship->getPosition().getY(),
				spaceship->getWidth(), spaceship->getHeight()))
			{
				if (m_moi[i]->switchh == true)
				{
					TTF::coin++;
					m_moi[i]->appear = false;
					SSSound.PlayCoinSound();
				}
				else
				{
					cheDo = die;
				}
			}
		}
		for (int i = 0; i < m_thuong.size(); i++)
		{
			if (checkVa(m_thuong[i]->getPosition().getX(), m_thuong[i]->getPosition().getY(),
				m_thuong[i]->getWidth(), m_thuong[i]->getHeight(),
				spaceship->getPosition().getX(), spaceship->getPosition().getY(),
				spaceship->getWidth(), spaceship->getHeight()))
			{
				if (m_thuong[i]->switchh == true)
				{
					TTF::coin++;
					m_thuong[i]->appear = false;
					SSSound.PlayCoinSound();
				}
				else
				{
					cheDo = die;
				}
			}
		}

		if (checkVa(bigOc->getPosition().getX(), bigOc->getPosition().getY(),
			bigOc->getWidth(), bigOc->getHeight(),
			spaceship->getPosition().getX(), spaceship->getPosition().getY(),
			spaceship->getWidth(), spaceship->getHeight()))
		{
			cheDo = die;
		}
		if (!banDanDuoi)
		{
			dem++;
			if (dem == gioihan)
			{
				banDanDuoi = true;
			}
		}
		if (banDanDuoi)
		{
			if(spaceship->getPosition().getY()>= bigOc->getPosition().getY() &&
				spaceship->getPosition().getY() <= bigOc->getPosition().getY() + bigOc->getHeight())
			{
				Bullet* bullet = new Bullet(new LoaderParams(bigOc->getPosition().getX(),
					spaceship->getPosition().getY()
					, 11, 8, "bullet"), 4, -5,2);
				m_danDuoi.push_back(bullet);
				banDanDuoi = false;
				dem = 0;
			}
		}

		for (int i = 0; i < m_danDuoi.size(); i++)
		{
			m_danDuoi[i]->update();
		}

		if (mauBig < 0)
		{
			cheDo = normal;
			mauBig = 100;
			bigOc->changeRow0();
			kill = 0;
			bigOc->updateSpeedBig = 0;
			bigOc->updateSpeed+=3;
			bigOc->BigDie();
			m_danDuoi.clear();
			gioihan = 100;

			TTF::coin += 50;
			TTF::coin += 20;
			SSSound.PlayCoinSound();
		}

		if (mauBig == 70)
		{
			bigOc->updateSpeedBig = 5;
			bigOc->changeRow1();
			gioihan = 70;
		}

		if (mauBig == 40)
		{
			bigOc->updateSpeedBig = 10;
			bigOc->changeRow2();
			gioihan = 50;
		}

		//xoa
		if (m_bullet.size() != 0)
		{
			if (m_bullet[0]->validDan == false)
			{
				m_bullet.erase(m_bullet.begin() + 0);
			}
		}

		if (m_danDuoi.size() != 0)
		{
			if (m_danDuoi[0]->validDan == false)
			{
				m_danDuoi.erase(m_danDuoi.begin() + 0);
			}
		}
		for (int i = 0; i < m_thuong.size(); i++)
		{
			if (m_thuong[i]->appear == false)
			{
				m_thuong.erase(m_thuong.begin() + i);
			}
		}

		for (int i = 0; i < m_moi.size(); i++)
		{
			if (m_moi[i]->appear == false)
			{
				m_moi.erase(m_moi.begin() + i);
			}
		}

		for (int i = 0; i < m_xanhchuoi.size(); i++)
		{
			if (m_xanhchuoi[i]->appear == false)
			{
				m_xanhchuoi.erase(m_xanhchuoi.begin() + i);
			}
		}
	}
}

void SpaceState::render()
{
	spaceBgr.draw();
	for (int i = 0; i < m_thuong.size(); i++)
	{
		m_thuong[i]->draw();
	}
	for (int i = 0; i < m_xanhchuoi.size(); i++)
	{
		m_xanhchuoi[i]->draw();
	}
	for (int i = 0; i < m_moi.size(); i++)
	{
		m_moi[i]->draw();
	}
	for (int i = 0; i < m_danDuoi.size(); i++)
	{
		m_danDuoi[i]->draw();
	}

	spaceship->draw();
	gun->drawFlip();
	money->draw();
	bigOc->draw();

	for (int i = 0; i < button.size(); i++)
	{
		button[i]->draw();
	}
	for (int i = 0; i < m_bullet.size(); i++)
	{
		m_bullet[i]->draw();
	}

	if(cheDo == normal)
	{
		if (Bullet::banTruot >= 5 && Bullet::banTruot <= 10)
		{
			spaceWrite.Write(100, 590, "Ban da ban truot rat nhieu :<<");
		}
		if (Bullet::banTruot == 5)
		{
			SSSound.PlayTruotFive();
			Bullet::banTruot++;
		}
	}

	spaceWrite.WriteNumber(TTF::coin, 430, 53);
	spaceWrite.WriteNumber(TTF::food, 640, 53);
}

bool SpaceState::onEnter()
{
	Bullet::banTruot = 0;
	bigOc->updateSpeedBig = 0;
	bigOc->updateSpeed = 0;


	spaceBgr.load(2176, 640, "image/bgrSpace.png", "bgrSpace");
	if (ChangeCharacterState::loaiDan == -1)
	{
		ChangeCharacterState::loaiDan = 0;
		ChangeCharacterState::pathGunID = "image/aka.png";
		ChangeCharacterState::widthG = 65;
		ChangeCharacterState::heightG = 16;
		ChangeCharacterState::framesG = 1;
	}
	if (ChangeCharacterState::pathSpaceID == "")
	{
		ChangeCharacterState::pathSpaceID = "image/PhiHanhGia1.png";
		ChangeCharacterState::phgWidth = 22;
		ChangeCharacterState::phgHeight = 32;
		ChangeCharacterState::phgFrames = 4;
		ChangeCharacterState::speed = 5;
	}


	if (!TheTextureManager::Instance()->load(ChangeCharacterState::pathSpaceID,
		"phg", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg";
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Bullet.png",
		"bullet", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load bullet";
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Alien.png",
		"octopus", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail oc5";
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/AlienMoi.png",
		"ocMoi", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail oc4";
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/AlienXanhChuoi.png",
		"ocXanhChuoi", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail oc3";
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Back.png",
		"Back", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail oc2";
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/CoinPlace.png",
		"cPlace", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail pl";
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/KeyPlace.png",
		"kPlace", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail pl";
		return false;
	}

	if (!TheTextureManager::Instance()->load(ChangeCharacterState::pathGunID,
		"gun", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail gun";
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/money.png",
		"money", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail money";
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/AlienVua.png",
		"ocBig", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail oc1";
		return false;
	}
	GameObject* button1 = new Button(new LoaderParams(600, 500, 39,
		33, "Back"), 2, Back);

	button.push_back(button1);

	PhanDien* oc = new PhanDien(new LoaderParams(800, 200, 13, 16, 1, "octopus"), 1, 4, 2);
	m_thuong.push_back(oc);

	PhanDien* moi = new PhanDien(new LoaderParams(900, 400, 13, 16, 1, "ocMoi"), 2, 4, 2);
	m_moi.push_back(moi);

	PhanDien* xanhchuoi = new PhanDien(new LoaderParams(500, 300, 13, 16,1, "ocXanhChuoi"), 2,4,2);
	m_xanhchuoi.push_back(xanhchuoi);

	spaceship = new Spaceship(new LoaderParams(10, 320, ChangeCharacterState::phgWidth, 
		ChangeCharacterState::phgHeight, 
		"phg"), 2, ChangeCharacterState::phgFrames,ChangeCharacterState::speed);

	gun = new DrawPic(new LoaderParams(10 + ChangeCharacterState::phgWidth/2, 350, ChangeCharacterState::widthG,
		ChangeCharacterState::heightG,"gun"),1,1);

	money = new DrawPic(new LoaderParams(800, 200,24,12,
		"money"),3,2);

	GameObject* coinPlace = new DrawPic(new LoaderParams(400, 30, 64, 32, "cPlace"), 2, 1);
	GameObject* keyPlace = new DrawPic(new LoaderParams(600, 30, 64, 32, "kPlace"), 2, 1);
	button.push_back(coinPlace);
	button.push_back(keyPlace);

	bigOc = new PhanDien(new LoaderParams(900, 250, 13, 16, 1, "ocBig"),15, 4, 2);
	m_moi.push_back(moi);

	Spaceship::i = 0;
	std::cout << "entering SpaceState\n";
	return true;
}

bool SpaceState::onExit()
{
	bigOc->updateSpeedBig = 0;
	bigOc->updateSpeed = 0;
	
	SSSound.resume();
	SSSound.Clean();
	GameOverState::PathNguoiRaDi = ChangeCharacterState::pathPhgID;
	GameOverState::width = ChangeCharacterState::menuw;
	GameOverState::height = ChangeCharacterState::menuh;
	GameOverState::frame = ChangeCharacterState::phgFrames;

	for (int i = 0; i < m_thuong.size(); i++)
	{
		m_thuong[i]->clean();
	}
	m_thuong.clear();
	for (int i = 0; i < m_bullet.size(); i++)
	{
		m_bullet[i]->clean();
	}
	m_bullet.clear();
	for (int i = 0; i < m_moi.size(); i++)
	{
		m_moi[i]->clean();
	}
	m_moi.clear();
	for (int i = 0; i < button.size(); i++)
	{
		button[i]->clean();
	}
	button.clear();
	for (int i = 0; i < m_xanhchuoi.size(); i++)
	{
		m_xanhchuoi[i]->clean();
	}
	m_xanhchuoi.clear();
	for (int i = 0; i < m_danDuoi.size(); i++)
	{
		m_danDuoi[i]->clean();
	}
	m_danDuoi.clear();

	gun->clean();
	spaceBgr.clean();
	spaceship->clean();
	money->clean();
	bigOc->clean();
	money->clean();

	std::vector<Bullet*>().swap(m_bullet);

	spaceWrite.Clean();
	std::cout << "exiting SpaceState\n";
	return true;
}

bool SpaceState::checkVa(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	if (x1 + w1 > x2 &&
		x2 + w2 > x1 &&
		y1 + h1 > y2 &&
		y2 + h2 > y1)
		return true;

	return false;
}

void SpaceState::Back()
{
	TheGame::Instance()->getStateMachine()->changeState(new
		MenuState());
}