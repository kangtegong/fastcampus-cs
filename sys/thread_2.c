#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    int thread_id = *((int *)arg);
    printf("Thread %d is running\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_ids[5];
    int thread_args[5];

    for (int i = 0; i < 5; i++) {
        thread_args[i] = i;
        int result = pthread_create(&thread_ids[i], NULL, thread_function, &thread_args[i]);
        if (result != 0) {
            perror("pthread_create");
            return 1;
        }

        // 스레드를 detached 상태로 설정
        result = pthread_detach(thread_ids[i]);
        if (result != 0) {
            perror("pthread_detach");
            return 1;
        }
    }

    // 각 스레드가 실행을 완료할 시간 주기
    sleep(1);

    return 0;
}
