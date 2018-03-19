#include <map.h>
#include <Graphics.hpp>

using namespace sf;

map::map(String F)
{
	/*String TileMap1[HEIGHT_MAP] = 
	{
	"0000000000000000000000000000000000000000",
	"0                                      0",
	"0   s                                  0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0000000000000000000000000000000000000000",
	};

	TileMap = TileMap1;*/
	File = F;

	image.loadFromFile("images/" + File);//загружаем файл для карты
	texture.loadFromImage(image);//заряжаем текстуру картинкой
	look.setTexture(texture);//заливаем текстуру спрайтом
}

void map::print(RenderWindow& window) 
{
	for (int i = 0; i < HEIGHT_MAP; i++)
	for (int j = 0; j < WIDTH_MAP; j++)
	{
		if (TileMap[i][j] == ' ')  look.setTextureRect(IntRect(0, 0, 32, 32)); 
		if (TileMap[i][j] == 's')  look.setTextureRect(IntRect(32, 0, 32, 32));
		if ((TileMap[i][j] == '0')) look.setTextureRect(IntRect(64, 0, 32, 32));
 		
		look.setPosition(j * 32, i * 32);
			
		window.draw(look);
	}
}


