

#include <iostream>
#include <stdlib.h>

using namespace std;

void multiple(int n){
	if(n == 0 || n < 0){
		return;
	}

	if(n == 1){
		// << endl = \n
		cout << 3 << " ";
		return;
	}
	else{
		multiple(n-1);
		cout << 3*n << " ";
		return;
	}
}

int main(int argc, char* argv[]){
	string n;
	cout << "Enter N: ";
	cin >> n;
	multiple(stoi(n)); //prints first N multiples of 3
	
}
