#include "ChangeCharacterState.h"
#include "Button.h"
#include "TextureManager.h"
#include "MenuState.h"
#include "Background.h" 
#include "DrawPic.h"

Background characBgr;

std::string ChangeCharacterState::pathPhgID;
std::string ChangeCharacterState::pathAvaID;
std::string ChangeCharacterState::pathSpaceID;
int ChangeCharacterState::phgWidth;
int ChangeCharacterState::phgHeight;
int ChangeCharacterState::phgFrames;

std::string ChangeCharacterState::pathID ;
int ChangeCharacterState::width;
int ChangeCharacterState:: height;
int ChangeCharacterState::frames;
int ChangeCharacterState::speed;
int ChangeCharacterState::state = 1;
int ChangeCharacterState::menuw;
int ChangeCharacterState::menuh;

int ChangeCharacterState::phg2Ok;
int ChangeCharacterState::phg3Ok;
int ChangeCharacterState::phg4Ok;
int ChangeCharacterState::kl2Ok;
int ChangeCharacterState::gun2Ok;

int ChangeCharacterState::loaiDan=-1;
std::string ChangeCharacterState::pathGunID;
int ChangeCharacterState::widthG;
int ChangeCharacterState::heightG;
int ChangeCharacterState::framesG;

DrawPic* ChangeCharacterState::here;

const std::string ChangeCharacterState::s_characterID = "CHANGECHARACTER";

void ChangeCharacterState::update()
{
	chaWrite.UpdateStatic();
	for (int i = 0; i < button.size(); i++)
	{
		button[i]->update();
	}
	if (state == 1)
	{
		for (int i = 0; i < state1.size(); i++)
		{
			state1[i]->update();
		}
	}
	if (state == 2)
	{
		for (int i = 0; i < state2.size(); i++)
		{
			state2[i]->update();
		}
	}
	if (state == 3)
	{
		for (int i = 0; i < state3.size(); i++)
		{
			state3[i]->update();
		}
	}

	if (phg2Ok == DaMua && state1.size() >= 2)
	{
		state1.erase(state1.begin() + 1);
		GameObject* phg02 = new Button(new LoaderParams(250, 250, 48,
			40, "phg2"), 2, phg2);
		auto it = state1.begin() + 1;
		state1.insert(it, phg02);
		phg2Ok = DaXuLy;
	}

	if (phg3Ok == DaMua && state1.size() >= 3)
	{
		state1.erase(state1.begin() + 2);
		GameObject* phg03 = new Button(new LoaderParams(450, 250, 55,
			47, "phg3"), 2, phg3);
		auto it = state1.begin()+2; 
		state1.insert(it, phg03);
		phg3Ok = DaXuLy;
	}

	if (phg4Ok == DaMua && state1.size() >= 4)
	{
		state1.erase(state1.begin() + 3);
		GameObject* phg04 = new Button(new LoaderParams(650, 250, 24,
			14, "phg4"), 3, phg4);
		auto it = state1.begin() + 3;
		state1.insert(it, phg04);
		phg4Ok = DaXuLy;
	}

	if (kl2Ok == DaMua && state2.size() >= 2)
	{
		state2.erase(state2.begin() + 1);
		GameObject* kl2 = new Button(new LoaderParams(250, 250, 31,
			22, "kl2"), 3, KLXanh);
		auto it = state2.begin() + 1;
		state2.insert(it, kl2);
		kl2Ok = DaXuLy;
	}

	if (gun2Ok == DaMua && state3.size() >= 2)
	{
		state3.erase(state3.begin() + 1);
		GameObject* gun2 = new Button(new LoaderParams(250, 250, 65,
			16, "gun2"), 2, gun02);
		auto it = state3.begin() + 1;
		state3.insert(it, gun2);
		gun2Ok = DaXuLy;
	}
}
void ChangeCharacterState::render()
{
	characBgr.draw();
	for (int i = 0; i < button.size(); i++)
	{
		button[i]->draw();
	}
	if (state == 1)
	{
		for (int i = 0; i < state1.size(); i++)
		{
			state1[i]->draw();
		}
	}
	if (state == 2)
	{
		for (int i = 0; i < state2.size(); i++)
		{
			state2[i]->draw();
		}
	}
	if (state == 3)
	{
		for (int i = 0; i < state3.size(); i++)
		{
			state3[i]->draw();
		}
	}
	here->draw();
	chaWrite.WriteNumber(TTF::coin, 430, 53);
	chaWrite.WriteNumber(TTF::food, 640, 53);
}
bool ChangeCharacterState::onEnter()
{
	CCSound.pause();
	CCSound.PlayCCSound();
	state = 1;
	if (!TheTextureManager::Instance()->load("image/PHG.png",
		"state1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/Dino.png",
		"state2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/Gun.png",
		"state3", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Back.png",
		"Back", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/KhungLongFrames.png",
		"kl1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/KhungLongXanh.png",
		"kl2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/KhungLongXanhUn.png",
		"kl2un", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/PhiHanhGia1.png",
		"phg1", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg1";
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/PhiHanhGia2.png",
		"phg2", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg2";
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/PhiHanhGia2Un.png",
		"phg2un", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg2un";
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/PhiHanhGia3.png",
		"phg3", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg3";
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/PhiHanhGia3Un.png",
		"phg3un", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg3";
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/PhiHanhGia4.png",
		"phg4", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/PhiHanhGia4Un.png",
		"phg4un", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/aka.png",
		"gun1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/akaPink.png",
		"gun2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/akaPinkUn.png",
		"gun2un", TheGame::Instance()->getRenderer()))
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

	if (!TheTextureManager::Instance()->load("image/here.png",
		"here", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	characBgr.load(800, 640, "image/Sky2.jpg", "characBgr");

	//button
	GameObject* button1 = new Button(new LoaderParams(50, 100, 36,
		20, "state1"), 3, nv);
	GameObject* button2 = new Button(new LoaderParams(250, 100, 36,
		20, "state2"), 3, kl);
	GameObject* button3 = new Button(new LoaderParams(450, 100, 36,
		20, "state3"), 3, dan);
	GameObject* button4 = new Button(new LoaderParams(400, 500, 39,
		33, "Back"), 2, Back);

	GameObject* coinPlace = new DrawPic(new LoaderParams(400, 30, 64, 32, "cPlace"), 2, 1);
	GameObject* keyPlace = new DrawPic(new LoaderParams(600, 30, 64, 32, "kPlace"), 2, 1);

	button.push_back(coinPlace);
	button.push_back(keyPlace);

	button.push_back(button1);
	button.push_back(button2);
	button.push_back(button3);
	button.push_back(button4);

	//phg
	GameObject* phg01 = new Button(new LoaderParams(50, 250, 22,
		32, "phg1"), 3, phg1);
	GameObject* phg02 = new Button(new LoaderParams(250, 250, 34,
		46, "phg2un"), 2, phg2);
	GameObject* phg03 = new Button(new LoaderParams(450, 250, 34,
		46, "phg3un"), 2, phg3);
	GameObject* phg04 = new Button(new LoaderParams(650, 250, 34,
		46, "phg4un"), 2, phg4);
	state1.push_back(phg01);
	state1.push_back(phg02);
	state1.push_back(phg03);
	state1.push_back(phg04);
	//klong
	GameObject* kl1 = new Button(new LoaderParams(50, 250, 25,
		25, "kl1"), 3, KLCam);
	GameObject* kl2 = new Button(new LoaderParams(250, 250, 34,
		46, "kl2un"), 2, KLXanh);
	state2.push_back(kl1);
	state2.push_back(kl2);
	//gun

	GameObject* gun1 = new Button(new LoaderParams(50, 250, 65,
		16, "gun1"), 2, gun01);
	GameObject* gun2 = new Button(new LoaderParams(250, 250, 34,
		46, "gun2un"), 2, gun02);
	state3.push_back(gun1);
	state3.push_back(gun2);

	here = new DrawPic(new LoaderParams(80, 230, 25, 13, "here"), 1, 1);

	if (pathPhgID == "image/PhiHanhGia1.png") { here->updateChuot(80, 230); }
	else if (pathPhgID == "image/PhiHanhGia22.png") { here->updateChuot(290, 230); }
	else if (pathPhgID == "image/PhiHanhGia33.png") { here->updateChuot(490, 230); }
	else if (pathPhgID == "image/BeHongNhun.png") { here->updateChuot(680, 230); }

	//buy
	std::ifstream phg("font/phg.txt");
	phg >> phg2Ok >> phg3Ok >> phg4Ok;
	phg.close();

	std::ifstream kl0("font/kl.txt");
	kl0 >> kl2Ok;
	kl0.close();

	std::ifstream gun0("font/gun.txt");
	gun0 >> gun2Ok;
	gun0.close();

	std::cout << "entering ChangeCharacterState\n";
	return true;
}
bool ChangeCharacterState::onExit()
{
	CCSound.resume();
	CCSound.Clean();
	characBgr.clean();
	chaWrite.Clean();
	here -> clean();

	for (int i = 0; i < button.size(); i++)
	{
		button[i]->clean();
	}
	button.clear();
	for (int i = 0; i < state1.size(); i++)
	{
		state1[i]->clean();
	}
	state1.clear();
	for (int i = 0; i < state2.size(); i++)
	{
		state2[i]->clean();
	}
	state2.clear();
	for (int i = 0; i < state3.size(); i++)
	{
		state3[i]->clean();
	}
	state3.clear();

	if (phg2Ok == DaXuLy) phg2Ok = DaMua;
	if (phg3Ok == DaXuLy) phg3Ok = DaMua;
	if (phg4Ok == DaXuLy) phg4Ok = DaMua;
	if (kl2Ok == DaXuLy) kl2Ok = DaMua;
	if (gun2Ok == DaXuLy) gun2Ok = DaMua;
	std::ofstream phg2("font/phg.txt");
	phg2 << phg2Ok <<' '<< phg3Ok<<' ' << phg4Ok;
	phg2.close();

	std::ofstream kl0("font/kl.txt");
	kl0 << kl2Ok;
	kl0.close();

	std::ofstream gun("font/gun.txt");
	gun << gun2Ok;
	gun.close();
	return true;
}

void ChangeCharacterState::phg1()
{
	pathPhgID = "image/PhiHanhGia1.png";
	pathAvaID = "image/avaPHG1.png";
	pathSpaceID = "image/PhiHanhGia1.png";
	phgWidth = 22;
	phgHeight = 32;
	menuw = 22;
	menuh = 32;
	phgFrames = 4;
	speed = 5;
	here->updateChuot(80,230);
}

void ChangeCharacterState::phg2()
{
	if (TTF::coin >= 100 && phg2Ok == ChuaMua)
	{
		TTF::coin -= 100;
		phg2Ok = DaMua;
	}
	if (phg2Ok == DaXuLy)
	{
		pathPhgID = "image/PhiHanhGia22.png";
		pathAvaID = "image/avaPHG2.png";
		pathSpaceID = "image/PhiHanhGia2.png";
		phgWidth = 48;
		phgHeight = 40;
		menuw = 22;
		menuh = 39;
		phgFrames = 3;
		speed = 6;
		here->updateChuot(290, 230);
	}
}

void ChangeCharacterState::phg3()
{
	if (TTF::coin >= 200 && phg3Ok == ChuaMua)
	{
		TTF::coin -= 200;
		phg3Ok = DaMua;
	}
	if(phg3Ok == DaXuLy)
	{
		pathPhgID = "image/PhiHanhGia33.png";
		pathAvaID = "image/avaPHG3.png";
		pathSpaceID = "image/PhiHanhGia3.png";
		phgWidth = 55;
		phgHeight = 47;
		menuw = 22;
		menuh = 39;
		phgFrames = 3;
		speed = 6;
		here->updateChuot(490, 230);
	}
}

void ChangeCharacterState::phg4()
{
	if (TTF::coin >= 300 && phg4Ok == ChuaMua)
	{
		TTF::coin -= 300;
		phg4Ok = DaMua;
	}
	if(phg4Ok == DaXuLy)
	{
		pathPhgID = "image/BeHongNhun.png";
		pathAvaID = "image/avaPHG4.png";
		pathSpaceID = "image/PhiHanhGia4.png";
		phgWidth = 24;
		phgHeight = 14;
		menuw = 32;
		menuh = 32;
		phgFrames = 5;
		speed = 6;
		here->updateChuot(680, 230);
	}
}

void ChangeCharacterState::KLCam()
{
	pathID = "image/KhungLongFrames.png";
	width = 25;
	height = 25;
	frames = 9;
	here->updateChuot(80, 230);
}

void ChangeCharacterState::KLXanh()
{
	if (TTF::coin >= 250 && kl2Ok == ChuaMua)
	{
		TTF::coin -= 250;
		kl2Ok = DaMua;
	}

	if(kl2Ok == DaXuLy)
	{
		pathID = "image/KhungLongXanh.png";
		width = 31;
		height = 22;
		frames = 3;
		here->updateChuot(290, 230);
	}
}

void ChangeCharacterState::gun01()
{
	pathGunID = "image/aka.png";
	widthG = 65;
	heightG = 16;
	framesG = 1;
	loaiDan = 0;
	here->updateChuot(80, 230);
}

void ChangeCharacterState::gun02()
{
	if (TTF::coin >= 400 && gun2Ok == ChuaMua)
	{
		TTF::coin -= 400;
		gun2Ok = DaMua;
		loaiDan = 1;
	}

	if (gun2Ok == DaXuLy)
	{
		pathGunID = "image/akaPink.png";
		widthG = 65;
		heightG = 16;
		framesG = 1;

		loaiDan = 1;
		here->updateChuot(290, 230);
	}
}

void ChangeCharacterState::nv()
{
	state = 1;
	if(pathPhgID == "image/PhiHanhGia1.png"){ here->updateChuot(80, 230); }
	else if (pathPhgID == "image/PhiHanhGia22.png"){ here->updateChuot(290, 230); }
	else if (pathPhgID == "image/PhiHanhGia33.png"){ here->updateChuot(490, 230); }
	else if (pathPhgID == "image/BeHongNhun.png"){ here->updateChuot(680, 230); }
}

void ChangeCharacterState::kl()
{
	state = 2;
	if (pathID == "image/KhungLongFrames.png") { here->updateChuot(80, 230); }
	else if (pathID == "image/KhungLongXanh.png") { here->updateChuot(290, 230); }
}

void ChangeCharacterState::dan()
{
	state = 3;
	if (pathGunID == "image/aka.png") { here->updateChuot(80, 230); }
	else if (pathGunID == "image/akaPink.png") { here->updateChuot(290, 230); }
}

void ChangeCharacterState::Back()
{
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}