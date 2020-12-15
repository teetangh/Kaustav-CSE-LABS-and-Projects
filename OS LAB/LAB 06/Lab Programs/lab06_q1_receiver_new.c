// Receiver
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main()
{
    int a = 0;
    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        fprintf(stderr, "Getting message failed\n");
        exit(EXIT_FAILURE);
    }
    if (msgrcv(msgid, &a, sizeof(int), 0, 0) == -1)
    {
        printf("Sending message failed\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Number recieved is %d\n", a);
        int p = a;
        int r = 0, s = 0;

        while (p != 0)
        {
            r = p % 10;
            s = (s * 10) + r;
            p = p / 10;
        }

        if (s == a)
            printf("Palindrome\n");
        else
            printf("Not a Palindrome \n");
    }
    exit(EXIT_SUCCESS);
}
