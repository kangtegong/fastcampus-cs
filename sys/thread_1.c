#include <stdio.h>
#include <pthread.h>

// 17번째 줄의 &thread_args[i]가 여기 인자로 들어감
void *thread_function(void *arg) {
    int thread_id = *((int *)arg);
    printf("Thread %d is running\n", thread_id);
    pthread_exit(NULL);  // 스레드 종료
}

int main() {
    pthread_t thread_ids[5];  // 스레드 식별자 배열
    int thread_args[5];       // 스레드 인자 배열

    for (int i = 0; i < 5; i++) {
        thread_args[i] = i;
        int result = pthread_create(&thread_ids[i], NULL, thread_function, &thread_args[i]);
        if (result != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    // 생성된 스레드의 종료를 기다림
    for (int i = 0; i < 5; i++) {
        int result = pthread_join(thread_ids[i], NULL);
        if (result != 0) {
            perror("pthread_join");
            return 1;
        }
        printf("Thread %d has finished\n", i);
    }

    return 0;
}
