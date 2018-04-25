
//AntHill
AntHill::AntHill(int max_num){
	current_ants = 0;
	max_ants = max_num;
}
bool AntHill::addAnt(){
	if(current_ants < max_ants){
		ants[current_ants] = Ant(current_ants+1);
		current_ants+=1;
		return true;
	}
	return false;
}
Ant AntHill::getAnt(int id_num){
	return ants[id_num];
}
void AntHill::move(){
	for(int i = 0; i < max_ants ; i=i+1){
		if(ants[i].getID() != 0){
			ants[i].move();
		}
	}
}
bool AntHill::changeMax(int new_max){
	if(new_max >= 0 && new_max <= 100){
		max_ants = new_max;
	}
	return true;
}
void AntHill::printHillInfo(){
	for(int i = 0; i < max_ants; i=i+1){
		std::cout << "\tAnt #"<< i << " ["<< ants[i].getX() << "," << ants[i].getY() << "]" << std::endl;

	}
}
int AntHill::getCurrentNumAnts(){
	return current_ants;
}
int AntHill::getMaxAnts(){
	return max_ants;
}
AntHill::~AntHill(){

}

