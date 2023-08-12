#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t parent_pid = getpid();

    pid_t pid = fork();  // 자식 프로세스 생성

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // 자식 프로세스
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        // 부모 프로세스
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}
