

#include <iostream>
#include <stdlib.h>
#include "DonorDatabase.h"
#include <fstream>

using namespace std;

DonorDatabase::DonorDatabase(int c){
	donorArray = new Donor[c];
	capacity = c;
	current = 0;
	filename = "";
}

DonorDatabase::DonorDatabase(int c, char* f){
	donorArray = new Donor[c];
	capacity = c;
	current = 0;
	filename = f;
}

void DonorDatabase::Login(){
	string tmpUserid;
	string tmpPassword;

	cout<< "Enter userid.\n" <<endl;
	cin >> tmpUserid;
	cout << "Password.\n"<<endl;
	cin >> tmpPassword;

	bool inArray = false;
	int index;
	int i;
	for(i=0;i<capacity;i++){
		if(tmpUserid == donorArray[i].userid && tmpPassword == donorArray[i].password){
			inArray = true;
			index = i;
		}		
	}

	string command;
	if(inArray == true){
		while(true){

			cout << "Enter command: Manage, Passwd, View, Donate, Total, Logout.\n" <<endl;

			cin >> command;

			if(command == "Manage"){
				donorArray[index].Manage();

			}
			else if (command == "Passwd"){
				donorArray[index].Passwd();

			}
			else if (command == "View"){
				donorArray[index].View();

			}
			else if (command == "Donate"){
				donorArray[index].Donate();

			}
			else if (command == "Total"){
				donorArray[index].Total();

			}
			else if (command == "Logout"){
				break;

			}
			else {
				cout << "Command not recognized. Try again.\n" << endl;
			}

		}	
	}
	else{
		Add();
	}

}

void DonorDatabase::Add(){

	if(current != capacity){

		cout << "Last name: ";
		cin >> donorArray[current].donorLastName;
/*
		string tempLastName;
		cin >> tempLastName;
		bool validLastName = false;
		int i;
		for(i = 0; i < tempLastName.size(); i++){
			if((tempLastName[i] >= 'A' && tempLastName[i] <= 'Z') ||(tempLastName[i] >= 'a' && tempLastName[i] <= 'z') ){
				validLastName = true;
				//overwritten bools. Address this error.
			}
		}
		if(validLastName == true){
			donorArray[current].donorLastName = tempLastName;
		}
		else{
			cout << "Letters only. Try again" << endl;
			cin >> donorArray[current].donorLastName;
			//Need rewrite to not progress in program until properly formatted.
		}
*/
		cout << "First name: ";
		cin >> donorArray[current].donorFirstName;
/*
		string tempFirstName;
		cin >> tempFirstName;
		bool validFirstName = false;
		int j;
		for(j = 0; j < tempFirstName.size(); j++){
			if((tempFirstName[i] >= 'A' && tempFirstName[i] <= 'Z') ||(tempFirstName[i] >= 'a' && tempFirstName[i] <= 'z') ){
				validFirstName = true;
			}
		}
		if(validFirstName == true){
			donorArray[current].donorFirstName = tempFirstName;
		}
		else{
			cout << "Letters only. Try again" << endl;
			cin >> donorArray[current].donorFirstName;
			//Need rewrite to not progress in program until properly formatted.
		}
*/

		cout << "userid: ";
		string tempID;
/*
		cin >> tempID;
		bool validChar = false;
		bool validLength = false;
		int k;
		for(k = 0; k < tempID.size(); k++){
			if((tempID[i] >= 'A' && tempID[i] <= 'Z') ||(tempID[i] >= 'a' && tempID[i] <= 'z') || tempID[i] == '0' || tempID[i] == '1' || tempID[i] == '2' || tempID[i] == '3' || tempID[i] == '4' || tempID[i] == '5' || tempID[i] == '6' || tempID[i] == '7' || tempID[i] == '8' || tempID[i] == '9'){
			validChar = true;
		}
		if(tempID.size() >= 5 && tempID.size() <= 10){
			validLength = true;
		}
		if(validChar && validLength){
			donorArray[current].userid = tempID;
		}
*/
		while(true){		
			cin >> tempID;
			int i;
			bool notInUse = false;
			for(i=0;i<capacity;i++){
				if(donorArray[i].userid != tempID){
					notInUse = true;
				}
			
			}
			if(notInUse == true){
				donorArray[current].userid = tempID;
				break;
			}
			else{
				cout << "Choose another id\n" <<endl;
			}
		}
		cout << "password:";
		cin >> donorArray[current].password;
		cout << "Age: ";
		cin >> donorArray[current].age;
		cout << "Street number: ";
		cin >> donorArray[current].streetNumber;
		cout << "Street name: ";
		cin >> donorArray[current].streetName;
		cout << "Town: ";
		cin >> donorArray[current].town;
		cout << "state";
		cin >> donorArray[current].state;
		cout << "Zip code: ";
		cin >> donorArray[current].zipCode;

		donorArray[current].amount = 0;
		current = current +1;
	}
	else{
		cout << "Donor capacity reached.\n";
	}
}

void DonorDatabase::Save(){
		string command = "";
		if(filename != ""){
			if(ofstream(filename)){
				cout << "File exists. Enter 'Overwrite' to overwrite or 'New' to use another file.\n";
				cin >> command;
				if(command == "Overwrite"){
					ofstream outfile;
					outfile.open(filename, ios::app);
					int i;
					for(i=0;i<capacity;i++){
						outfile.write((char*)&donorArray[i],sizeof(donorArray[i]));
					}
					outfile.close();				
				}
				else if(command == "New"){
					cout << "Enter new file name.\n";
					cin >> filename;
					ofstream outfile;
					outfile.open(filename, ios::app);
					int i;
					for(i=0;i<capacity;i++){
						outfile.write((char*)&donorArray[i],sizeof(donorArray[i]));
					}
					outfile.close();
				}
				else{
					cout << "Unrecognized command. Retype 'Save' and try again.\n" << endl;
				}

			}
			else{
				ofstream outfile;
					outfile.open(filename, ios::app);
					int i;
					for(i=0;i<capacity;i++){
						outfile.write((char*)&donorArray[i],sizeof(donorArray[i]));
					}
					outfile.close();
			}

		}
		else{
			cout << "Enter a file name.\n";
			cin >> filename;
			ofstream outfile;
			outfile.open(filename, ios::app);
			int i;
			for(i=0;i<capacity;i++){
				outfile.write((char*)&donorArray[i],sizeof(donorArray[i]));
			}
			outfile.close();			
		}
}

void DonorDatabase::Load(){

}

void DonorDatabase::Report(){
	cout << "There are " << current << " donors." << endl;

	float totalDonated = 0;
	int i;
	for(i=0;i<capacity;i++){
		totalDonated = totalDonated + donorArray[i].amountDonated;
	}
	cout << totalDonated << " total donated." << endl;
}

void DonorDatabase::Quit(){
	string command;
	cout << "Would you like to save? Type 'Yes' to save or any other key to exit.\n" << endl;
	cin >> command;
	if(command == "Yes"){
		Save();
	}
}
