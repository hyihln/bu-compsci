#ifndef PROJ1_H
#define PROJ1_H

#include <string>

using namespace std;

class proj1 {

	private:
		int branches;
		int correct;

	public:
		string output;
		proj1();
		void pTaken(string filename);
                void pNT(string filename);
		void singlebit(string filename);
		void twobit(string filename);
		void gshare(string filename);
		void tournament(string filename);

};

#endif
