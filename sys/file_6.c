#include <stdio.h>

int main() {
    FILE *file;
    char buffer[100];
    size_t elements_read;

    file = fopen("hello", "rb");
    if (file == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    // 100바이트 크기의 buffer에 바이너리 데이터 읽어오기
    elements_read = fread(buffer, sizeof(char), sizeof(buffer), file);

    if (elements_read == 0) {
        perror("데이터 읽기 실패");
        fclose(file);
        return 1;
    }

    // 읽어온 바이너리 데이터 출력
    printf("읽어온 바이너리 데이터:\n");
    for (size_t i = 0; i < elements_read; i++) {
        printf("%02X ", (unsigned char)buffer[i]);
    }
    printf("\n");

    fclose(file);

    return 0;
}
