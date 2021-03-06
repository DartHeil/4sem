#pragma once
#include <Graphics.hpp>

using namespace sf;

class Entity 
{
protected:
	float dx, dy, x, y, speed,moveTimer;//добавили переменную таймер для будущих целей
	int w,h,health;
	bool life, isMove;
	Texture texture;
	Sprite sprite;
	String name;//враги могут быть разные, мы не будем делать другой класс для врага.всего лишь различим врагов по имени и дадим каждому свое действие в update в зависимости от имени


public:
	Entity(Image &image, float X, float Y,int W,int H,String Name);

	void draw(RenderWindow& window);

	float get_x();
	float get_y();

	void change_x(float xnew);
	void change_y(float ynew);

	float get_dx();
	float get_dy(); 

	float get_h();
	float get_w();

};
