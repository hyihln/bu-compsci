
#include "AntHill.h"
#include <iostream>

Ant::Ant(){
	id = -1;
	x = 0;
	y = 0;
}
Ant::Ant(int number){
	id = number;
	x = 0;
	y = 0;
}
void Ant::move(){
	int direction = rand()%4;
	// up +1
	if (direction == 0){
		y+=1;
	}
	// down
	if (direction == 1){
		y-=1;
	}
	// left
	if (direction == 2){
		x-=1;
	}
	// right
	if (direction == 3){
		x+=1;
	}
}
int Ant::getID(){
	return id;
}
int Ant::getX(){
	return x;
}
int Ant::getY(){
	return y;
}

int main(){
	Ant anAnt;
	
}

