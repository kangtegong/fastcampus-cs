#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* produce(void* arg);
void* consume(void* arg);

int sum = 0;
pthread_mutex_t mutex;

int main() {
    printf("초기 합계: %d\n", sum);

    pthread_t producer_thread, consumer_thread;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&producer_thread, NULL, produce, NULL);
    pthread_create(&consumer_thread, NULL, consume, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    pthread_mutex_destroy(&mutex);

    printf("실행 이후 합계: %d\n", sum);
    return 0;
}

void* produce(void* arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);
        sum++;
	pthread_mutex_unlock(&mutex);
    }
}

void* consume(void* arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);
	sum--;
	pthread_mutex_unlock(&mutex);
    }
}
