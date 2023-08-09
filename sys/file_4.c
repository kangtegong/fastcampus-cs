#include <stdio.h>

int main() {
    FILE *file;
    int num1, num2;

    // 파일 열기
    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    // 파일에서 두 개의 정수 읽어오기
    if (fscanf(file, "%d %d", &num1, &num2) != 2) {
        perror("데이터 읽기 실패");
        fclose(file);
        return 1;
    }

    // 파일 닫기
    fclose(file);

    // 두 정수의 합 출력
    printf("두 정수의 합: %d\n", num1 + num2);

    return 0;
}
