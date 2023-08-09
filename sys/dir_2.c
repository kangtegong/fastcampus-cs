#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *dirname = "example_dir";

    // 디렉터리 삭제
    if (rmdir(dirname) == 0) {
        printf("디렉터리 삭제 성공: %s\n", dirname);
    } else {
        perror("디렉터리 삭제 실패");
        return 1;
    }

    return 0;
}

