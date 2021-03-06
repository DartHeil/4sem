#include <player.h>
#include <Graphics.hpp>
#include <iostream>

#define LeftPressed (Keyboard::isKeyPressed(Keyboard::Left))
#define RightPressed (Keyboard::isKeyPressed(Keyboard::Right))
#define UpPressed (Keyboard::isKeyPressed(Keyboard::Up))
#define DownPressed (Keyboard::isKeyPressed(Keyboard::Down))

using namespace sf;

Player::Player(Image &bodyImage, Image &cannonImage, float X, float Y,int W,int H,String PlayerName, String CannonName) : Entity(bodyImage,X,Y,W,H,PlayerName), cannon(bodyImage,X,Y,0,0,CannonName)
{
	if (PlayerName == "Player1")
	{
	sprite.setTextureRect(IntRect(0,0,w,h));
	}

	isCannon = true;
	state = stay;
}

void Player::control()
{
	if(LeftPressed) //left
	{ 
		speed = 0.1;
		sprite.setRotation(90);		
		state = left; 
	}
	if(RightPressed) //right
	{
		speed = 0.1; 
		sprite.setRotation(-90);	
		state = right; 
	}
	if(UpPressed) //up
	{
		speed = 0.1; 
		sprite.setRotation(180);		
		state = up; 
	}
	if(DownPressed) //down
	{
		speed = 0.1; 
		sprite.setRotation(0);	
		state = down; 
	}
	if(LeftPressed && UpPressed) //left-up
	{
		speed = 0.1; 
		sprite.setRotation(135);		
		state = leftUp; 
	}
	if(RightPressed && UpPressed) //right-up
	{
		speed = 0.1; 
		sprite.setRotation(-135);	
		state = rightUp; 
	}
	if(LeftPressed && DownPressed) //left-down
	{
		speed = 0.1; 
		sprite.setRotation(45);		
		state = leftDown; 
	}
	if(RightPressed && DownPressed) //right-down
	{
		speed = 0.1; 
		sprite.setRotation(-45);	
		state = rightDown; 
	}
}

void Player::interactionWithMap(map& mapa)//ф-ция взаимодействия с картой
{
 
	for (int i = y / 32; i < (y + h) / 32; i++)
	for (int j = x / 32; j<(x + w) / 32; j++)
	{
		if (mapa.get_ij(i, j) == '0')
		{
		   switch (state)
		   {
		   case right:x = j * 32 - w; break;
		   case left:x = j * 32 + 32; break;
		   case up:y = i * 32 + 32; break;
		   case down:y = i * 32 - h; break;
		   case leftUp:dx = -speed / 1.4; dy = -speed / 1.4; break;
		   case leftDown:dx = -speed / 1.4; dy = speed / 1.4; break;
		   case rightUp:dx = speed / 1.4; dy = -speed / 1.4; break;
		   case rightDown:dx = speed / 1.4; dy = speed / 1.4; break;
		   case stay: break;		
		   }



			/*if (dy > 0)
			{
				if (dx > 0)
				{
					x = j * 32 - w / 1.4;
					y = i * 32 - h / 1.4;
				}
								
				if (dx < 0)
				{	y = i * 32 - h;
					x = j * 32 + 32;
				}

				
			}
			if (dy < 0)
			{
				y = i * 32 + 32;
			}
			if (dx > 0)
			{
				x = j * 32 - w;
			}
			if (dx < 0)
			{
				x = j * 32 + 32;
			}
			if ( (dy < 0) && (dx < 0) )
			{
				y = i * 32 + 32;
			}
			if ( (dy > 0) && (dx < 0) )
			{
				x = j * 32 - w;
			}
			if ( (dy < 0) && (dx > 0) )
			{
				x = j * 32 + 32;
			} */
		}
 
		if (mapa.get_ij(i, j) == 's') 
		{ 
			x = 300; y = 300;
			mapa.change_ij(i, j, ' ');
		}
	}
} 	

void Player::draw(RenderWindow& window)
{
	if(!isCannon)
		Entity::draw(window);
	else
	{
		window.draw(sprite);
		cannon.draw(window);
	}
}

void Player::update(float time, map& mapa, RenderWindow& window)
	   {
		   control();//функция управления персонажем
		   switch (state)//тут делаются различные действия в зависимости от состояния
		   {
		   case right:dx = speed; dy = 0; break;
		   case left:dx = -speed; dy = 0; break;
		   case up:dx = 0; dy = -speed; break;
		   case down:dx = 0; dy = speed; break;
		   case leftUp:dx = -speed / 1.4; dy = -speed / 1.4; break;
		   case leftDown:dx = -speed / 1.4; dy = speed / 1.4; break;
		   case rightUp:dx = speed / 1.4; dy = -speed / 1.4; break;
		   case rightDown:dx = speed / 1.4; dy = speed / 1.4; break;
		   case stay: break;		
		   }

		   x += dx * time;
		   y += dy * time;

		   interactionWithMap(mapa);

		   sprite.setPosition(x + w / 2, y + h / 2); //задаем позицию спрайта в место его центра
		   cannon.update(x + w / 2, y + h / 2, life, window);

		   if (health <= 0){ life = false; }

		   if (!isMove){ speed = 0; }

		 //  if (life) { view = get_xy_for_view(); window.setView(view); }
	   } 














