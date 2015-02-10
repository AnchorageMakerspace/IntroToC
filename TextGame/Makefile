C=gcc
CFLAGS=-I.
DEPS = gameutils.h scenes.h

all: game

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

game: game.o gameutils.o scenes.o 
		gcc -o game game.o gameutils.o scenes.o -I.

clean:
		rm -f *.o tests/*.o game.exe bin/*.exe

tests: bin/testGame.exe

bin/testGame.exe: tests/testGame.o gameutils.o scenes.o
		gcc -o testGame.exe tests/testGame.o gameutils.o scenes.o
		mv testGame.exe bin
