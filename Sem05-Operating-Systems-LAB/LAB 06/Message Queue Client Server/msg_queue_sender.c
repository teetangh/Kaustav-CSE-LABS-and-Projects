#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define MAX_TEXT 512

struct my_message_st
{
    long int my_msg_type;
    char some_text[MAX_TEXT];
};

int main(int argc, char const *argv[])
{
    int running = 1;
    struct my_message_st some_data;
    char buffer[MAX_TEXT];

    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if (msgid != 0)
    {
        fprintf(stderr, "message failed with error no : %d", errno);
        exit(EXIT_FAILURE);
    }

    while (running)
    {
        printf("Enter some text \n");
        fgets(buffer, BUFSIZ, stdin);
        some_data.my_msg_type = 1;
        strcpy(some_data.some_text, buffer);

        if (msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0) == -1)
        {
            fprintf(stderr, "Message Sending failed \n");
            exit(EXIT_FAILURE);
        }

        if (strncmp(buffer, "end", 3) == 0)
            running = 0;

        exit(EXIT_FAILURE);
    }

    return 0;
}
