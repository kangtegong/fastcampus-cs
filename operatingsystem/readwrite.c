#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[1024];
    ssize_t bytesRead, bytesWritten;

    int src_fd = open("source.txt", O_RDONLY);
    int dest_fd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    while ((bytesRead = read(src_fd, buffer, sizeof(buffer))) > 0) {
        bytesWritten = write(dest_fd, buffer, bytesRead);
    }

    close(src_fd);
    close(dest_fd);

    return 0;
}
