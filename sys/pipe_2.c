#include <stdio.h>
#include <unistd.h>

int main() {
    int pipe_fds[2]; // 파이프 파일 디스크립터 배열
    int pipe_creation_status; // 파이프 생성 상태
    char messages_to_write[2][20] = {"Hi", "Hello"}; // 쓸 메시지 배열
    char received_message[20]; // 읽은 메시지 저장할 배열
    pid_t child_pid; // 자식 프로세스의 PID 저장 변수

    // 파이프 생성 및 상태 저장
    pipe_creation_status = pipe(pipe_fds);

    if (pipe_creation_status == -1) {
        printf("Unable to create pipe\n");
        return 1;
    }

    child_pid = fork();

    if (child_pid == 0) { // 자식 프로세스
        read(pipe_fds[0], received_message, sizeof(received_message));
        printf("[child] first pipe reading: %s\n", received_message);

        read(pipe_fds[0], received_message, sizeof(received_message));
        printf("[child] second pipe reading: %s\n", received_message);
    } else { // 부모 프로세스
        printf("[parent] first pipe writing: %s\n", messages_to_write[0]);
        write(pipe_fds[1], messages_to_write[0], sizeof(messages_to_write[0]));

        printf("[parent] second pipe writing: %s\n", messages_to_write[1]);
        write(pipe_fds[1], messages_to_write[1], sizeof(messages_to_write[1]));
    }

    return 0;
}
