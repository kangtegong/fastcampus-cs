#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-l", NULL};
    printf("before exec...\n");
    // "ls" 프로그램을 구성하는 코드로 자신을 덮어씌움
    execvp("ls", args);

    return 1;
}
