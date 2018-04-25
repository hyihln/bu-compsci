
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>


char* array[1024];
sem_t len;

void* worker_function1(){
	printf("Enter a word: ");
	scanf("%s",array);
	sem_post(&len);
}

void* worker_function2(){
	sem_wait(&len);
	printf("Write: %s\n", array);
}

int main(){
	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, worker_function1, NULL);
	pthread_create(&tid2, NULL, worker_function2, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	return 0;
}
