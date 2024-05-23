#include "Snake.h"
#include "GameOverState.h"

bool checkVa(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	if (x1 + w1 > x2 &&
		x2 + w2 > x1 &&
		y1 + h1 > y2 &&
		y2 + h2 > y1)
		return true;
	return false;
}

Snake::Snake(const LoaderParams* pParams, int scale, int frames, int speeds) :
SDLGameObject(pParams, scale), frame(frames), speed(speeds)
{}

void Snake::update()
{
	handleInput();
	if (buoc.size() == 0)
	{
		buoc.push_back("none");
	}
	if (buoc.size() != 0)
	{
		if (buoc[0] == "down")
		{
			m_velocity.setX(0);
			m_velocity.setY(speed);
		}
		if (buoc[0] == "up")
		{
			m_velocity.setX(0);
			m_velocity.setY(-speed);
		}

		if (buoc[0] == "right")
		{
			m_velocity.setY(0);
			m_velocity.setX(speed);
		}
		if (buoc[0] == "left")
		{
			m_velocity.setY(0);
			m_velocity.setX(-speed);
		}
	}

	if ((m_position.getX() > 640) ||
	 (m_position.getX() <0)||
	 (m_position.getY() > 640)
		|| (m_position.getY() < 0))
	{
		GameOverState::PathNguoiRaDi = "image/walking.png";
		GameOverState::width = 20;
		GameOverState::height = 62;
		GameOverState::frame = 4;
		TheGame::Instance()->getStateMachine()->changeState(new GameOverState);
	}

	SDLGameObject::update();
	currentFrame = int(((SDL_GetTicks() / (200)) %frame));
}

void Snake::updateCon(Snake* player)
{

	if (player->buoc[0] != "none")
		buoc.push_back(player->buoc[0]);

	if (buoc.size() > 10)
	{
		if (buoc[0] == "down")
		{
			m_velocity.setX(0);
			m_velocity.setY(speed);
		}
		if (buoc[0] == "up")
		{
			m_velocity.setX(0);
			m_velocity.setY(-speed);
		}

		if (buoc[0] == "right")
		{
			m_velocity.setY(0);
			m_velocity.setX(speed);
		}
		if (buoc[0] == "left")
		{
			m_velocity.setY(0);
			m_velocity.setX(-speed);
		}

		buoc.erase(buoc.begin());
	}

	SDLGameObject::update();
	currentFrame = int(((SDL_GetTicks() / (200)) % frame));
}

void Snake::updateFood()
{
	if (!appear)
	{
		m_position.setX(SDL_GetTicks() % 5 * 100 + 20); 
		m_position.setY(SDL_GetTicks() % 5 * 100 + 20);
		appear = true;
	}
	SDLGameObject::update();
	currentFrame = int(((SDL_GetTicks() / (200)) % frame));
}

void Snake::updateBomb(int x, int y)
{
	if (!appear)
	{ 
		m_position.setX((SDL_GetTicks() % (600 / 32)) * 32 + 5);
		m_position.setY((SDL_GetTicks() % (600 / 32)) * 32 + 5);

		std::cout << m_position.getX() << ' ';
		if(x + 20 > m_position.getX() &&
			m_position.getX() + width * scale > x &&
			y + 62 > m_position.getY() &&
			m_position.getY() + height * scale > y)
		{
			if (m_position.getX() + 100 <= 600) {
				m_position.setX(m_position.getX() + 100);
			}
			else
			{
				m_position.setX(m_position.getX() - 100);
			}

			if (m_position.getY() + 100 <= 600) {
				m_position.setY(m_position.getY() + 100);
			}
			else
			{
				m_position.setY(m_position.getY() - 100);
			}
		}
		appear = true;
	}
	SDLGameObject::update();
	currentFrame = int(((SDL_GetTicks() / (200)) % frame));
}

void Snake::updateExplode(int x,int y)
{
	std::cout << currentFrame << ' ';
	if (appear)
	{
		m_position.setX(x);
		m_position.setY(y);
	}

	SDLGameObject::update();
	bool is(false);
	if (currentFrame == 0) is = true;
	currentFrame = (SDL_GetTicks() / 200) % frame;
	if (is && currentFrame == frame - 1) currentFrame = 0;
}

void Snake::draw()
{
	SDLGameObject::draw();
}

void Snake::clean()
{
	SDLGameObject::clean();
}

void Snake::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		buoc[0] = "right";
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		buoc[0] = "left";
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		buoc[0] = "up";
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		buoc[0] = "down";
	}
}