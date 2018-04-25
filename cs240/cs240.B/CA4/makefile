
#CTRL + H : Replace all

all:	DISH

DISH:	CA4.o DISH.o DISHobj.o
	g++  CA4.o DISH.o DISHobj.o -o DISH

CA4.o:	CA4.cpp
	g++ -c CA4.cpp

DISH.o:	DISH.cpp
	g++ -c DISH.cpp

DISHobj.o:	DISHobj.cpp 
	g++ -c DISHobj.cpp

clean:
	rm -f *.o DISH
