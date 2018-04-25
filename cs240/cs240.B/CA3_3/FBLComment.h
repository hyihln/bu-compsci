

#ifndef FBLCOMMENT_H
#define FBLCOMMENT_H

using namespace std;

class FBLComment {
	public:
		FBLComment(string text, string firstName, string lastName);

	private:
		string comment;
		string firstName;
		string lastName;
		FBLComment* next;
		FBLComment* prev;

		friend class FBLCommentLL;
		friend class FBLUser;
};

#endif
