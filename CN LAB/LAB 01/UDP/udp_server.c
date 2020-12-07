#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 5000
#define maxline 1000

int main(int argc, char const *argv[])
{
    char buffer[100];
    int servsockfd, len, n;
    struct sockaddr_in servaddr, cliaddr;

    // Create a UDP socket
    servsockfd = socket(AF_INET, SOCK_DGRAM, 0);
    /* INADDR_ANY returns the ip address of the system*/
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Bind the server address to the socket descriptior
    bind(servsockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Recieve the datagram
    len = sizeof(cliaddr);
    n = recvfrom(servsockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);
    buffer[n] = '\0';
    puts(buffer);

    // Echoing back to the client
    sendto(servsockfd, buffer, n, 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
    getchar();

    // Close the descriptor
    close(servsockfd);
    return 0;
}
