#include <stdio.h>
#include <unistd.h>

int main() {
    // 실행할 프로그램과 인자들을 배열로 정의
    char *args[] = {"ls", "-l", NULL};

    printf("before exec... \n");

    // 새로운 프로그램 실행
    // execve(const char *filename, char *const argv[], char *const envp[]);
    //   filename: 실행할 프로그램의 경로
    //   argv: 실행할 프로그램에 전달할 인자     
    execve("/bin/ls", args, NULL);

    return 0;
}

