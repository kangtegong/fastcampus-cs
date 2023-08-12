#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    size_t size = getpagesize();  // 페이지 크기 가져오기

    int *shared_data = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared_data == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    *shared_data = 42;  // 공유 데이터에 값 설정

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // 자식 프로세스
        printf("Child process: shared_data = %d (Address: %p)\n", *shared_data, shared_data);
        *shared_data = 84;  // 공유 데이터 변경
        printf("Child process: shared_data changed to %d (Address: %p)\n", *shared_data, shared_data);
    } else {
        // 부모 프로세스
        wait(NULL);  // 자식 프로세스가 종료될 때까지 대기
        printf("Parent process: shared_data = %d (Address: %p)\n", *shared_data, shared_data);
    }

    munmap(shared_data, size);
    return 0;
}
