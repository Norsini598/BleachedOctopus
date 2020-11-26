#IDIR_H = include/headers #directory with header files
CC = g++
Exec = Test.exe

Include = include
CFLAGS = -Wall -std=c++11 #-I$(IDIR_H)

all: $(Exec)
Test.exe: Instantiation.o
		$(CC) -o $(Exec) Instantiation.o #$(Libs)
Instantiation.o: Instantiation.cpp
		$(CC) -c $(CFLAGS) Instantiation.cpp -g
clean:
		rm -f $(Exec) Instantiation.o
rebuild:
		make clean
		make
