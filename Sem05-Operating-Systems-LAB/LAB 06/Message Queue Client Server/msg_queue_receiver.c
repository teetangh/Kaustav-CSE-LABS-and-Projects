#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct my_msg_st
{
    long int msg_type;
    char some_text[BUFSIZ];
};

int main(int argc, char const *argv[])
{
    int running = 1;
    int msgid;
    long int msg_to_receive = 0;
    struct my_msg_st some_data;
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        fprintf(stderr, "message failed with error no : %d", errno);
        exit(EXIT_FAILURE);
    }

    while (running)
    {
        if (msgrcv(msgid, (void *)&some_data, BUFSIZ, msg_to_receive, 0) == -1)
        {
            fprintf(stderr, "Messsage Receive Failed\n");
            exit(EXIT_FAILURE);
        }

        printf("You Wrote %s \n", some_data.some_text);
        if (strncmp(some_data.some_text, "end", 3) == 0)
            running = 0;
    }

    if (msgctl(msgid, IPC_RMID, 0) == -1)
    {
        fprintf(stderr, "msgctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
