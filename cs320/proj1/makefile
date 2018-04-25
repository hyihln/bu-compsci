#CTRL + H : Replace all

all:	predictors

predictors:	proj1.o
	g++  proj1.o -o predictors

proj1.o:	proj1.cpp
	g++ -c proj1.cpp

clean:
	rm -f *.o predictors *.txt
