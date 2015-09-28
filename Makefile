pigsgame: main.o dice.o player.o
	g++ -Wall -pedantic -g -o pigsgame main.o dice.o player.o

main.o: main.cpp dice.h player.h
	g++ -Wall -pedantic -g -c main.cpp

dice.o: dice.h dice.cpp
	g++ -Wall -pedantic -g -c dice.cpp

player.o: player.h player.cpp
	g++ -Wall -pedantic -g -c player.cpp

clean:
	rm -f *.o pigsgame pigsgame.exe
