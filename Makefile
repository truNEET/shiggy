CC=gcc
CFLAGS=-std=c99

all:
	$(CC) -o shig shig.c $(CFLAGS)
