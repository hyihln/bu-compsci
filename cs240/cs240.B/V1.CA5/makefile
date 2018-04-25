
all:	driver

driver:	CA5.o requirements.o
	g++ CA5.o requirements.o -o driver

CA5.o:	CA5.cpp
	g++ -c CA5.cpp

requirements.o:	requirements.cpp
	g++ -c requirements.cpp

clean:
	rm -f *.o driver
