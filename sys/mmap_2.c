#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    size_t size = getpagesize();

    int *shared_data = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared_data == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    *shared_data = 42;  // 공유 데이터에 값을 설정

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // 자식 프로세스
        printf("Child process: shared_data = %d\n", *shared_data);
        *shared_data = 84;  // 공유 데이터 변경
        printf("Child process: shared_data changed to %d\n", *shared_data);
    } else {
        // 부모 프로세스
        wait(NULL);
        printf("Parent process: shared_data = %d\n", *shared_data);
    }

    // 메모리 매핑을 해제합니다.
    munmap(shared_data, size);
    return 0;
}
