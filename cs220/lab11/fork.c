
#include <stdio.h>
#include <unistd.h>

int main(){
	int x = 1;
	pid_t pid;
	pid = fork();

	if(pid == 0){
		x++;
		printf("%d\n", x);
		printf("In child\n");
		printf("%d\n", pid);
		printf("%d\n", getpid());
		printf("%d\n", getppid());
	} else {
		x--;
		printf("%d\n", x);
		sleep(1);
		printf("In parent\n");
		printf("%d\n", getppid());
	}

	return(0);
}
