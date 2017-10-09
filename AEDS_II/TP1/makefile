all: tp1

tp1: main.o caixeiro.o
	gcc -o tp1 main.o caixeiro.o -Wall -Wextra -lm

main.o: main.c
	gcc -c main.c -Wall -Wextra

caixeiro.o: caixeiro.c
	gcc -c caixeiro.c -Wall -Wextra

clean:
	rm tp1 *.o
