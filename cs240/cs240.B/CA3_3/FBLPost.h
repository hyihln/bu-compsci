

#ifndef FBLPOST_H
#define FBLPOST_H
#include "FBLCommentLL.h"

using namespace std;

//forward declaration, else #include "FBLUser.h" will cause a circular dependency
class FBLUser;

class FBLPost {
	public:
		FBLPost(string text);

	private:
		string message;
		FBLPost* next;

		int likes;
		int postNumber;
		FBLUser* idTrace;

		FBLCommentLL* comments;

		friend class FBLPostLL;
		friend class FBLUser;
};

#endif
