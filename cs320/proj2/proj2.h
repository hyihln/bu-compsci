#ifndef PROJ2_H
#define PROJ2_H

#include <string>

using namespace std;

class proj2 {

	private:
		int hits;
		int accesses;
	public:
		string output;
		proj2();
		void direct_mapped(string filename);
		void set_associative(string filename);
		void full_LRU(string filename);
		void full_hot_cold(string filename);
		void set_no_alloc(string filename);
		void set_w_prefetch(string filename);
		void prefetch_on_miss(string filename);

};

#endif
