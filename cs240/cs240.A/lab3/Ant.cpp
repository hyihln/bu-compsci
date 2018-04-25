
#include "AntHill.h"
#include <iostream>
#include <cstdlib>

Ant::Ant(int number){
	id = number;
	x = 0;
	y = 0;
}
void Ant::move(){
	int direction = rand()%4;
	// up +1
	if (direction == 0){
		y = getY()+1;
	}
	// down
	if (direction == 1){
		y = getY()-1;
	}
	// left
	if (direction == 2){
		x = getX()-1;
	}
	// right
	if (direction == 3){
		x = getX()+1;
	}
}
Ant::~Ant(){

}

