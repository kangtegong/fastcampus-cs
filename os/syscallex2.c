#include <stdio.h>
#include <unistd.h>

int main() {
    // fork() 시스템 콜을 호출하여 자식 프로세스 생성
    int pid = fork();

    if (pid == -1) {
        // fork 실패
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // 자식 프로세스  
        printf("자식 프로세스\n");
    } else {
        // 부모 프로세스  
        printf("부모 프로세스\n");
    }

    return 0;
}
