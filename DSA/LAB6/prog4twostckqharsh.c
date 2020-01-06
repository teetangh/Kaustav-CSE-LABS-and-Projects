#include <stdio.h>
#include <stdlib.h>
#include "IntStack2.h"
int main()
{
    stack s1;
    s1.top = -1;
    stack s2;
    s2.top = -1;
    int e;
    int ch;
    int i;
    int x;
    do
    {
        printf("Enter your choice:\n");
        printf("1.PUSH\t2.POP\t3.DISPLAY\t4.EXIT\n");
        scanf("%d", &ch);
        fflush(stdin);
        switch (ch)
        {
        case 1:
            printf("Input the Entry to push\n");
            scanf("%d", &e);
            fflush(stdin);
            push(&s1, e);
            break;
        case 2:
            if (isEmpty(&s2) && !isEmpty(&s1))
            {
                while (!isEmpty(&s1))
                {
                    int k = pop(&s1);
                    push(&s2, k);
                }
            }
            x = pop(&s2);
            if (x != -9999)
            {
                printf("Removed: %d\n", x);
            }
            else
            {
                printf("\nQUEUE EMPTY\n");
            }
            break;
        case 3:
            if (!isEmpty(&s2))
                for (i = s2.top; i >= 0; i--)
                    printf("%d ", s2.arr[i]);
            display(&s1);
            break;
        default:
            printf("\nEXIT STATUS INITIATED\n");
            exit(0);
            break;
        }
    } while (ch != 4);
    return 0;
}