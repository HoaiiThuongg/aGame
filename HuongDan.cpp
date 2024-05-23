#include "HuongDan.h"
#include "DrawPic.h"
#include "Button.h"
#include "TextureManager.h"

const std::string HuongDan::s_huongDanName = "HUONGDAN";
int HuongDan::open = 0;

void HuongDan::update()
{
	huongDan->update();

	if(open == 0)
	{
		for (int i = 0; i < button.size(); i++)
		{
			button[i]->update();
		}
	}
	else 
	{
		xbutton->update();
	}

}

void HuongDan::render()
{
	huongDan->draw();
	if(open ==0)
	{
		for (int i = 0; i < button.size(); i++)
		{
			button[i]->draw();
		}
	}
	else if (open == 1)
	{
		one->draw();
		xbutton->draw();
	}
	else if (open == 2)
	{
		two->draw();
		xbutton->draw();
	}
	else if (open == 3)
	{
		three->draw();
		xbutton->draw();
	}
}
bool HuongDan::onEnter()
{
	if (!TheTextureManager::Instance()->load("image/bgr.png",
		"hdBgr", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Back.png",
		"Back", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/cachChoi.png",
		"cachChoi", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/chucNang.png",
		"chucNang", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/cotChuyen.png",
		"cotChuyen", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/cachChoii.png",
		"cachChoii", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/chucNangg.png",
		"chucNangg", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/cotChuyenn.png",
		"cotChuyenn", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Xbutton.png",
		"x", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	huongDan = new DrawPic(new LoaderParams(0, 0, 800, 640, "hdBgr"), 1, 1);
	Button*  back = new Button(new LoaderParams(500, 500, 39, 33, "Back"),2, Back);
	Button* cachChoi = new Button(new LoaderParams(130, 300, 134, 144, "cachChoi"), 1, One);
	Button* chucNang = new Button(new LoaderParams(330, 300, 134, 144, "chucNang"), 1, Two);
	Button* cotChuyen = new Button(new LoaderParams(530, 300, 134, 144, "cotChuyen"), 1, Three);

	one = new DrawPic(new LoaderParams(140, 40, 529, 546, "cachChoii"), 1, 1);
	two = new DrawPic(new LoaderParams(140, 40, 529, 546, "chucNangg"), 1, 1);
	three = new DrawPic(new LoaderParams(140, 40, 529, 546, "cotChuyenn"), 1, 1);
	xbutton = new Button(new LoaderParams(270, 110, 26, 26, "x"), 1, X);

	button.push_back(back);
	button.push_back(cachChoi);
	button.push_back(chucNang);
	button.push_back(cotChuyen);
	return true;
}

bool HuongDan::onExit()
{
	huongDan->clean();
	one->clean();
	two->clean();
	three->clean();
	xbutton->clean();

	for (int i = 0; i < button.size(); i++)
	{
		button[i]->clean();
	}
	button.clear();
	return true;
}

void HuongDan::One()
{
	open = 1;
}

void HuongDan::Two()
{
	open = 2;
}

void HuongDan::Three()
{
	open = 3;
}

void HuongDan::X()
{
	open = 0;
}

void HuongDan::Back()
{
	TheGame::Instance()->getStateMachine()->popState();
}