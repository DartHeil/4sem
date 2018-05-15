CC=g++

CFLAGS=-c -Wall

all: hello

hello: main.o player.o map.o Entity.o cannon.o
	$(CC)  main.o player.o map.o Entity.o cannon.o -o game -L/home/dartheil/Desktop/2kurs/Миряха/SFML-2.3.2/lib -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -I/home/dartheil/Desktop/2kurs/Миряха/SFML-2.3.2/include/SFML -I/home/dartheil/Desktop/2kurs/Миряха/HW/proj/src

Entity.o: Entity.cpp
	$(CC) $(CFLAGS) Entity.cpp -I/home/dartheil/Desktop/2kurs/Миряха/SFML-2.3.2/include/SFML -I/home/dartheil/Desktop/2kurs/Миряха/HW/proj/src

player.o: player.cpp
	$(CC) $(CFLAGS) player.cpp -I/home/dartheil/Desktop/2kurs/Миряха/SFML-2.3.2/include/SFML -I/home/dartheil/Desktop/2kurs/Миряха/HW/proj/src

cannon.o: cannon.cpp
	$(CC) $(CFLAGS) cannon.cpp -I/home/dartheil/Desktop/2kurs/Миряха/SFML-2.3.2/include/SFML -I/home/dartheil/Desktop/2kurs/Миряха/HW/proj/src

map.o: map.cpp
	$(CC) $(CFLAGS) map.cpp -I/home/dartheil/Desktop/2kurs/Миряха/SFML-2.3.2/include/SFML -I/home/dartheil/Desktop/2kurs/Миряха/HW/proj/src
	

clean:
	rm -rf *.o hello
