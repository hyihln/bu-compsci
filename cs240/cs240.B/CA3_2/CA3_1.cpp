
#include <iostream>
#include <stdlib.h>
#include "FBLUser.h"
#include "FBLUserLL.h"

using namespace std;

int main(int argc, char* argv[]){

	FBLUserLL FBLUserLL; //Parenthesis not required to instantiate a class object when no parameters

	string command;

	while(true){

		cout << "Enter a command. CREATE, LOGIN, or QUIT.\n";

		cin >> command;
	
		if(command == "CREATE"){
			string u, p, f, l;
			cin >> u >> p >> f >> l;
			FBLUserLL.create(u, p, f, l);
			

		}
		else if (command == "LOGIN"){
			string id;
			string pw;
			cin >> id;
			cin >> pw;			
			FBLUserLL.login(id, pw);

		}
		else if (command == "QUIT"){
			break;
		}
		else{
			cout << "Command not recognized. ";
		}

	}
}
