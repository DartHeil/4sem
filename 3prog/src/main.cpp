#include <essence.h>
#include <map.h>
#include <Graphics.hpp>
#include <view.h>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(640, 480), "My_First_Game");

	view.reset(FloatRect(0, 0, 640, 480));

	map mapa("map.png");
	essence test(50, 25, 51, 21, 132, 138, "sprite.png");
	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time/800;
		Event event;
		while (window.pollEvent(event))
		{
			if(event.type == Event::Closed)
				window.close();
		}

		test.move(time);
		test.update(time);
		get_xy_for_view(test.get_x(), test.get_y());
		window.setView(view);

		window.clear(Color::Red);
		
		mapa.print(window);
		test.draw(window);

		window.display();
	}

	return 0;
}
