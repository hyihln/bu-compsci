

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


void Donor::Add(){

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
	cout << "Zip code: ";
	cin >> zipCode;

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
	cout << "Zip code: ";
	cin >> zipCode;

}

void Donor::View(){

	cout << "Donor Info\n" << donorFirstName << " " << donorLastName << ": age " << age << "\n" << streetNumber << " " << streetName << "\n" << town << ", NY " << zipCode << "\n" << "Current Amount Donated: " << amount << "\n";
}

void Donor::Donate(){
	//to format decimal places
	cout << fixed;
	cout << setprecision(2);

	cout << "Enter Amount to Donate: \n";
	float tmp = amount;
	cin >> amount;
	amountDonated = amountDonated + amount;
	amount = amount + tmp;
}

void Donor::Total(){

	cout << "$" << amountDonated << "\n";
}

void Donor::Quit(){

}
