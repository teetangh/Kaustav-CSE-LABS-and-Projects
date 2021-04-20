#include "CharStack.h"
#include <string.h>

void main()
{
    STACK s1, s2;
    s1.top = -1;
    s2.top = -1;

    char input[50];
    char output[50];

    printf("Enter String");
    // fflush(stdin);
    gets(input);
    puts(input);

    int i = 0, j = 0, k = 0;

    for (int i = 0; i <= strlen(input); i++)
    {
        /* code */
        push(&s1, input[i]);
    }

    // while (input[i] != '\0')
    // {
    //     push(&s1, input[i++]);
    // }
    display(&s1);

    while (s1.top != -1)
    {
        //j = 0;
        while (s1.arr[s1.top] != ' ')
        {
            push(&s2, pop(&s1));
        }

        while (s2.top != -1)
            output[j++] = pop(&s2);
        output[j++] = ' ';

        output[j] = '\0';

        printf('Output is : \n');
        puts(output);
    }

    output[++j] = '\0';

    printf('Output is : \n');
    puts(output);
}