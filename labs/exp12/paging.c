#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[2];

int counter;
pthread_mutex_t lock;

void *doSomething(void *args) {
	pthread_mutex_lock(&lock);
	unsigned int i = 0;
	counter += 1;
	
	printf("\nJob %d started\n", counter);
	
	for (i = 0; i < 0xFFFFFF; i++);
	
	printf("\nJob %d finished\n", counter);

	pthread_mutex_unlock(&lock);
	return NULL;
}

int main(void) {
	int i = 0;
	int err;
	if (pthread_mutex_init(&lock, NULL) != 0) {
		printf("\nmutex init failed\n");
		return 1;
	} 
	while(i < 2) {
		err = pthread_create(&(tid[i]), NULL, &doSomething, NULL);
		if (err != 0)
			printf("Can't create thread: [%s]", strerror(err));
		i++;
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&lock);

	return 0;
}

