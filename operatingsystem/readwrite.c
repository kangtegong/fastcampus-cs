#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[1024];
    ssize_t bytesRead;

    // source.txt 읽기 전용으로 열기
    int src_fd = open("source.txt", O_RDONLY);

    // destination.txt 쓰기 전용으로 열기, 없으면 생성, 퍼미션 0644로 설정
    int dest_fd = open("destination.txt", O_WRONLY | O_CREAT, 0644);

    // source.txt로부터 데이터를 읽어오고, 읽은 데이터의 크기를 bytesRead에 저장
    while ((bytesRead = read(src_fd, buffer, sizeof(buffer))) > 0) {
        // 읽은 데이터를 대상 파일에 쓰기
        write(dest_fd, buffer, bytesRead);
    }

    // 열어둔 파일 디스크립터들 닫기
    close(src_fd);
    close(dest_fd);

    return 0;
}
