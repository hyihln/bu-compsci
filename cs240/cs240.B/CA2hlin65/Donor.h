

#ifndef DONOR_H
#define DONOR_H

using namespace std;

class Donor {
	public:
		Donor();

		void Manage();
		void Passwd();
		void View();
		void Donate();
		void Total();
		void Logout();
		
	private:
		string donorLastName;
		string donorFirstName;
		string userid;
		string password;
		int age;
		int streetNumber;
		string streetName;
		string town;
		string state;
		string zipCode;
		float amountDonated;

		float amount;

		friend class DonorDatabase;
};

#endif
