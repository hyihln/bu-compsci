#include <stdio.h>
#include "proj1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

proj1::proj1(){
	correct = 0;
	branches = 0;
	output = "output.txt";
}

void proj1::pTaken(string filename){

	ifstream infile;
	infile.open(filename);

	long address;
	string tag;
	branches = 0;
	correct = 0;

	while(infile >> hex >> address >> tag){
		if(tag == "T"){
			correct++;
		}
		branches++;
	}

	infile.close();

	ofstream outfile;
	outfile.open(output, ios::app);
        outfile << correct << "," << branches << ";" << endl;
	outfile.close();
}

void proj1::pNT(string filename){
        ifstream infile;
        infile.open(filename);

        long address;
        string tag;
	branches = 0;
	correct = 0;

        while(infile >> hex >> address >> tag){
                if(tag == "NT"){
                        correct++;
                }
                branches++;
        }

        infile.close();

        ofstream outfile;
        outfile.open(output, ios::app);
        outfile << correct << "," << branches << ";" << endl;
        outfile.close();
}

void proj1::singlebit(string filename){
        ifstream infile;
        infile.open(filename);

        ofstream outfile;
        outfile.open(output, ios::app);

        long address;
        string tag;

	int ptsize = 16;

	int index;

	for(int i = 0; i < 7; i++){
		correct = 0;

		string ptable[ptsize];
		fill_n(ptable, ptsize, "T");

		while(infile >> hex >> address >> tag){

			index = (ptsize-1) & address;

			if(ptable[index] == tag){
				correct++;
			}
			else{
				ptable[index] = tag;
			}
		}

		infile.clear();
		infile.seekg(0, ios::beg);

		if(ptsize == 32){
			ptsize = ptsize *4;
		}
		else{
			ptsize = ptsize *2;
		}

		outfile << correct << "," << branches << "; ";
	}
	outfile << endl;

        infile.close();
        outfile.close();
}

void proj1::twobit(string filename){
	ifstream infile;
	infile.open(filename);

	ofstream outfile;
	outfile.open(output, ios::app);

	long address;
	string tag;

	int ptsize = 16;
	int index;

        for(int i = 0; i < 7; i++){
                correct = 0;

                string ptable[ptsize];
                fill_n(ptable, ptsize, "TT");

                while(infile >> hex >> address >> tag){

                        index = (ptsize-1) & address;

                        if(tag == "T"){
				if(ptable[index] == "TT"){
					correct++;
				}
                                else if(ptable[index] == "T"){
					correct++;
					ptable[index] = "TT";
                                }
                                else if(ptable[index] == "NT"){
					ptable[index] = "T";
                                }
                                else if(ptable[index] == "NNT"){
					ptable[index] = "NT";
                                }
                        }
                        else{
                                if(ptable[index] == "TT"){
                                        ptable[index] = "T";
                                }
                                else if(ptable[index] == "T"){
                                        ptable[index] = "NT";
                                }
                                else if(ptable[index] == "NT"){
                                        correct++;
					ptable[index] = "NNT";
                                }
                                else if(ptable[index] == "NNT"){
                                        correct++;
                                }

                        }
                }

                infile.clear();
                infile.seekg(0, ios::beg);

                if(ptsize == 32){
                        ptsize = ptsize *4;
                }
                else{
                        ptsize = ptsize *2;
                }
                outfile << correct << "," << branches << "; ";
        }
        outfile << endl;

	infile.close();
	outfile.close();
}

void proj1::gshare(string filename){
        ifstream infile;
        infile.open(filename);

        ofstream outfile;
        outfile.open(output, ios::app);

        long address;
        string tag;

        int ptsize = 2048;
        int index;
	int gr = 0;
	int second;

        for(int i = 0; i < 9; i++){

	        correct = 0;
	        branches = 0;

	        string ptable[ptsize];
	        fill_n(ptable, ptsize, "TT");


                while(infile >> hex >> address >> tag){
//                	gr = gr << 1;
//			if(gr >= pow(2, (3+i) )){
//				gr = gr - pow(2, (3+i) );
//			}
//			gr = gr + second;

                        index = gr ^ (address & 2047);

                        if(tag == "T"){
                                if(ptable[index] == "TT"){
                                        correct++;
                                }
                                else if(ptable[index] == "T"){
                                        correct++;
                                        ptable[index] = "TT";
                                }
                                else if(ptable[index] == "NT"){
                                        ptable[index] = "T";
                                }
                                else if(ptable[index] == "NNT"){
                                        ptable[index] = "NT";
                                }

				second = 1;
                        }
                        else{
                                if(ptable[index] == "TT"){
                                        ptable[index] = "T";
                                }
                                else if(ptable[index] == "T"){
                                        ptable[index] = "NT";
                                }
                                else if(ptable[index] == "NT"){
                                        correct++;
                                        ptable[index] = "NNT";
                                }
                                else if(ptable[index] == "NNT"){
                                        correct++;
                                }

				second = 0;

                        }

                        gr = gr << 1;
                        if(gr >= pow(2, (3+i) )){
                                gr = gr - pow(2, (3+i) );
                        }
                        gr = gr + second;

//                        index = gr ^ (address & 2047);

			branches++;
                }

                infile.clear();
                infile.seekg(0, ios::beg);

                outfile << correct << "," << branches << "; ";
        }
        outfile << endl;

        infile.close();
        outfile.close();
}

void proj1::tournament(string filename){
        ifstream infile;
        infile.open(filename);

        ofstream outfile;
        outfile.open(output, ios::app);

        long address;
        string tag;

        int ptsize = 2048;
        int index;
        int gr = 0;
        int second;
	string pselect;

        correct = 0;
        branches = 0;

        string ptable[2048];
        fill_n(ptable, ptsize, "TT");

	string bimodal[2048];
	fill_n(bimodal, 2048, "TT");

	string selector[2048];
	fill_n(selector, 2048, "0");

	string gshare[2048];
	fill_n(gshare, 2048, "TT");

        while(infile >> hex >> address >> tag){

                index = gr ^ (address & 2047);


                        if(tag == "T"){
/*
				if(gshare[(address & 2047) ^ gr] > 1){
					pselect += 1;
				}
				if(bimodal[address & 2047] > 1){
					pselect +=2;
				}
*/
                                if(ptable[index] == "TT"){
                                        correct++;
                                }
                                else if(ptable[index] == "T"){
                                        correct++;
                                        ptable[index] = "TT";
                                }
                                else if(ptable[index] == "NT"){
                                        ptable[index] = "T";
                                }
                                else if(ptable[index] == "NNT"){
                                        ptable[index] = "NT";
                                }

                                second = 1;
                        }
                        else{
/*
				if(gshare[(address & 2047) ^ gr] < 2){
					pselect += 1;
				}
				if(bimodal[(address & 2047)] < 2){
					pselect +=2;
				}
*/
                                if(ptable[index] == "TT"){
                                        ptable[index] = "T";
                                }
                                else if(ptable[index] == "T"){
                                        ptable[index] = "NT";
                                }
                                else if(ptable[index] == "NT"){
                                        correct++;
                                        ptable[index] = "NNT";
                                }
                                else if(ptable[index] == "NNT"){
                                        correct++;
                                }

                                second = 0;
                        }

//			if(pselect == 1){

//			}

//                        gr = gr << 1;
//                        if(gr >= pow(2, (3+i) )){
//                                gr = gr - pow(2, (3+i) );
//                        }
//                        gr = gr + second;

                        branches++;
                }

                infile.clear();
                infile.seekg(0, ios::beg);

                outfile << correct << "," << branches << "; ";

        outfile << endl;

        infile.close();
        outfile.close();
}

int main(int argc, char* argv[]){

	proj1* p = new proj1();

	if(argc > 2){
		p->output = argv[2];
	}

	p->pTaken(argv[1]);
	p->pNT(argv[1]);
	p->singlebit(argv[1]);
	p->twobit(argv[1]);
	p->gshare(argv[1]);
//	p->tournament(argv[1]);

	return 0;
}
