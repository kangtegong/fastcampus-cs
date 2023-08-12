#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

#define SEM_NAME "/my_named_semaphore"
#define MAX_COUNT 100000

int shared_counter = 0;
sem_t *semaphore; // named semaphore

void *increment_counter(void *thread_id) {
    int tid = *((int *)thread_id);

    for (int i = 0; i < MAX_COUNT; i++) {
        sem_wait(semaphore);
        shared_counter++; // 공유 자원 접근
        sem_post(semaphore);
    }

    printf("Thread %d finished\n", tid);
    pthread_exit(NULL);
}

int main() {
    semaphore = sem_open(SEM_NAME, O_CREAT, 0666, 1);

    pthread_t thread1, thread2;
    int thread_id1 = 1, thread_id2 = 2;

    pthread_create(&thread1, NULL, increment_counter, &thread_id1);
    pthread_create(&thread2, NULL, increment_counter, &thread_id2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_close(semaphore); // 세마포어 닫기
    sem_unlink(SEM_NAME); // 세마포어 삭제

    printf("Final counter value: %d\n", shared_counter);

    return 0;
}
