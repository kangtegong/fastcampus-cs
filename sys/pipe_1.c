#include <stdio.h>
#include <unistd.h>

int main() {
    int pipe_fds[2]; // 파이프 파일 디스크립터 배열
    int pipe_creation_status; // 파이프 생성 상태
    char write_messages[2][20] = {"Hi", "Hello"}; // 쓸 메시지 배열
    char read_message[20]; // 읽은 메시지 저장할 배열
  
    // 파이프 생성 및 상태 저장
    pipe_creation_status = pipe(pipe_fds); 

    if (pipe_creation_status == -1) {
        printf("Unable to create pipe\n");
        return 1;
    }

    // 첫 번째 메시지 쓰기
    printf("first pipe writing: %s\n", write_messages[0]);
    write(pipe_fds[1], write_messages[0], sizeof(write_messages[0]));

    // 첫 번째 메시지 읽기
    read(pipe_fds[0], read_message, sizeof(read_message));
    printf("first pipe reading: %s\n", read_message);

    // 두 번째 메시지 쓰기
    printf("second pipe writing: %s\n", write_messages[1]);
    write(pipe_fds[1], write_messages[1], sizeof(write_messages[1]));

    // 두 번째 메시지 읽기
    read(pipe_fds[0], read_message, sizeof(read_message));
    printf("second pipe reading: %s\n", read_message);

    return 0;
}
