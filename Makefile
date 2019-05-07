test: main.o add.o
	gcc main.o add.o -o test

main.o: main.c
	gcc -c main.c -o main.o

add.o: add.S
	gcc -c add.S -o add.o

clean:
	rm -rf *.o test


