

#include <iostream>
#include <stdlib.h>

using namespace std;

void multiple(int n){
	if(n == 0 || n < 0){
		// << endl = \n
		//cout << 3 << " ";
		return;
	}
	else{
		cout << 3*n << " ";
		multiple(n-1);
		return;
	}
}

int main(int argc, char* argv[]){
	string n;
	cout << "Enter N: ";
	cin >> n;
	multiple(stoi(n)); //prints first N multiples of 3 in reverse order
	
}
