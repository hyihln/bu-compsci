
#ifndef REQUIREMENTS_H
#define REQUIREMENTS_H
#include <vector>
#include "courses.h"

using namespace std;

class requirements {
	public:
		requirements();
		void total(int t);
		void credit(char type, int num);
		void course(string name, char type, vector<string> prereq);
		void choose();
	private:
		int totalcredits;
		int typeCcredits;
		int typeHcredits;
		int typeFcredits;
		courses* list;
};

#endif
