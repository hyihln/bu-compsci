

all:	Donate

Donate:	CA1.o LinHuiyiDonorFunctions.o
	g++  LinHuiyiDonorFunctions.o CA1.o -o Donate

CA1.o:	CA1.cpp
	g++ -c CA1.cpp

LinHuiyiDonorFunctions.o:	LinHuiyiDonorFunctions.cpp 
	g++ -c LinHuiyiDonorFunctions.cpp

clean:
	rm -f *.o Donate Donate.exe
