#CTRL + H : Replace all

all:	cache-sim

cache-sim:	proj2.o
	g++  proj2.o -o cache-sim

proj2.o:	proj2.cpp
	g++ -c proj2.cpp

clean:
	rm -f *.o cache-sim
