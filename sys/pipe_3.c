#include <stdio.h>
#include <unistd.h>

int main() {
    int pipe_fds1[2], pipe_fds2[2]; // 파이프 파일 디스크립터 배열
    int pipe_creation_status1, pipe_creation_status2; // 파이프 생성 상태
    char write_message1[20] = "Hi"; // 파이프 1에 쓸 메시지
    char write_message2[20] = "Hello"; // 파이프 2에 쓸 메시지
    char read_message[20]; // 읽은 메시지 저장할 배열
    pid_t child_pid;

    // 파이프 생성 및 상태 저장
    pipe_creation_status1 = pipe(pipe_fds1);
    pipe_creation_status2 = pipe(pipe_fds2);

    if (pipe_creation_status1 == -1) {
        printf("Unable to create pipe 1\n");
        return 1;
    }

    if (pipe_creation_status2 == -1) {
        printf("Unable to create pipe 2\n");
        return 1;
    }

    child_pid = fork();

    if (child_pid != 0) { // 부모 프로세스
        close(pipe_fds1[0]); // 파이프 1의 읽기 파일 디스크립터 닫기
        close(pipe_fds2[1]); // 파이프 2의 쓰기 파일 디스크립터 닫기
        
        printf("[parent] Writing to pipe 1: Message is %s\n", write_message1);
        write(pipe_fds1[1], write_message1, sizeof(write_message1));
        
        read(pipe_fds2[0], read_message, sizeof(read_message));
        printf("[parent] Reading from pipe 2: Message is %s\n", read_message);
    } else { // 자식 프로세스
        close(pipe_fds1[1]); // 파이프 1의 쓰기 파일 디스크립터 닫기
        close(pipe_fds2[0]); // 파이프 2의 읽기 파일 디스크립터 닫기
        
        read(pipe_fds1[0], read_message, sizeof(read_message));
        printf("[child] Reading from pipe 1:  Message is %s\n", read_message);
        
        printf("[child] Writing to pipe 2: Message is %s\n", write_message2);
        write(pipe_fds2[1], write_message2, sizeof(write_message2));
    }

    return 0;
}
