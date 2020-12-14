#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 5000
#define MAXLINE 1000

int main(int argc, char const *argv[])
{
    char buffer[100];
    char *message = "Hello Server";
    int sockfd, len, n;
    struct sockaddr_in servaddr, cliaddr;

    // Clear servaddr
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;

    // Create the datagram socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    sendto(sockfd, message, MAXLINE, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    len = sizeof(cliaddr);

    // Waiting for response
    n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);

    buffer[n] = '\0';

    printf("message from the server is %s \n", buffer);
    getchar();

    // Close the descriptor
    close(sockfd);
    return 0;
}
