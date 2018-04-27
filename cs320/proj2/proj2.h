#ifndef PROJ2_H
#define PROJ2_H

#include <string>

using namespace std;

class proj2 {

	private:
		int branches;
		int correct;

	public:
		string output;
		proj2();
		void direct_mapped();
		void set_associative();
		void full_LRU();
		void full_hot_cold();
		void set_no_alloc();
		void set_w_prefetch();
		void prefetch_on_miss();

};

#endif
