
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

void FBLUser::logout(){
		
}

void FBLUser::post(string text){


	if(fpost->firstpost == NULL){
		//puts post in the default wall
		fpost->firstpost = new FBLPost(text);
		fpost->lastpost = fpost->firstpost;

		//make a copy for each friend's feed
		int i = 0;
		while(i < friendlist.size()){
			// without *() get error conversion from FBLPost* to FBLPost
			FBLPost copy = *(new FBLPost(text));
			friendlist[i]->feed.push_back(copy);
			i++;
		}
	}
	else{
		fpost->lastpost->next = new FBLPost(text);
		fpost->lastpost = fpost->lastpost->next;

		int j = 0;
		while(j < friendlist.size()){
			FBLPost copy = *(new FBLPost(text));
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
		while(traverse->next != NULL){
			cout << traverse->message << "\n";
	
			traverse = traverse->next;
		}

		cout << fpost->lastpost->message << "\n";
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

		//actually remove the post
		feed.erase(feed.begin());
	}
}
