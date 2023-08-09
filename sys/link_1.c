#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *originf = "original.txt";
    const char *linkf = "linked.txt";

    // 원본 파일 생성
    FILE *file = fopen(originf, "w");
    if (file == NULL) {
        perror("원본 파일 생성 오류");
        return 1;
    }
    fprintf(file, "원본 파일\n");
    fclose(file);

    // 링크 생성
    if (link(originf, linkf) == 0) {
        printf("링크 생성 성공: %s -> %s\n", linkf, originf);
    } else {
        perror("링크 생성 실패");
        return 1;
    }

    return 0;
}
