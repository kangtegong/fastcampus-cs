#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* produce(void* arg);
void* consume(void* arg);

int sum = 0;
pthread_mutex_t mutex;
pthread_cond_t cond_var;

int main() {
    printf("초기 합계: %d\n", sum);

    pthread_t producer_thread, consumer_thread;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_var, NULL);

    pthread_create(&producer_thread, NULL, produce, NULL);
    pthread_create(&consumer_thread, NULL, consume, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_var);

    printf("실행 이후 합계: %d\n", sum);

    return 0;
}

void* produce(void* arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);
        sum++;

        // consumer 깨우기
        pthread_cond_signal(&cond_var);

        pthread_mutex_unlock(&mutex);
    }
}

void* consume(void* arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);

        // 소비할 데이터가 없으면 기다린다
        while (sum == 0) {
            pthread_cond_wait(&cond_var, &mutex);
        }

        sum--;
        pthread_mutex_unlock(&mutex);
    }
}
