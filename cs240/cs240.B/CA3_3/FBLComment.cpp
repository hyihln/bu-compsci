

#include <iostream>
#include <stdlib.h>
#include "FBLUser.h"
#include "FBLPostLL.h"
#include "FBLPost.h"
#include "FBLCommentLL.h"
#include "FBLComment.h"

using namespace std;

FBLComment::FBLComment(string c, string f, string l){
	comment = c;
	firstName = f;
	lastName = l;
	prev = NULL;
	next = NULL;
}
