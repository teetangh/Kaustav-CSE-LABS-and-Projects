#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include "lab06_q1_common.h"

bool is_palindrome(long long int original_number)
{
    long long int last_digit = 0, reverse = 0, temp = original_number;
    printf("original %lld \n", original_number);

    while (temp > 0)
    {
        last_digit = temp % 10;
        reverse = (reverse * 10) + last_digit;
        temp = temp / 10;
    }
    printf("Reverse %lld \n", reverse);

    if (reverse == original_number)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    int running = 1;
    int msgid;
    long int msg_to_receive = 0;
    struct lab06_q1_structure some_data;
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

        printf("You Wrote %lld \n", some_data.original_number);
        if (is_palindrome(some_data.original_number))
            printf("Palindrome\n");
        else
            printf("Not Palindrome\n");
    }

    if (msgctl(msgid, IPC_RMID, 0) == -1)
    {
        fprintf(stderr, "msgctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
