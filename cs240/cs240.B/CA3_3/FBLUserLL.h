
#ifndef FBLUSERLL_H
#define FBLUSERLL_H
#include "FBLUser.h"

using namespace std;

class FBLUserLL{
	public:
		FBLUserLL();
		void create(string userid, string password, string first, string last);
		void login(string userid, string password);
		void users();
		void sortUsers();
		
	private:
		FBLUser* pointertofirst;
		FBLUser* lastuser;
};

#endif
