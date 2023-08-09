#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    // 파일을 열고 파일 디스크립터를 얻음
    fd = open("example.txt", O_RDONLY);

    if (fd == -1) {
        perror("Failed to open the file");
        return 1;
    }

    printf("File descriptor: %d\n", fd);

    // 파일을 닫음
    if (close(fd) == -1) {
        perror("Failed to close the file");
        return 1;
    }

    return 0;
}
