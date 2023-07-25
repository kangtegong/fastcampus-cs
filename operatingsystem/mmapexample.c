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

    // 메모리 매핑
    mapped = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

    // 매핑된 데이터 출력
    printf("%s\n", mapped);

    // 메모리 매핑 해제
    munmap(mapped, sb.st_size);

    // 파일 닫기
    close(fd);

    return 0;
}
