#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

void* produce(void* arg);
void* consume(void* arg);

int sum = 0;
sem_t semaphore;

int main() {
    printf("초기 합계: %d\n", sum);

    // 세마포어 초기화. 세마포어 값은 1로 설정
    if (sem_init(&semaphore, 0, 1) != 0) {
        perror("세마포어 초기화 에러");
        exit(EXIT_FAILURE);
    }

    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, produce, NULL);
    pthread_create(&consumer_thread, NULL, consume, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&semaphore);

    printf("실행 이후 합계: %d\n", sum);

    return 0;
}

void* produce(void* arg) {
    for (int i = 0; i < 100000; i++) {
        sem_wait(&semaphore);
        sum++;
        sem_post(&semaphore);
    }
    return NULL;
}

void* consume(void* arg) {
    for (int i = 0; i < 100000; i++) {
        sem_wait(&semaphore);
        sum--;
        sem_post(&semaphore);
    }
    return NULL;
}
