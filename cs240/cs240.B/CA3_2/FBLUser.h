
#ifndef FBLUSER_H
#define FBLUSER_H
#include <vector>
#include "FBLPost.h"
#include "FBLPostLL.h"

using namespace std;

class FBLUser {
	public:
		FBLUser();
		void logout();
		void post(string text);
		void read();
		void myfeed();
		void mywall();
		void friendfunction(FBLUser* f);
		void myfriends();
		
	private:
		string userid;
		string password;
		string firstname;
		string lastname;

		FBLUser* next;
		FBLPostLL* fpost;

		vector<FBLUser*> friendlist;
		vector<FBLPost> feed;

		friend class FBLUserLL;
	
};

#endif
