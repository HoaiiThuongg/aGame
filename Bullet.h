#pragma once
#include "SDLGameObject.h"
#include "Sound.h"
#include "DrawPic.h"
#include "Spaceship.h"

class Bullet : public SDLGameObject
{
public:
	Bullet(const LoaderParams* pParams, int scale);
	Bullet(const LoaderParams* pParams, int scale,int speeds);
	Bullet(const LoaderParams* pParams, int scale, int speeds,int fr);
	virtual void draw();
	virtual void update();
	virtual void clean();

	void danDoc();

	int getX() { return m_position.getX(); }
	int getY() { return m_position.getY(); }
	int speed;
	bool validDan = true;

	static int banTruot;
private:
	int frames;
	Sound BulletSound;
};
#pragma once
