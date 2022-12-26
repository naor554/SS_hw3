# Makefile for isort.c and txtfind.c - Assignment 3

all: isort txtfind

isort: isort.c
	gcc -Wall isort.c -o isort

txtfind: txtfind.c
	gcc -Wall txtfind.c -o txtfind

clean:
	rm -f *.o isort txtfind

