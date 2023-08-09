#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char *argv[]) {
    struct stat sb;  // 파일 속성 정보 저장
    off_t len;       // 파일 크기 저장
    char *p;         //  매핑된 메모리를 가리킬 포인터
    int fd;           // 파일디스프립터

    // 파일열기
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // 파일 속성 가져오기
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        return 1;
    }

    // 메모리 매핑
    // NULL 혹은 0: 매핑할 메모리 주소를 자동으로 선택
    // pagesize: 매핑할 파일의 크기
    // PROT_READ: 메모리를 읽기 전용으로 매핑 (메모리 내용을 변경할 수 없음)
    // MAP_SHARED: 메모리를 SHARD 매핑
    // fd: 파일 디스크립터
    // 0: 파일 내에서 매핑을 시작할 위치(파일의 처음부터 매핑)
    int pagesize = getpagesize();
    p = mmap(NULL, pagesize, PROT_READ, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    for (len = 0; len < sb.st_size; len++)
        putchar(p[len]);

    if (munmap(p, sb.st_size) == -1) {
        perror("munmap");
        return 1;
    }

    return 0;
}
