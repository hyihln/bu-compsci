
#include <stdlib.h>
#include <string>
#include "DISH.h"

using namespace std;

DISH::DISH(){
	container = {};
}

int DISH::insert(string s){
	container.push_back(DISHobj(s));
	return container.size();
}

int DISH::find(string s){

}

bool DISH::capitalize(int k){

}

bool DISH::allcaps(int k){

}

bool DISH::truncate(int k, int i){

}

string DISH::getshortest(){

}

string DISH::getfirst(){

}
