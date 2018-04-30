#include <stdio.h>
#include "proj2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

proj2::proj2(){
	hits = 0;
	accesses = 0;
	output = "output.txt";
}

void proj2::direct_mapped(string filename){

	ifstream infile;
	infile.open(filename);

	ofstream outfile;
	outfile.open(output, ios::app);

	string flag;
	unsigned int address;
	unsigned int tag;
	unsigned int index;
	int cache_size = 1024;
	int block_size = 32;

	for(int i = 0; i < 4; i++){

		hits = 0;
		accesses = 0;
		int table_size = cache_size/block_size;
		vector<pair<int, int>> table;
		for(int a = 0; a < table_size; a++){
			table.push_back(make_pair(0,0));
		}

		while(infile >> flag >> hex >> address){
			index = (address << (32-5-(int)log2(cache_size/block_size))) >> (32-(int)log2(cache_size/block_size));
			tag = address >> ((int)log2(cache_size/block_size) + 5);
			if((table.at(index).first == 1) && (table.at(index).second == tag)){
				hits++;
			} else {
				table.at(index).first = 1;
				table.at(index).second = tag;
			}
			accesses++;
		}
	        outfile << hits << "," << accesses << "; ";
		if(i == 0){
			cache_size = 1024 * 4;
		}
		else if(i == 1){
			cache_size = 1024 * 16;
		}
		else if(i == 2){
			cache_size = 1024 * 32;
		}
		infile.clear();
		infile.seekg(0, ios::beg);
	}
	outfile << endl;

	infile.close();
	outfile.close();
}

void proj2::set_associative(string filename){

	ifstream infile;
	infile.open(filename);

	ofstream outfile;
	outfile.open(output, ios::app);

	string flag;
	unsigned int address;
	unsigned int tag;
	unsigned int index;
	int cache_size = (1024 * 16);
	int block_size = 32;
	int associativity = 2;
	int clock = 1;

	for(int i = 0; i < 4; i++){

		hits = 0;
		accesses = 0;
		int table_size = (cache_size/block_size);

		vector< vector<pair<int, int>> > table;
		for(int a = 0; a < associativity; a++){
			vector<pair<int, int>> way;
			for(int b = 0; b < table_size; b++){
				way.push_back(make_pair(0,0));
			}
			table.push_back(way);
		}

		vector< vector<int > > lru;
		for(int a = 0; a < associativity; a++){
			vector<int > way;
			for(int b = 0; b < table_size; b++){
				way.push_back(0);
			}
			lru.push_back(way);
		}

		while(infile >> flag >> hex >> address){
			int something_happened = 0;
			int min = 0;

			index = (address << (32-5-(int)log2(cache_size/block_size))) >> (32-(int)log2(cache_size/block_size));
			tag = address >> ((int)log2(cache_size/block_size) + 5);

			for(int j = 0; j < associativity; j++){
				if(table.at(j).at(index).first == 0){
					table.at(j).at(index).first = 1;
					table.at(j).at(index).second = tag;

					lru.at(j).at(index) = clock;
					clock++;
					something_happened = 1;
					break;
				}
				if(table.at(j).at(index).first == 1 && table.at(j).at(index).second == tag){
					hits++;

					lru.at(j).at(index) = clock;
					clock++;
					something_happened = 1;
					break;
				}

			}
			if(something_happened == 0){
				for(int k = 0; k < associativity; k++){
					if(lru.at(k).at(index) < lru.at(min).at(index)){
						min = k;
					}
				}
				table.at(min).at(index).second = tag;

				lru.at(min).at(index) = clock;
				clock++;
				something_happened = 1;
			}
			accesses++;
		}
	        outfile << hits << "," << accesses << "; ";
		if(i == 0){
			associativity = 4;
		}
		else if(i == 1){
			associativity = 8;
		}
		else if(i == 2){
			associativity = 16;
		}
		infile.clear();
		infile.seekg(0, ios::beg);
	}
	outfile << endl;

	infile.close();
	outfile.close();
}

void proj2::full_LRU(string filename){
	ifstream infile;
	infile.open(filename);

	ofstream outfile;
	outfile.open(output, ios::app);

	string flag;
	unsigned int address;
	unsigned int tag;
	unsigned int index;
	int cache_size = (1024 * 16);
	int block_size = 32;
	int clock = 1;

	hits = 0;
	accesses = 0;
	int table_size = (cache_size/block_size);

	vector< vector<pair<int, int>> > table;
	for(int a = 0; a < table_size; a++){
		vector<pair<int, int> > way;
		way.push_back(make_pair(0,0));
		table.push_back(way);
	}
	vector< vector<int > > lru;
	for(int a = 0; a < table_size; a++){
		vector<int > way;
		way.push_back(0);
		lru.push_back(way);
	}
	while(infile >> flag >> hex >> address){
		int something_happened = 0;
		int min = 0;

		tag = address >> 5;

		for(int j = 0; j < table_size; j++){

			if(table.at(j).at(0).first == 0 && table.at(j).at(0).second == 0){
				table.at(j).at(0).first = 1;
				table.at(j).at(0).second = tag;

				lru.at(j).at(0) = clock;
				clock++;
				something_happened = 1;
				break;
			}
			if(table.at(j).at(0).first == 1 && table.at(j).at(0).second == tag){
				hits++;

				lru.at(j).at(0) = clock;
				clock++;
				something_happened = 1;
				break;
			}

		}
		if(something_happened == 0){
			for(int k = 0; k < table_size; k++){
				if(lru.at(k).at(0) < lru.at(min).at(0)){
					min = k;
				}
			}
			table.at(min).at(0).second = tag;

			lru.at(min).at(0) = clock;
			clock++;
			something_happened = 1;
		}
		accesses++;
	}

        outfile << hits << "," << accesses << ";" << endl;

	infile.clear();
	infile.seekg(0, ios::beg);

	infile.close();
	outfile.close();

}

void proj2::full_hot_cold(string filename){

}

void proj2::set_no_alloc(string filename){
	ifstream infile;
	infile.open(filename);

	ofstream outfile;
	outfile.open(output, ios::app);

	string flag;
	unsigned int address;
	unsigned int tag;
	unsigned int index;
	int cache_size = (1024 * 16);
	int block_size = 32;
	int associativity = 2;
	int clock = 1;

	for(int i = 0; i < 4; i++){

		hits = 0;
		accesses = 0;
		int table_size = (cache_size/block_size);

		vector< vector<pair<int, int>> > table;
		for(int a = 0; a < associativity; a++){
			vector<pair<int, int>> way;
			for(int b = 0; b < table_size; b++){
				way.push_back(make_pair(0,0));
			}
			table.push_back(way);
		}

		vector< vector<int > > lru;
		for(int a = 0; a < associativity; a++){
			vector<int > way;
			for(int b = 0; b < table_size; b++){
				way.push_back(0);
			}
			lru.push_back(way);
		}

		while(infile >> flag >> hex >> address){
			int something_happened = 0;
			int min = 0;

			index = (address << (32-5-(int)log2(cache_size/block_size))) >> (32-(int)log2(cache_size/block_size));
			tag = address >> ((int)log2(cache_size/block_size) + 5);

			for(int j = 0; j < associativity; j++){
				if(table.at(j).at(index).first == 0 && flag == "L"){
					table.at(j).at(index).first = 1;
					table.at(j).at(index).second = tag;

					lru.at(j).at(index) = clock;
					clock++;
					something_happened = 1;
					break;
				}
				if(table.at(j).at(index).first == 1 && table.at(j).at(index).second == tag){
					hits++;

					lru.at(j).at(index) = clock;
					clock++;
					something_happened = 1;
					break;
				}

			}
			if(something_happened == 0 && flag == "L"){
				for(int k = 0; k < associativity; k++){
					if(lru.at(k).at(index) < lru.at(min).at(index)){
						min = k;
					}
				}
				table.at(min).at(index).second = tag;

				lru.at(min).at(index) = clock;
				clock++;
				something_happened = 1;
			}
			accesses++;
		}
	        outfile << hits << "," << accesses << "; ";
		if(i == 0){
			associativity = 4;
		}
		else if(i == 1){
			associativity = 8;
		}
		else if(i == 2){
			associativity = 16;
		}
		infile.clear();
		infile.seekg(0, ios::beg);
	}
	outfile << endl;

	infile.close();
	outfile.close();
}

void proj2::set_w_prefetch(string filename){

	ifstream infile;
	infile.open(filename);

	ofstream outfile;
	outfile.open(output, ios::app);

	string flag;
	unsigned int address;
	unsigned int tag;
	unsigned int index;
	int cache_size = (1024 * 16);
	int block_size = 32;
	int associativity = 2;
	int clock = 1;

	for(int i = 0; i < 4; i++){

		hits = 0;
		accesses = 0;
		int table_size = (cache_size/block_size);

		vector< vector<pair<int, int>> > table;
		for(int a = 0; a < associativity; a++){
			vector<pair<int, int>> way;
			for(int b = 0; b < table_size; b++){
				way.push_back(make_pair(0,0));
			}
			table.push_back(way);
		}

		vector< vector<int > > lru;
		for(int a = 0; a < associativity; a++){
			vector<int > way;
			for(int b = 0; b < table_size; b++){
				way.push_back(0);
			}
			lru.push_back(way);
		}

		while(infile >> flag >> hex >> address){
			int something_happened = 0;
			int min = 0;

			index = (address << (32-5-(int)log2(cache_size/block_size))) >> (32-(int)log2(cache_size/block_size));
			tag = address >> ((int)log2(cache_size/block_size) + 5);

			for(int j = 0; j < associativity; j++){
				if(table.at(j).at(index).first == 0){
					table.at(j).at(index).first = 1;
					table.at(j).at(index).second = tag;

					lru.at(j).at(index) = clock;
					clock++;
					something_happened = 1;
					break;
				}
				if(table.at(j).at(index).first == 1 && table.at(j).at(index).second == tag){
					hits++;

					lru.at(j).at(index) = clock;
					clock++;
					something_happened = 1;
					break;
				}

			}
			if(something_happened == 0){
				for(int k = 0; k < associativity; k++){
					if(lru.at(k).at(index) < lru.at(min).at(index)){
						min = k;
					}
				}
				table.at(min).at(index).second = tag;

				lru.at(min).at(index) = clock;
				clock++;
				something_happened = 1;
			}

			//repeat

			something_happened = 0;
			min = 0;

			index = ((address+32) << (32-5-(int)log2(cache_size/block_size))) >> (32-(int)log2(cache_size/block_size));
			tag = (address+32) >> ((int)log2(cache_size/block_size) + 5);

			for(int j = 0; j < associativity; j++){
				if(table.at(j).at(index).first == 0){
					table.at(j).at(index).first = 1;
					table.at(j).at(index).second = tag;

					lru.at(j).at(index) = clock;
					clock++;
					something_happened = 1;
					break;
				}
				if(table.at(j).at(index).first == 1 && table.at(j).at(index).second == tag){
					//hits++;

					lru.at(j).at(index) = clock;
					clock++;
					something_happened = 1;
					break;
				}

			}
			if(something_happened == 0){
				for(int k = 0; k < associativity; k++){
					if(lru.at(k).at(index) < lru.at(min).at(index)){
						min = k;
					}
				}
				table.at(min).at(index).second = tag;

				lru.at(min).at(index) = clock;
				clock++;
				something_happened = 1;
			}

			accesses++;
		}
	        outfile << hits << "," << accesses << "; ";
		if(i == 0){
			associativity = 4;
		}
		else if(i == 1){
			associativity = 8;
		}
		else if(i == 2){
			associativity = 16;
		}
		infile.clear();
		infile.seekg(0, ios::beg);
	}
	outfile << endl;

	infile.close();
	outfile.close();
}

void proj2::prefetch_on_miss(string filename){
	ifstream infile;
	infile.open(filename);

	ofstream outfile;
	outfile.open(output, ios::app);

	string flag;
	unsigned int address;
	unsigned int tag;
	unsigned int index;
	int cache_size = (1024 * 16);
	int block_size = 32;
	int associativity = 2;
	int clock = 1;

	for(int i = 0; i < 4; i++){

		hits = 0;
		accesses = 0;
		int table_size = (cache_size/block_size);

		vector< vector<pair<int, int>> > table;
		for(int a = 0; a < associativity; a++){
			vector<pair<int, int>> way;
			for(int b = 0; b < table_size; b++){
				way.push_back(make_pair(0,0));
			}
			table.push_back(way);
		}

		vector< vector<int > > lru;
		for(int a = 0; a < associativity; a++){
			vector<int > way;
			for(int b = 0; b < table_size; b++){
				way.push_back(0);
			}
			lru.push_back(way);
		}

		while(infile >> flag >> hex >> address){
			int something_happened = 0;
			int min = 0;

			index = (address << (32-5-(int)log2(cache_size/block_size))) >> (32-(int)log2(cache_size/block_size));
			tag = address >> ((int)log2(cache_size/block_size) + 5);

			for(int j = 0; j < associativity; j++){
				if(table.at(j).at(index).first == 0){
					table.at(j).at(index).first = 1;
					table.at(j).at(index).second = tag;

					lru.at(j).at(index) = clock;
					clock++;
					something_happened = 1;

					//repeat on miss
				something_happened = 0;
				min = 0;

				index = ((address+32) << (32-5-(int)log2(cache_size/block_size))) >> (32-(int)log2(cache_size/block_size));
				tag = (address+32) >> ((int)log2(cache_size/block_size) + 5);

				for(int j = 0; j < associativity; j++){
					if(table.at(j).at(index).first == 0){
						table.at(j).at(index).first = 1;
						table.at(j).at(index).second = tag;

						lru.at(j).at(index) = clock;
						clock++;
						something_happened = 1;
						break;
					}
					if(table.at(j).at(index).first == 1 && table.at(j).at(index).second == tag){
						//hits++;

						lru.at(j).at(index) = clock;
						clock++;
						something_happened = 1;
						break;
					}

				}
				if(something_happened == 0){
					for(int k = 0; k < associativity; k++){
						if(lru.at(k).at(index) < lru.at(min).at(index)){
							min = k;
						}
					}
					table.at(min).at(index).second = tag;

					lru.at(min).at(index) = clock;
					clock++;
					something_happened = 1;
				}
					//repeat end
					break;
				}
				if(table.at(j).at(index).first == 1 && table.at(j).at(index).second == tag){
					hits++;

					lru.at(j).at(index) = clock;
					clock++;
					something_happened = 1;
					break;
				}

			}
			if(something_happened == 0){
				for(int k = 0; k < associativity; k++){
					if(lru.at(k).at(index) < lru.at(min).at(index)){
						min = k;
					}
				}
				table.at(min).at(index).second = tag;

				lru.at(min).at(index) = clock;
				clock++;
				something_happened = 1;

				//repeat on miss
				something_happened = 0;
				min = 0;

				index = ((address+32) << (32-5-(int)log2(cache_size/block_size))) >> (32-(int)log2(cache_size/block_size));
				tag = (address+32) >> ((int)log2(cache_size/block_size) + 5);

				for(int j = 0; j < associativity; j++){
					if(table.at(j).at(index).first == 0){
						table.at(j).at(index).first = 1;
						table.at(j).at(index).second = tag;

						lru.at(j).at(index) = clock;
						clock++;
						something_happened = 1;
						break;
					}
					if(table.at(j).at(index).first == 1 && table.at(j).at(index).second == tag){
						//hits++;

						lru.at(j).at(index) = clock;
						clock++;
						something_happened = 1;
						break;
					}

				}
				if(something_happened == 0){
					for(int k = 0; k < associativity; k++){
						if(lru.at(k).at(index) < lru.at(min).at(index)){
							min = k;
						}
					}
					table.at(min).at(index).second = tag;

					lru.at(min).at(index) = clock;
					clock++;
					something_happened = 1;
				}
				//repeat end
			}
			accesses++;
		}
	        outfile << hits << "," << accesses << "; ";
		if(i == 0){
			associativity = 4;
		}
		else if(i == 1){
			associativity = 8;
		}
		else if(i == 2){
			associativity = 16;
		}
		infile.clear();
		infile.seekg(0, ios::beg);
	}
	outfile << endl;

	infile.close();
	outfile.close();

}

int main(int argc, char* argv[]){

	proj2* p = new proj2();

	if(argc > 2){
		p->output = argv[2];
	}

	p->direct_mapped(argv[1]);
	p->set_associative(argv[1]);
	//p->full_LRU(argv[1]);
	//p->full_hot_cold(argv[1]);
	p->set_no_alloc(argv[1]);
	p->set_w_prefetch(argv[1]);
	p->prefetch_on_miss(argv[1]);

	return 0;
}
