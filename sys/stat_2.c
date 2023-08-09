#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main() {
    const char *filename = "example.txt";

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("파일 열기 오류");
        return 1;
    }

    struct stat filestat;

    // 파일의 메타데이터 정보 가져오기
    if (fstat(fd, &filestat) == 0) {
        printf("파일 크기: %ld bytes\n", filestat.st_size);
        printf("아이노드 번호: %ld\n", filestat.st_ino);
        printf("파일 링크 수: %ld\n", filestat.st_nlink);
        printf("파일 크기: %ld bytes\n", filestat.st_size);
        printf("블록 크기: %ld bytes\n", filestat.st_blksize);
        printf("할당된 블록 수: %ld\n", filestat.st_blocks);
        printf("최근 접근 시간: %s", ctime(&filestat.st_atime));
        printf("최근 수정 시간: %s", ctime(&filestat.st_mtime));
    } else {
        perror("fstat 오류");
        return 1;
    }

    close(fd);

    return 0;
}

