

#ifndef DONORDATABASE_H
#define DONORDATABASE_H

#include "Donor.h"

using namespace std;

class DonorDatabase {
	public:
		DonorDatabase(int c, char* f);
		DonorDatabase(int c);
		void Login();
		void Add();
		void Save();
		void Load();
		void Report();
		void Quit();
		
	private:
		Donor* donorArray;
		int capacity;
		int current;
		string filename;
};

#endif
