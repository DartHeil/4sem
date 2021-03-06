#include <essence.h>
#include <map.h>
#include <Graphics.hpp>
#include <view.h>
#include <exitwindow.h>
#include <iostream>
#include <mapPlan.h>
#include <cstdio>

using namespace sf;

int main()
{
	/*Texture texture;
	Sprite sprite;
	texture.loadFromFile("images/image.jpg");
	sprite.setTexture(texture);
	sprite.setPosition(100, 200);*/


	RenderWindow window(VideoMode(800, 600), "My_First_Game"/*, Style::Fullscreen*/);

	view.reset(FloatRect(0, 0, 640, 480));

	map mapa("map.png", mapPlan);

	essence test(50, 25, 51, 21, 132, 138, "sprite.png");

	Clock clock;

	while (window.isOpen())
	{
		//std::cout << "OK, its start" << "\n";

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time/800;
		Event event;
		while (window.pollEvent(event))
		{
			if(event.type == Event::Closed)
				window.close();

			if(Keyboard::isKeyPressed(Keyboard::Escape)) 
			{ 					
				int exitCode = exitWindow();	
				std::cout << exitCode << "\n";	
				
				if(exitCode == 0) { window.close(); } 
				if(exitCode == 2) { window.close(); std::cout <<"EXIT ERROR"; } 
				if(exitCode == 1) { std::cout <<"Im fine"; }
			}
		}
				
		window.clear(Color::Red);
		//std::cout << "Starting to print" << "\n";
		
		mapa.print(window); 
		//std::cout << "Map printed" << "\n";

		test.draw(window);
		//std::cout << "Hero printed" << "\n";
		//std::cout << test.get_x() << " " << test.get_y() << "\n";
		window.display();

		test.move(time);
		//std::cout << "Hero moved" << "\n";

		view = get_xy_for_view(test.get_x(), test.get_y());
		//std::cout << "View got xy" << "\n";

		window.setView(view);
		//std::cout << "View installed" << "\n"; 

		test.interactionWithMap(mapa);
		//std::cout << "OK, it is interaction" << "\n";


	}

	return 0;
}
