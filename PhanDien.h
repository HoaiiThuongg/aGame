#pragma once
#include "SDLGameObject.h"
#include "Sound.h"

class PhanDien :public SDLGameObject
{
public:
	PhanDien(const LoaderParams* pParams, int scale,int frames,int speeds);

	virtual void draw();
	virtual void update();
	virtual void updateCatus();
	void updateSpecial(int y);
	void updateBigOcState();
	void updateBigOc();
	void BigDie()
	{
		m_position.setX(900);
		m_position.setY(250);
		if (speed < 0)
		{
			speed = -speed;
		}
		if (updateSpeedBig < 0)
		{
			updateSpeedBig = -updateSpeedBig;
		}
	}

	virtual void clean();

	void dead1();
	void diRa();

	bool appear = true;
	bool switchh = false;

	void changeRow0() { currentRow = 0; }
	void changeRow1() { currentRow = 1; }
	void changeRow2() { currentRow = 2; }

	static int updateSpeedBig;
	static int updateSpeed;

private:
	Sound PDSound;
	int swX = -1;
	int swY = -1;
	int frames;
	int speed;
	int yDan;
};