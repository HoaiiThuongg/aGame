#pragma once

class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height, std::string
		textureID) : m_x(x), m_y(y), m_width(width), m_height(height),
		m_textureID(textureID),m_scale(1)
	{}
	LoaderParams(int x, int y, int width, int height, int scale, std::string
		textureID) : m_x(x), m_y(y), m_width(width), m_height(height), m_scale(scale),
		m_textureID(textureID)
	{}

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width*m_scale; }
	int getHeight() const { return m_height*m_scale; }
	std::string getTextureID() const { return m_textureID; }
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_scale;
	std::string m_textureID;
};