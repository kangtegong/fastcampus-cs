#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();  // 자식 프로세스 생성

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // 자식 프로세스
        printf("Child process: PID = %d\n", getpid());
        sleep(2);  // 자식 프로세스는 2초 동안 대기
        printf("Child process exiting...\n");
    } else {
        // 부모 프로세스
        printf("Parent process: Created child with PID = %d\n", pid);

        int status;
        pid_t child_pid = wait(&status);  // 자식 프로세스의 종료를 기다림

        if (WIFEXITED(status)) {
            printf("Parent process: Child with PID = %d exited with status %d\n", child_pid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Parent process: Child with PID = %d was terminated by signal %d\n", child_pid, WTERMSIG(status));
        }
    }

    return 0;
}
