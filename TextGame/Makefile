C=gcc
CFLAGS=-I.
DEPS = gameutils.h scenes.h

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

game: game.o gameutils.o scenes.o 
		gcc -o game game.o gameutils.o scenes.o -I.

clean:
		rm *.o 
