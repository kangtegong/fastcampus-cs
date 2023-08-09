#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *symlinkf = "symlink.txt";

    char target_path[1024]; // 심볼릭 링크의 실제 경로를 저장할 버퍼

    // 심볼릭 링크의 실제 경로 읽기
    ssize_t bytesread = readlink(symlinkf, target_path, sizeof(target_path) - 1);
    if (bytesread != -1) {
        target_path[bytesread] = '\0'; // 문자열 끝에 널 문자 추가
        printf("심볼릭 링크의 실제 경로: %s\n", target_path);
    } else {
        perror("readlink 오류");
        return 1;
    }

    return 0;
}
