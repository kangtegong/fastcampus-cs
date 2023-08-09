#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *file; // 파일 포인터
    int fd;     // 파일 디스크립터

    // 파일 열기 시도
    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("파일 열기 오류");
        return 1;
    }

    // 파일 포인터를 파일 디스크립터로 변환
    fd = fileno(file);

    printf("file descriptor: %d\n", fd);

    // 파일 닫기
    fclose(file);

    return 0;
}
