#CTRL + H : Replace all

all:	predictors

predictors:	proj2.o
	g++  proj2.o -o predictors

proj2.o:	proj2.cpp
	g++ -c proj2.cpp

clean:
	rm -f *.o predictors *.txt
