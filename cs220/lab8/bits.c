#include "bits.h"
#include <stdio.h>

void print_in_binary(unsigned int x){
	int i;
	for(i = 31; i >= 0; i--){
		/* logic to get ith bit of a number */
		if( ((x >> i) & 1) == 1 ){
			printf("1");
		} else{
			printf("0");
		}
		printf("\n");
	}
}

/* 
Bits 0 to 11 = PAGE OFFSET
Bits 12, 13, 14 = TLB ID.
Bits 15 to 23 NOT USED.
Bits 24 to 31 = TLB Tag. 
*/

/* test these macros with print_in_binary */

unsigned int get_page_offset(unsigned int address){
	BF_MASK(0,12);
	BF_PREP(address, 0, 12);
	BF_GET(address, 0, 12);
}

unsigned int get_tlb_id(unsigned int address){
	BF_MASK(12, 3);
	BF_PREP(address, 12, 3);
	BF_GET(address, 12, 3);
}

unsigned int get_tlb_tag(unsigned int address){
	BF_MASK(24, 8);
	BF_PREP(address, 24, 8);
	BF_GET(address, 24, 8);
}

unsigned int set_page_offset(unsigned int address, unsigned int new_offset){
	BF_MASK(0,12);
	BF_PREP(address, 0, 12);
	BF_SET(address, new_offset, 0, 12);
}

unsigned int set_tlb_id(unsigned int address, unsigned int new_tlb_id){
	BF_MASK(12, 3);
	BF_PREP(address, 12, 3);
	BF_SET(address, new_tlb_id, 12, 3);
}

unsigned int set_tlb_tag(unsigned int address, unsigned int new_tag){
	BF_MASK(24, 8);
	BF_PREP(address, 24, 8);
	BF_SET(address, new_tag, 24, 8);
}
