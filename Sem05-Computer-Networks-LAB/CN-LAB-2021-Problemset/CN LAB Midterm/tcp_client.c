#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    int sockfd, len, result, n = 1;
    struct sockaddr_in address;
    int i, value;

    char send_buffer[256], receive_buffer[256];

    // Create a new Connection
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Create a named Connection
    address.sin_family = AF_INET;
    // address.sin_addr.s_addr = INADDR_ANY;
    // address.sin_port = htons(5555);

    address.sin_addr.s_addr = inet_addr("172.16.57.152");
    address.sin_port = (5555);

    // Create the socket
    len = sizeof(address);
    result = connect(sockfd, (struct sockaddr *)&address, len);
    if (result == -1)
    {
        perror("Client Error");
        exit(1);
    }

    // LOGIC
    while (1)
    {
        printf("\n Enter the string to send to server \n");
        gets(send_buffer);
        send_buffer[strlen(send_buffer)] = '\0';
        write(sockfd, send_buffer, sizeof(send_buffer));

        printf("STRING SENT BACK FROMSERVER IS ... ");
        n = read(sockfd, receive_buffer, sizeof(receive_buffer));
        puts(receive_buffer);
    }

    return 0;
}