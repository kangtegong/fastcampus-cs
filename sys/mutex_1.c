#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_COUNT 100000

pthread_mutex_t mutex;

int shared_counter = 0;

void *increment_counter(void *thread_id) {
    int tid = *((int *)thread_id);

    for (int i = 0; i < MAX_COUNT; i++) {
        pthread_mutex_lock(&mutex);
        shared_counter++; // 공유 자원 접근
        pthread_mutex_unlock(&mutex);
    }

    printf("Thread %d finished\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // 뮤텍스 초기화
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        perror("pthread_mutex_init");
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

    if (pthread_mutex_destroy(&mutex) != 0) {
        perror("pthread_mutex_destroy");
        return 1;
    }

    printf("Final counter value: %d\n", shared_counter);

    return 0;
}
