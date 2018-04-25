

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

extern uint32_t* get_ebp(void);

void ret2libc(int dummy){
	uint32_t* curr_ebp = get_ebp();
	
	curr_ebp[2] = curr_ebp[1];
	curr_ebp[1] = &system;

	char* str = "/bin/bash";
	curr_ebp[3] = str;
}

void ret2libc_generic(char* cmd){
	uint32_t* curr_ebp = get_ebp();
	uint32_t* tmp = curr_ebp[2];
	
	curr_ebp[2] = curr_ebp[1];
	curr_ebp[1] = &system;

	char* str = "/bin/bash";
	curr_ebp[3] = tmp;
}

int main(){
	ret2libc_generic(0);
	printf("Done!\n");
	return 0;
}
