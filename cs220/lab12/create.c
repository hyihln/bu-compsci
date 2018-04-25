
#include <stdio.h>
#include <pthread.h>

void* worker_function(void* payload){
	printf("In thread %d\n", (int) payload);
}

#define NUM_THREADS 3

int main(){
	pthread_t threads[NUM_THREADS];
	int i;

	void* payload;

	for(i = 0; i < NUM_THREADS; i++){
		pthread_create(&threads[i], NULL, worker_function, (void*) payload);
	}

	printf("In main thread\n");

	for(i = 0; i < NUM_THREADS; i++){
		pthread_join(threads[i], NULL);
	}

	printf("Exiting main thread\n");
	pthread_exit(NULL);
	return 0;
}
