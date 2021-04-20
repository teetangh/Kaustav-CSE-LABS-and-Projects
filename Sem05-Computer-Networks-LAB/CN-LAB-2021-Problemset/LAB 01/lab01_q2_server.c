// Will practice again
/*  Make the necessary includes and set up the variables.  */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    /*  Create an unnamed socket for the server.  */

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /*  Name the socket.  */

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = 9735;
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

    /*  Create a connection queue and wait for clients.  */

    listen(server_sockfd, 5);
    while (1)
    {
        char ch[100];

        printf("server waiting\n");

        /*  Accept a connection.  */

        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd,
                               (struct sockaddr *)&client_address, &client_len);

        /*  We can now read/write to client on client_sockfd.  */
        //char *inet_ntoa(client_addr.sin_addr);
        char *ip_add = inet_ntoa(client_address.sin_addr);
        int port = client_address.sin_port;

        printf("IP:%s  PORT:%d\n", ip_add, port);
        read(client_sockfd, ch, 100);
        printf("%s\n", ch);

        for (int i = 0; ch[i] != '\0'; i++)
        {
            if (ch[i] >= 'a' && ch[i] <= 'z')
            {
                ch[i] = ch[i] - 32;
            }
        }

        // ch.upper();
        write(client_sockfd, ch, 100);
        close(client_sockfd);
    }
}
