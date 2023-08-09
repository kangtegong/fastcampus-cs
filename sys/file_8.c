#include <stdio.h>

int main() {
    FILE *file;

    file = fopen("output.txt", "w");
    if (file == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    // 파일에 문자 쓰기
    fputc('H', file);
    fputc('e', file);
    fputc('l', file);
    fputc('l', file);
    fputc('o', file);

    // 파일에 문자열 쓰기
    fputs("\n안녕하세요, 파일에 문자열 쓰는 예제입니다.\n", file);

    fclose(file);

    return 0;
}
