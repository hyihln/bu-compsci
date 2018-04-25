
#include <iostream>
#include <stdlib.h>
#include "DISH.h"
#include "DISHobj.h"

using namespace std;

int main(int argc, char* argv[]){
	DISH DISH;
	
	cout << DISH.insert("Alpha");
	cout << DISH.insert("Beta");
	cout << DISH.insert("Gamma");
}
