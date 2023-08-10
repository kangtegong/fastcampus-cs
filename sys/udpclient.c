#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 9876
#define MAX_BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];

    // 소켓 생성
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(PORT);

    while (1) {
        printf("Enter a message: ");
        fgets(buffer, sizeof(buffer), stdin);

        // 서버로 데이터 송신
        sendto(sockfd, buffer, strlen(buffer), 0, (const struct sockaddr *)&server_addr, sizeof(server_addr));

        // 서버로부터 데이터 수신
        ssize_t received_bytes = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
        buffer[received_bytes] = '\0';

        printf("Server response: %s", buffer);
    }

    return 0;
}
