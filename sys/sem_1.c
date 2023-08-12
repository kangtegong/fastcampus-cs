#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 4
#define MAX_COUNT 100000

sem_t semaphore; // unnamed semaphore

int shared_counter = 0;

void *increment_counter(void *thread_id) {
    int tid = *((int *)thread_id);

    for (int i = 0; i < MAX_COUNT; i++) {
        sem_wait(&semaphore);
        shared_counter++; // 공유 자원 접근
        sem_post(&semaphore);
    }

    printf("Thread %d finished\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    if (sem_init(&semaphore, 0, 1) != 0) {
        perror("sem_init");
        return 1;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, increment_counter, &thread_ids[i]) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return 1;
        }
    }

    if (sem_destroy(&semaphore) != 0) {
        perror("sem_destroy");
        return 1;
    }

    printf("Final counter value: %d\n", shared_counter);

    return 0;
}
