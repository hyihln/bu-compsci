
#ifndef DISH_H
#define DISH_H
#include <vector>
#include <string>
#include "DISHobj.h"

using namespace std;

class DISH {
	public:
		DISH();
		int insert(string s);
		int find(string s);
		bool capitalize(int k);
		bool allcaps(int k);
		bool truncate(int k, int i);
		string getshortest();
		string getfirst();

	private:
		vector<DISHobj> container;
};

#endif
