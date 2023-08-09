#include <stdio.h>

int main() {
    FILE *file;
    char data[] = { 'H', 'e', 'l', 'l', 'o', '\n' };

    file = fopen("output.txt", "w");
    if (file == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    // 바이너리 데이터를 파일에 쓰기
    size_t elements_written = fwrite(data, sizeof(char), sizeof(data), file);
    if (elements_written != sizeof(data)) {
        perror("데이터 쓰기 실패");
        fclose(file);
        return 1;
    }

    fclose(file);

    return 0;
}
