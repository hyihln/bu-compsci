
#ifndef FBLUSER_H
#define FBLUSER_H
#include "FBLPost.h"
#include "FBLPostLL.h"

using namespace std;

class FBLUser {
	public:
		FBLUser();
		void logout();
		void post(string text);
		void read();
		
	private:
		string userid;
		string password;
		string firstname;
		string lastname;

		FBLUser* next;
		FBLPostLL* fpost;

		friend class FBLUserLL;
	
};

#endif
