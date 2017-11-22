all: dicionario
dicionario: main.o dicionario.o tree.o
	gcc -o dicionario main.o dicionario.o tree.o -Wall
main.o: main.c
	gcc -c main.c -Wall
dicionario.o: dicionario.c
	gcc -c dicionario.c -Wall
tree.o: tree.c
	gcc -c tree.c -Wall
clean:
	rm -f *.o
	rm -f ~.o
	rm -f dicionario
