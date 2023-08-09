#include <stdio.h>

int main() {
    FILE *file;
    int ch;
    char buffer[100];

    // fgetc를 이용한 파일 읽기
    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    printf("fgetc를 이용한 파일 내용:\n");
    while ((ch = fgetc(file)) != EOF) {
        printf("%c\n", ch);
    }

    fclose(file);

    // fgets를 이용한 파일 읽기
    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    printf("\nfgets를 이용한 파일 내용:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);

    return 0;
}

