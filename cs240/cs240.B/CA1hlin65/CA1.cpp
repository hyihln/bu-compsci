
#include <iostream>
#include <stdlib.h>
#include "Donor.h"


using namespace std;

int main(int argc, char *argv[]){

	Donor Donor;
	string command;


	while(true){

		cout << "Enter a command. Choose from ['Add' 'Manage' 'View' 'Donate' 'Total' 'Quit']: \n";

		cin >> command;

		if(command == "Add"){
			Donor.Add();

		}
		else if (command == "Manage"){
			Donor.Manage();

		}
		else if (command == "View"){
			Donor.View();

		}
		else if (command == "Donate"){
			Donor.Donate();

		}
		else if (command == "Total"){
			Donor.Total();

		}
		else if (command == "Quit"){
			break;

		}
		else {
			cout << "Command not recognized. Try again.\n";
		}

	}



}
