#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("output.txt", "w+");

    if (file == NULL) {
        perror("파일 열기 오류");
        return 1;
    }

    fprintf(file, "Hello, World!\n");

    long position;

    position = ftell(file);
    printf("현재 파일 위치: %ld\n", position);

    fseek(file, 7, SEEK_SET); // 파일의 7번째 바이트로 이동

    fprintf(file, "Added Text\n");

    position = ftell(file);
    printf("이동 및 추가 쓰기 후 파일 위치: %ld\n", position);

    fclose(file);

    return 0;
}
