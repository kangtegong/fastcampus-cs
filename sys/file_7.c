#include <stdio.h>

int main() {
    FILE *file;

    file = fopen("output.txt", "w");
    if (file == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    // 파일에 텍스트 쓰기
    fprintf(file, "안녕하세요, 파일에 쓰는 예제입니다.\n");
    fprintf(file, "숫자 출력: %d\n", 42);

    fclose(file);

    return 0;
}
