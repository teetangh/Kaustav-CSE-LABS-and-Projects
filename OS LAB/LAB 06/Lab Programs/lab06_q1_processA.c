#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>
#include "lab06_q1_common.h"

int main(int argc, char const *argv[])
{
    int running = 1;
    struct lab06_q1_structure some_data;

    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if (msgid != 0)
    {
        fprintf(stderr, "message failed with error no : %d", errno);
        exit(EXIT_FAILURE);
    }

    while (running)
    {
        printf("Enter some number \n");
        scanf(" %lld", &some_data.original_number);
        some_data.message_type = 1;

        if (msgsnd(msgid, (void *)&some_data, sizeof(some_data), 0) == -1)
        {
            fprintf(stderr, "Message Sending failed \n");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_FAILURE);
    }

    return 0;
}
