#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *originalf = "original.txt";
    const char *symlinkf = "symlink.txt";

    // 원본 파일 생성
    FILE *file = fopen(originalf, "w");
    if (file == NULL) {
        perror("원본 파일 생성 오류");
        return 1;
    }
    fprintf(file, "원본 파일\n");
    fclose(file);

    // 심볼릭 링크 생성
    if (symlink(originalf, symlinkf) == 0) {
        printf("심볼릭 링크 생성 성공: %s -> %s\n", symlinkf, originalf);
    } else {
        perror("심볼릭 링크 생성 실패");
        return 1;
    }

    return 0;
}
