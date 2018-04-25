
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
		
		fpost->firstpost = new FBLPost(text);
		fpost->lastpost = fpost->firstpost;
	}
	else{
		fpost->lastpost->next = new FBLPost(text);
		fpost->lastpost = fpost->lastpost->next;
	}
}

void FBLUser::read(){
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
}
