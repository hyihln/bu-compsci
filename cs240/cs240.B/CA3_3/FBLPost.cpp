

#include <iostream>
#include <stdlib.h>
#include "FBLPost.h"

using namespace std;

FBLPost::FBLPost(string t){

	next = NULL;
	message = t;

	likes = 0;
	postNumber = 0;
	idTrace = NULL;

	comments = new FBLCommentLL();

}
