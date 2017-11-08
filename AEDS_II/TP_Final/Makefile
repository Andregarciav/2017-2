all: dicionario
dicionario: main.o dicionario.o
	gcc -o dicionario main.o dicionario.o -Wall
main.o: main.c
	gcc -c main.c -Wall
dicionario.o: dicionario.c
	gcc -c dicionario.c -Wall
clean:
	rm -f *.o
	rm -f ~.o
	rm -f dicionario
