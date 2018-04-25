

#ifndef FBLPOSTLL_H
#define FBLPOSTLL_H
#include "FBLPost.h"

using namespace std;

class FBLPostLL{
	public:
		FBLPostLL();
		
	private:
		FBLPost* firstpost;
		FBLPost* lastpost;
		
		friend class FBLUser;
		
};

#endif
