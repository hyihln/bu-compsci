
#include <iostream>
#include <stdlib.h>
#include "Donor.h"
#include "DonorDatabase.h"


using namespace std;

int main(int argc, char *argv[]){ 

/*command line arguments
	argc = argument count

	argv[0] = first string: program name

*/

	DonorDatabase DonorDatabase(*argv[1]);
	

	string command;

	while(true){

		cout << "Enter a command. Login, Add, Save, Load, Report, Quit.\n" <<endl;

		cin >> command;

		if(command == "Login"){
			DonorDatabase.Login();

		}
		else if (command == "Add"){
			DonorDatabase.Add();

		}
		else if (command == "Save"){
			DonorDatabase.Save();

		}
		else if (command == "Load"){
			DonorDatabase.Load();

		}
		else if (command == "Report"){
			DonorDatabase.Report();

		}
		else if (command == "Quit"){
			break;

		}
		else {
			cout << "Command not recognized. Try again.\n" << endl;
		}

	}



}


