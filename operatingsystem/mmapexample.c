#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    struct stat sb;
    char *mapped;

    // 파일 오픈
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // 파일 정보 얻기
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        exit(EXIT_FAILURE);
    }

    // 메모리 매핑
    mapped = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mapped == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // 매핑된 데이터 출력
    printf("%s\n", mapped);

    // 메모리 매핑 해제
    if (munmap(mapped, sb.st_size) == -1) {
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    // 파일 닫기
    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return 0;
}
