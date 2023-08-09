#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    const char *dirname = "."; // 현재 디렉터리

    // 디렉터리 열기
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        perror("디렉터리 열기 오류");
        return 1;
    } else {
        printf("디렉터리 열기 성공\n");
    }

    printf("디렉터리 내용:\n");

    // 디렉터리 읽기
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // 디렉터리 닫기
    if (closedir(dir) == 0) {
        printf("디렉터리 닫기 성공: %s\n", dirname);
    } else {
        perror("디렉터리 닫기 실패");
        return 1;
    }

    return 0;
}
