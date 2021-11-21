# Compiler
CC = g++

# Flags 
CC_FLAGS = -Wall -g -Iinclude -c


all: main

main: main.o review.o
		$(CC) -o bin/main obj/main.o obj/Review.o 

main.o: src/main.cpp
		$(CC) $(CC_FLAGS) src/main.cpp -o obj/main.o

review.o: src/Review.cpp include/Review.h
		$(CC) $(CC_FLAGS) src/Review.cpp -o obj/Review.o


execute: all
		./bin/main.exe