#include <stdio.h>
#include "proj2.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

proj2::proj2(){
	correct = 0;
	branches = 0;
	output = "output.txt";
}

void proj2::direct_mapped(string filename){

	ifstream infile;
	infile.open(filename);

	long address;
	string tag;
	branches = 0;
	correct = 0;

	while(infile >> hex >> address >> tag){

	}

	infile.close();

	ofstream outfile;
	outfile.open(output, ios::app);
        outfile << correct << "," << branches << ";" << endl;
	outfile.close();
}

void proj2::set_associative(string filename){

}

void proj2::full_LRU(string filename){

}

void proj2::full_hot_cold(string filename){

}

void proj2::set_no_alloc(string filename){

}

void proj2::set_w_prefetch(string filename){

}

void proj2::prefetch_on_miss(string filename){

}

int main(int argc, char* argv[]){

	proj2* p = new proj2();

	if(argc > 2){
		p->output = argv[2];
	}

	p->direct_mapped();

	return 0;
}
