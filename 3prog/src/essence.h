#pragma once
#include <Graphics.hpp>

using namespace sf;

class essence
{
protected:
	float x, m, y, xo, yo, w, h, dm, dy, speed;//координаты, размеры, ускорения, скорость
	int dir;//напрвление движения
	String File;//файл с расширением
	Image image;
	Texture texture;
	Sprite look;
public:
	essence();
	essence(float M, float Y, float Xo, float Yo, float W, float H, String F);

	void move(float time);
	void draw(RenderWindow& window);

	float get_x();
	float get_y();

	void update(float time);

};
