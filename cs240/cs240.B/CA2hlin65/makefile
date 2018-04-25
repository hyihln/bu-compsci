
#CTRL + H : Replace all

all:	Donate

Donate:	CA2.o Donor.o DonorDatabase.o
	g++  Donor.o CA2.o DonorDatabase.o -o Donate

CA2.o:	CA2.cpp
	g++ -c CA2.cpp

Donor.o:	Donor.cpp 
	g++ -c Donor.cpp

DonorDatabase.o:	DonorDatabase.cpp
	g++ -c DonorDatabase.cpp

clean:
	rm -f *.o Donate
