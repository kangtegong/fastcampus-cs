#include <stdio.h>

int main() {
    FILE *file; // 파일 포인터 선언

    // 파일 열기 시도
    file = fopen("example.txt", "w"); // "example.txt" 파일을 쓰기 모드로 열기

    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1; // 오류 코드 반환
    }

    // 파일에 데이터 쓰기
    fprintf(file, "안녕하세요, 파일에 쓰는 예제입니다.\n");

    // 파일 닫기
    fclose(file);

    return 0; // 프로그램 종료
}

