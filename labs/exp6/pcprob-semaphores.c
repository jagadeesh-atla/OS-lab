#include <stdio.h>
#include <stdlib.h>

#define N 5

int mutex = 1, full = 0, empty = 5, x = 0;

void producer();
void consumer();

int wait (int);
int signal (int);

int main() {
	int choice = 0;
	printf("Press 1 - PRODUCER \t Press 2 - CONSUMER \t Press 3 - EXIT\n");

	while (1) {
		printf("Enter your Choice : ");
		scanf("%d", &choice);

		switch (choice) {
			case (1) : { 
					if ((mutex == 1) && (empty != 0)) {
						producer();
						printf("full: %d, mutex: %d, empty: %d\n", full, mutex, empty);
					} else printf("BUFFER is FULL\n");
					break;
				}
			case (2) : {
					if ((mutex == 1) && (full != 0)) {
						consumer();
						printf("full: %d, mutex: %d, empty: %d\n", full, mutex, empty);
					} else printf("BUFFER is EMPTY\n");
					break;
				}
			case (3) : {
					exit(0);
					break;
				}
		}
		
	}

	return 0;
}


int wait (int s) {
	return --s;
}

int signal (int s) {
	return ++s;
}

void producer() {
	mutex = wait(mutex);
	full = signal(full);
	empty = wait(empty);

	x++;
	printf("PRODUCER produced item : %d\n", x);

	mutex = signal(mutex);
}

void consumer() {
	mutex = wait(mutex);
	full = wait(full);
	empty = signal(empty);

	printf("CONSUMER consumed item : %d\n", x);
	x--;

	mutex = signal(mutex);
}

