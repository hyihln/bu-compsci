#include "bits.h"
#include <stdio.h>

int main(){
	print_in_binary(16);

	unsigned int address = 0xf712c0d0;

	unsigned int value = get_page_offset(0xf712c0d0);
	printf("offset: %d\n", value);

	value = get_tlb_id(0xf712c0d0);
	printf("id: %d\n", value);

	value = get_tlb_tag(0xf712c0d0);
	printf("tag: %d\n", value);

	value = set_page_offset(0xf712c0d0, 0x1a3);
	printf("offset: %d\n", value);

	value = set_tlb_id(0xf712c0d0, 0);
	printf("id: %d\n", value);

	value = set_tlb_tag(0xf712c0d0, 0x8400);
	printf("tag: %d\n", value);
}
