

#ifndef FBLCOMMENTLL_H
#define FBLCOMMENTLL_H
#include "FBLComment.h"

using namespace std;

class FBLCommentLL{
	public:
		FBLCommentLL();
		
	private:
	
		FBLComment* firstComment;
		FBLComment* lastComment;
		
		friend class FBLPost;
		friend class FBLUser;
};

#endif
