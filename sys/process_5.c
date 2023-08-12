/*
 * zombie process 만들기
 * $ cc process_5.c -o zombie
 * $ ./zombie &
 * $ ps -ef | grep defunct | grep -v grep
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("[start] child process\n", getpid());
        exit(0); // 바로 종료
    }
    else {
        printf("[start] parent process %d\n", pid);
        sleep(10); // 부모 프로세스 10초 sleep
    }

    return 0;
}
