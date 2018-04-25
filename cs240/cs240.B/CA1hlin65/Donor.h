

#ifndef DONOR_H
#define DONOR_H

using namespace std;

class Donor {
	public:
		Donor();
		void Add();
		void Manage();
		void View();
		void Donate();
		void Total();
		void Quit();
		
	private:
		string donorLastName;
		string donorFirstName;
		int age;
		int streetNumber;
		string streetName;
		string town;
		string zipCode;
		float amountDonated;

		float amount;
};

#endif
