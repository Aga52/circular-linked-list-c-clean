
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: programa.exe

programa.exe: main.c list.c list.h
	$(CC) $(CFLAGS) main.c list.c -o programa.exe

testai.exe: tests.c list.c list.h
	$(CC) $(CFLAGS) tests.c list.c -o testai.exe

.PHONY: all test run clean

test: testai.exe
	.\testai.exe

run: programa.exe
	.\programa.exe

clean:
	-del /Q programa.exe testai.exe 2>NUL
