
#ifndef DISHOBJ_H
#define DISHOBJ_H
#include <string>

using namespace std;

class DISHobj {
	public:
		DISHobj(string s);
	private:
		string s;
		int alphabetheap;
		int lengthheap;
		int stringlength;
		int asciivalue;
};

#endif
