

#ifndef FBLPOST_H
#define FBLPOST_H

using namespace std;

class FBLPost {
	public:
		FBLPost(string text);

	private:
		string message;
		FBLPost* next;

		friend class FBLPostLL;
		friend class FBLUser;
};

#endif
