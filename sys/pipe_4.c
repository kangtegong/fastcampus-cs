#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    const char *pipe_name = "my_named_pipe";
    mkfifo(pipe_name, 0666);

    int pipe_fd = open(pipe_name, O_RDWR);
    if (pipe_fd == -1) {
        perror("Error opening pipe");
        return 1;
    }

    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("Error forking process");
        return 1;
    }

    if (child_pid == 0) { // Child process
        char received_message[100];
        read(pipe_fd, received_message, sizeof(received_message));
        printf("[child]  Received: %s\n", received_message);
    } else { // Parent process
        char message[] = "Hello from parent!";
        write(pipe_fd, message, strlen(message) + 1);
        printf("[parent] Sent: %s\n", message);
    }

    close(pipe_fd);

    return 0;
}
