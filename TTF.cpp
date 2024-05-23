#include "TTF.h"
#include <fstream>

int TTF::food;
int TTF::coin;

TTF* TTF::s_pInstance = 0;


void TTF::readFile()
{
	std::ifstream coinFile("font/coin.txt");
	std::ifstream foodFile("font/food.txt");

	if (!coinFile.is_open() || !foodFile.is_open())
	{
		std::cout << "fail to open text file!" << std::endl;
		return;
	}

	int n;
	int m;

	coinFile >> n;
	coin = n;
	foodFile >> m;
	food = m;

	if (coin < 0) coin = 0;
	if (coin >= 9999) coin = 9999;

	if (food < 0) food = 0;
	if (food >= 9999) food = 9999;

	coinFile.close();
	foodFile.close();

}