

#include <iostream>
#include <stdlib.h>
#include <iomanip> //to use fixed & setprecision
#include "Donor.h"

using namespace std;

Donor::Donor(){
	donorLastName = "";
	donorFirstName = "";
	age = 0;
	streetNumber = 0;
	streetName = "";
	town = "";
	zipCode = "";
	amountDonated = 0;

	amount = 0;
}


void Donor::Manage(){
	
	cout << "Last name: ";
	cin >> donorLastName;
	cout << "First name: ";
	cin >> donorFirstName;
	cout << "Age: ";
	cin >> age;
	cout << "Street number: ";
	cin >> streetNumber;
	cout << "Street name: ";
	cin >> streetName;
	cout << "Town: ";
	cin >> town;
	cout << "State: ";
	cin >> state;
	cout << "Zip code: ";
	cin >> zipCode;

}

void Donor::Passwd(){
	string check;
	string newPW;
	string newPWAgain;
	cout << "Enter old password.\n" << endl;
	cin >> check;
	if(password == check){
		cout << "Enter new password.\n" << endl;
		cin >> newPW;
		cout << "Reenter password.\n" << endl;
		cin >> newPWAgain;
		if(newPW == newPWAgain){
			password = newPW;
		}
		else{
			cout << "Passwords do not match. Password reset terminated.\n" << endl;
		}
	}
	else{
		cout << "Incorrect password entered. Type Passwd() and try again.\n" << endl;
	}
}

void Donor::View(){

	cout << "Donor Info\n" << donorFirstName << " " << donorLastName << ": age " << age << "\n" << streetNumber << " " << streetName << "\n" << town << ", " << state << " " << zipCode << "\n" << "Current Amount Donated: " << amount << "\n";
}

void Donor::Donate(){
	//to format decimal places
	cout << fixed;
	cout << setprecision(2);

	cout << "Enter Amount to Donate: \n";
	float tmp = amount;
	cin >> amount;
	if(amount < 0 || amount > 5000){
		cout << "Try again." << endl;
		Donate();
	}
	else{
		amountDonated = amountDonated + amount;
		amount = amount + tmp;
	}
}

void Donor::Total(){

	cout << donorLastName << " $" << amountDonated << "\n";
}

void Donor::Logout(){
	cout << "Top level menu: Login, Add, Save, Load, Report, Quit.\n" << endl;
}
