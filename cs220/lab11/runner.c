

#include <stdio.h>
#include <unistd.h>

int main(){
	int pid = getpid();
	printf("My pid is %d, parent pid is %d.\n", getpid(), getppid());
}
