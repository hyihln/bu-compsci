
#include <iostream>
#include <stdlib.h>
#include "FBLUser.h"
#include "FBLPostLL.h"
#include "FBLPost.h"

using namespace std;

FBLUser::FBLUser(){
	userid = "";
	password = "";
	firstname = "";
	lastname = "";

	//the next user
	next = NULL;

	//fpost refers to post linkedlist
	fpost = new FBLPostLL();

}

//TO DO later: will need to free up memory allocated by new.


void FBLUser::logout(){
		
}

void FBLUser::post(string text){


	if(fpost->firstpost == NULL){
		//puts post in the default wall
		fpost->firstpost = new FBLPost(text);
		//initial first post = #1
		(fpost->firstpost->postNumber) += 1;

		fpost->lastpost = fpost->firstpost;

		//make a copy for each friend's feed
		int i = 0;
		while(i < friendlist.size()){
			// without *() get error conversion from FBLPost* to FBLPost
			FBLPost copy = *(new FBLPost(text));
			(copy.postNumber)+=1;
			//pointer to original poster
			(copy.idTrace) = this;
			friendlist[i]->feed.push_back(copy);
			i++;
		}
	}
	else{
		fpost->lastpost->next = new FBLPost(text);
		//increment post number
		(fpost->lastpost->next->postNumber) = (fpost->lastpost->postNumber) + 1;
		fpost->lastpost = fpost->lastpost->next;

		int j = 0;
		while(j < friendlist.size()){
			FBLPost copy = *(new FBLPost(text));
			(copy.postNumber) = (fpost->lastpost->postNumber);
			(copy.idTrace) = this;
			friendlist[j]->feed.push_back(copy);
			j++;
		}
	}
	
}

void FBLUser::friendfunction(FBLUser* f){
	friendlist.push_back(f);
	f->friendlist.push_back(this);

}

void FBLUser::myfriends(){
	if(friendlist.empty()){
		cout << "Nothing to display.";
	}
	int i = 0;
	while(i < friendlist.size()){
		cout << (friendlist[i])->firstname << " " << (friendlist[i])->lastname << endl;
		i++;
	}
}

void FBLUser::myfeed(){
	if(feed.empty()){
		cout << "Nothing to display. ";
	}
	else{
		int i = 0;
		while(i < feed.size()){
			cout << feed[i].message << "\n" << endl;
			i++;
		}
	}
}

void FBLUser::mywall(){
	if(fpost->firstpost == NULL){
		cout << "Nothing to display. ";
	}
	else{

		FBLPost* traverse = fpost->firstpost;
		while(traverse != NULL){
			cout << traverse->message << " (+" << traverse->likes << ")" << endl;

			FBLComment* c = traverse->comments->firstComment;
			while(c != NULL){
				cout << "  " << c->comment << " (" << c->firstName << " " << c->lastName << ")" << endl;
				c = c->next;
			}

			traverse = traverse->next;
		}

		//cout << fpost->lastpost->message << " +" << traverse->likes << "\n";
	}	
}

void FBLUser::read(){
	//this deletes from default wall
	/*
	if(fpost->firstpost == NULL){
		cout << "Nothing to READ. ";
	}
	else{
		cout << fpost->firstpost->message << "\n";
		FBLPost* temp = fpost->firstpost;
		fpost->firstpost = fpost->firstpost->next;
		
		//if there's only one post total & once deleted point to NULL
		if (fpost->firstpost == NULL){
			fpost->lastpost = fpost->firstpost;
		}
		
		delete temp;		
	}
	*/

	//this deletes from user's feed, which is a copy of friend's post, and will not affect the original post in friend's wall
	if(feed.empty()){
		cout << "Nothing to READ. ";
	}
	else{
		//print the to be deleted message
		cout << feed[0].message << "\n";

		string command;
		bool withinRead = true;

		FBLUser* original = (feed[0].idTrace);
		//looking for the original post that the copy was made from
		FBLPost* originalPost = original->fpost->firstpost;
		while(feed[0].postNumber != originalPost->postNumber){
			originalPost = originalPost->next;		
		}

		while(withinRead == true){
			cout << "Enter a command. LIKE, COMMENT, READ_AZ, READ_ZA, DONE.\n";
			cin >> command;
			if(command == "LIKE"){
				originalPost->likes = (originalPost->likes)+1;
			}
			else if(command == "COMMENT"){
				string t;
				getline(cin, t);

				if(originalPost->comments->firstComment == NULL){
					originalPost->comments->firstComment = new FBLComment(t,this->firstname, this->lastname);
					originalPost->comments->lastComment = originalPost->comments->firstComment;
				}
				else{
					FBLComment* temp = originalPost->comments->lastComment;
					originalPost->comments->lastComment->next = new FBLComment(t, this->firstname, this->lastname);
					originalPost->comments->lastComment = originalPost->comments->lastComment->next;
					originalPost->comments->lastComment->prev = temp;
				}
			}
			else if(command == "READ_AZ"){
				//show comments in chronological order - ie oldest first
				FBLComment* c = originalPost->comments->firstComment;
				while(c != NULL){
					cout << c->comment << " (" << c->firstName << " " << c->lastName << ")" << endl;
					c = c->next;
				}
			}
			else if(command == "READ_ZA"){
				//show comments in reverse chronological - ie most recent first
				FBLComment* c = originalPost->comments->lastComment;
				while(c != NULL){
					cout << c->comment << " (" << c->firstName << " " << c->lastName << ")" << endl;
					c = c->prev;
				}
			}
			else if(command == "DONE"){
				break; //or reset flag
			}
			else{
				cout << "Invalid command. ";
			}
		}

		//actually remove the post
		feed.erase(feed.begin());
	}
}
