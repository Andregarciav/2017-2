all: tp0

tp0: main.o analises.o
	gcc -o tp0 main.o analises.o -Wall -Wextra

main.o: main.c
	gcc -c main.c -Wall -Wextra

analises.o: analises.c
	gcc -c analises.c -Wall -Wextra

clean:
	rm tp0 *.o
