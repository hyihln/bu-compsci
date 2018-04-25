
#include <iostream>
#include <stdlib.h>
#include "FBLUserLL.h"

using namespace std;

FBLUserLL::FBLUserLL(){
	pointertofirst = NULL;
	lastuser = NULL;
}

void FBLUserLL::create(string userid, string password, string firstname, string lastname){
	if(pointertofirst == NULL){
		pointertofirst = new FBLUser();
		pointertofirst->userid = userid;
		pointertofirst->password = password;
		pointertofirst->firstname = firstname;
		pointertofirst->lastname = lastname;
		pointertofirst->next = NULL;

		lastuser = pointertofirst;

	}
	else{
		bool used = false;
		FBLUser* traverse = pointertofirst;
		while(traverse->next != NULL){
			if(traverse->userid == userid){
				used = true;
				break;
			}
	
		traverse = traverse->next;
		}
		//the while loop does not check the last user.
		if(lastuser->userid == userid){
			used = true;
		}

		if(used == false){
			lastuser->next = new FBLUser();

			lastuser->next->userid = userid;
			lastuser->next->password = password;
			lastuser->next->firstname = firstname;
			lastuser->next->lastname = lastname;
			lastuser->next->next = NULL;

			lastuser = lastuser->next;
		}

		else{
			cout << "UserID in use. ";
		}
	}
}

void FBLUserLL::login(string userid, string password){

/*
if ./FBL and then straight to LOGIN without first CREATE
get segmentation fault
implement error checking
*/

//interesting interaction if use top level commands while logged into a user ie in second level


	FBLUser* traverse = pointertofirst;

	string command;
	bool loggedin = false;
	
	while(traverse->next != NULL){
		if((traverse->userid) == userid && (traverse->password) == password){
			loggedin = true;
		
			while(loggedin == true){
				cout << "Enter a command. LOGOUT, POST, READ, FRIEND, MYFRIENDS, MYFEED, MYWALL.\n";
				cin >> command;
				if(command == "LOGOUT"){
					//traverse->logout(addfriendinvoked);
					break;
				}
				else if(command == "POST"){
					string t;
	
					//cin >> ws;
					getline(cin,t);
					traverse->post(t);
				}
				else if(command == "READ"){
					traverse->read();
				}
				else if(command == "FRIEND"){
					string friendid;
					cin >> friendid;
					FBLUser* f = pointertofirst;
					bool friendFunctionInvoked = false;
					while(f->next != NULL){
						
						if(f->userid == friendid){
							
							traverse->friendfunction(f);
							friendFunctionInvoked = true;
							
						}
						f = f->next;
					}
					if(friendFunctionInvoked == false && lastuser->userid == friendid){
						traverse->friendfunction(lastuser);
						friendFunctionInvoked = true;
					}

					if(friendFunctionInvoked == false){
						cout << "That user does not exist.";
					
					}
					
				}
				else if(command == "MYFRIENDS"){
					traverse->myfriends();
				}
				else if(command == "MYFEED"){
					traverse->myfeed();
				}
				else if(command == "MYWALL"){
					traverse->mywall();
				}
				else{
					cout << "Invalid command. ";
				}
			}
		
		}

	traverse = traverse->next;
	}

	if(lastuser->userid == userid && lastuser->password == password){
		loggedin = true;

		while(loggedin == true){
			cout << "Enter a command. LOGOUT, POST, READ, FRIEND, MYFRIENDS, MYFEED, MYWALL.\n";
			cin >> command;
			if(command == "LOGOUT"){
				//traverse->logout();
				break;
			}
			else if(command == "POST"){
				string t;
				//cin >> t;
				getline(cin,t);
				traverse->post(t);
			}
			else if(command == "READ"){
				traverse->read();
			}
			else if(command == "FRIEND"){
				string friendid;
				cin >> friendid;
				FBLUser* f = pointertofirst;
				while(f->next != NULL){
					if(f->userid == friendid){
						traverse->friendfunction(f);
						break;
					}
					f = f->next;
				}
				

				if(lastuser->userid == friendid){
					traverse->friendfunction(lastuser);
				}
				else {
				cout << "That user does not exist.";
				
				}
			}
			else if(command == "MYFRIENDS"){
				traverse->myfriends();
			}
			else if(command == "MYFEED"){
				traverse->myfeed();
			}
			else if(command == "MYWALL"){
				traverse->mywall();
			}
			else{
				cout << "Invalid command. ";
			}
		}
	}

	if(loggedin == false) {
		cout << "No such user. Or incorrect password. ";
	}
}

