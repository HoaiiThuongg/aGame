#include "DieuTraState.h"
#include "DrawPic.h"
#include "Button.h"
#include "TextureManager.h"
#include "Vector2D.h"
#include "TTF.h"
#include "fstream"

const std::string DieuTraState::s_dieuTraID = "DIEUTRA";

int DieuTraState::s1Ok;
int DieuTraState::s2Ok;
int DieuTraState::s3Ok;
int DieuTraState::s4Ok;
int DieuTraState::state=0;

void DieuTraState::update()
{
	DTWrite.UpdateStatic();
	bgr->update();
	chuot->updateChuot(mouse->getX()-30, mouse->getY()-30);
	if(state == 0)
	{
		for (int i = 0; i < m_dieuTra.size(); i++)
		{
			m_dieuTra[i]->update();
		}
		if (m_dieuTra.size() == 5)
		{
			if (s2Ok == MoNhungChuaMua)
			{
				m_dieuTra[1]->changeRow1();
			}
			if (s3Ok == MoNhungChuaMua)
			{
				m_dieuTra[2]->changeRow1();
			}
			if (s4Ok == MoNhungChuaMua)
			{
				m_dieuTra[3]->changeRow1();
			}
			//update mua ban
			if (s1Ok == DaMua)
			{
				m_dieuTra[0]->changeRow1();
			}
			if (s2Ok == DaMua)
			{
				m_dieuTra[1]->changeRow2();
			}

			if (s3Ok == DaMua)
			{
				m_dieuTra[2]->changeRow2();
			}

			if (s4Ok == DaMua)
			{
				m_dieuTra[3]->changeRow2();
			}
		}
	}
	else if (state == 1)
	{
		next->update();
		returnn->update();
	}
	else if (state == 2)
	{
		returnn->update();
	}
	else if (state == 3)
	{
		returnn->update();
	}
	else if (state == 4)
	{
		toBossState->update();
		returnn->update();
	}
	else if (state == 5)
	{
		snake->update();
		returnn->update();
	}
}

void DieuTraState::render()
{
	bgr->draw();
	for (int i = 0; i < m_hinhAnh.size(); i++)
	{
		m_hinhAnh[i]->draw();
	}
	DTWrite.WriteNumber(TTF::coin, 85, 70);
	DTWrite.WriteNumber(TTF::food, 400, 70);
	if(state == 0)
	{
		for (int i = 0; i < m_dieuTra.size(); i++)
		{
			m_dieuTra[i]->draw();
		}
		if (m_dieuTra.size() == 5)
		{
			if (s1Ok == DaMua)
			{
				day1->draw();
			}
			if (s2Ok == DaMua)
			{
				day2->draw();
			}

			if (s3Ok == DaMua)
			{
				day3->draw();
			}
		}
	}
	else if (state == 1)
	{
		key1->draw();
		returnn->draw();
		next->draw();
	}
	else if (state == 2)
	{
		key2->draw();
		returnn->draw();
	}
	else if (state == 3)
	{
		key3->draw();
		returnn->draw();
	}
	else if (state == 4)
	{
		key4->draw();
		toBossState->draw();
		returnn->draw();
	}
	else if (state == 5)
	{
		key1Next->draw();
		snake->draw();
		returnn->draw();
	}
	chuot->draw();
}

bool DieuTraState::onEnter()
{
	if (!TheTextureManager::Instance()->load("image/TaiLieu1.png",
		"tl1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/TaiLieu2.png",
		"tl2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/TaiLieu3.png",
		"tl3", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/TaiLieu4.png",
		"tl4", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if(!TheTextureManager::Instance()->load("image/DieuTra.jpg",
		"bgrDT", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/mouse.png",
		"mouse", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Back.png",
		"Back", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Key1.png",
		"key1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Key1Next.png",
		"key1Next", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Key2.png",
		"key2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Key3.png",
		"key3", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Key4.png",
		"key4", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Xbutton.png",
		"x", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/BossState.png",
		"BS", TheGame::Instance()->getRenderer()))
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

	if (!TheTextureManager::Instance()->load("image/day1.png",
		"day1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/day2.png",
		"day2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/next.png",
		"next", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/SnakeState.png",
		"Snake", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	state = 0;

	day1 = new DrawPic(new LoaderParams(125, 200, 47, 7, "day1"), 5, 1);
	day2 = new DrawPic(new LoaderParams(125, 200, 46, 42, "day2"), 5, 1);
	day3 = new DrawPic(new LoaderParams(125, 400, 47, 7, "day1"), 5, 1);

	GameObject* coinPlace = new DrawPic(new LoaderParams(50, 50, 64, 32, "cPlace"), 2, 1);
	GameObject* keyPlace = new DrawPic(new LoaderParams(350, 50, 64, 32, "kPlace"), 2, 1);

	m_hinhAnh.push_back(coinPlace);
	m_hinhAnh.push_back(keyPlace);

	key1 = new DrawPic(new LoaderParams(150, 10, 483, 584, "key1"), 1, 1);
	key1Next = new DrawPic(new LoaderParams(150, 10, 483, 584, "key1Next"), 1, 1);
	key2 = new DrawPic(new LoaderParams(150, 10, 515, 584, "key2"), 1, 1);
	key3 = new DrawPic(new LoaderParams(150, 10, 516, 584, "key3"), 1, 1);
	key4 = new DrawPic(new LoaderParams(150, 10, 487, 584, "key4"), 1, 1);

	toBossState= new Button(new LoaderParams(330, 310, 64, 32, "BS"), 2, m_toBossState);

	bgr = new DrawPic(new LoaderParams(0, 0, 800, 640, "bgrDT"), 1, 1);
	Button* tl1 = new Button(new LoaderParams(100, 200, 13, 20, "tl1"),5, TL1);
	Button* tl2 = new Button(new LoaderParams(325, 200, 14, 21, "tl2"),5, TL2);
	Button* tl3 = new Button(new LoaderParams(100, 400, 15, 23, "tl3"),5, TL3);
	Button* tl4 = new Button(new LoaderParams(325, 400, 17, 22, "tl4"),5, TL4);
	Button* backButton = new Button(new LoaderParams(350, 530, 39,33, "Back"), 2, Back);
	next = new Button(new LoaderParams(580, 300, 30, 27, "next"), 3, Next);

	returnn = new Button(new LoaderParams(600, 30, 26,26, "x"), 1, Return);
	snake = new Button(new LoaderParams(200, 450, 64, 32, "Snake"), 2, toSnake);
	
	m_dieuTra.push_back(tl1);
	m_dieuTra.push_back(tl2);
	m_dieuTra.push_back(tl3);
	m_dieuTra.push_back(tl4);
	m_dieuTra.push_back(backButton);

	chuot = new DrawPic(new LoaderParams(mouse->getX(), mouse->getY(), 25, 25, "mouse"), 3, 1);

	std::ifstream file("font/dieuTra.txt");
	file >> s1Ok >> s2Ok >> s3Ok >> s4Ok;
	if (s1Ok == chuaMo) s1Ok = MoNhungChuaMua;
	file.close();

	return true;
}

bool DieuTraState::onExit()
{
	bgr->clean();
	returnn->clean();
	snake->clean();
	chuot->clean();
	key1->clean();
	key1Next->clean();
	key2->clean();
	key3->clean();
	key4->clean();
	day1->clean();
	day2->clean();
	day3->clean();

	toBossState->clean();
	next->clean();

	for (int i = 0; i < m_dieuTra.size(); i++)
	{
		m_dieuTra[i]->clean();
	}
	m_dieuTra.clear();

	for (int i = 0; i < m_hinhAnh.size(); i++)
	{
		m_hinhAnh[i]->clean();
	}
	m_hinhAnh.clear();

	std::ofstream file("font/dieuTra.txt");
	if (s1Ok == 3) s1Ok = 2;
	if (s2Ok == 3) s2Ok = 2;
	if (s3Ok == 3) s3Ok = 2;
	if (s4Ok == 3) s4Ok = 2;
	file <<s1Ok<<' '<< s2Ok << ' ' << s3Ok << ' ' << s4Ok;
	file.close();
	return true;
}

void DieuTraState::TL1()
{
	if (s1Ok == MoNhungChuaMua && TTF::food >= 10)
	{
		TTF::food -= 10;
		s1Ok = DaMua;
		s2Ok = MoNhungChuaMua;
		std::ofstream file("font/dieuTra.txt");
		if (s1Ok == 3) s1Ok = 2;
		if (s2Ok == 3) s2Ok = 2;
		if (s3Ok == 3) s3Ok = 2;
		if (s4Ok == 3) s4Ok = 2;
		file << s1Ok << ' ' << s2Ok << ' ' << s3Ok << ' ' << s4Ok;
		file.close();
	}
	else if(s1Ok == DaMua)
	{
		state = 1;
	}
}

void DieuTraState::TL2()
{
	if (s2Ok == MoNhungChuaMua && TTF::food >= 20)
	{
		TTF::food -= 20;
		s2Ok = DaMua;
		s3Ok = MoNhungChuaMua;
		std::ofstream file("font/dieuTra.txt");
		if (s1Ok == 3) s1Ok = 2;
		if (s2Ok == 3) s2Ok = 2;
		if (s3Ok == 3) s3Ok = 2;
		if (s4Ok == 3) s4Ok = 2;
		file << s1Ok << ' ' << s2Ok << ' ' << s3Ok << ' ' << s4Ok;
		file.close();
	}
	else if (s2Ok == DaMua)
	{
		state = 2;
	}
}

void DieuTraState::TL3()
{
	if (s3Ok == MoNhungChuaMua &&TTF::food >= 30)
	{
		TTF::food -= 30;
		s3Ok = DaMua;
		s4Ok = MoNhungChuaMua;
		std::ofstream file("font/dieuTra.txt");
		if (s1Ok == 3) s1Ok = 2;
		if (s2Ok == 3) s2Ok = 2;
		if (s3Ok == 3) s3Ok = 2;
		if (s4Ok == 3) s4Ok = 2;
		file << s1Ok << ' ' << s2Ok << ' ' << s3Ok << ' ' << s4Ok;
		file.close();
	}
	else if (s3Ok == DaMua)
	{
		state = 3;
	}
}

void DieuTraState::TL4()
{
	if (s4Ok == MoNhungChuaMua &&TTF::food >= 40)
	{
		TTF::food -= 40;
		s4Ok = DaMua;
		std::ofstream file("font/dieuTra.txt");
		if (s1Ok == 3) s1Ok = 2;
		if (s2Ok == 3) s2Ok = 2;
		if (s3Ok == 3) s3Ok = 2;
		if (s4Ok == 3) s4Ok = 2;
		file << s1Ok << ' ' << s2Ok << ' ' << s3Ok << ' ' << s4Ok;
		file.close();
	}
	else if (s4Ok == DaMua)
	{
		state = 4;
	}
}

void DieuTraState::Next()
{
	state = 5;
}