#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char cwd[1024]; // 현재 작업 디렉터리 경로를 저장할 버퍼

    // 현재 작업 디렉터리 경로 가져오기
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("현재 작업 디렉터리: %s\n", cwd);
    } else {
        perror("getcwd 오류");
        return 1;
    }

    // 다른 디렉터리로 작업 디렉터리 변경
    const char *newdir = "/";
    if (chdir(newdir) == 0) {
        printf("작업 디렉터리 변경 성공: %s\n", newdir);
    } else {
        perror("작업 디렉터리 변경 실패");
        return 1;
    }

    // 변경된 작업 디렉터리 경로 가져오기
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("변경된 작업 디렉터리: %s\n", cwd);
    } else {
        perror("getcwd 오류");
        return 1;
    }

    return 0;
}
