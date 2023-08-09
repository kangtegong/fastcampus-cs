#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    const char *dirname = "example_dir";

    // 디렉터리 생성
    if (mkdir(dirname, 0755) == 0) {
        printf("디렉터리 생성 성공: %s\n", dirname);
    } else {
        perror("디렉터리 생성 실패");
        return 1;
    }

    return 0;
}
