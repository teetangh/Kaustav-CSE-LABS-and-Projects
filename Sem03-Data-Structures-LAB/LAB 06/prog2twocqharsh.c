#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
#define max 25
typedef struct
{
    char a[MAX][MAX];
    int f1, r1;
    int f2, r2;
} stcq;
int isFull1(stcq *s)
{
    int k = (s->r1 + 1) % max;
    return (k == s->f1);
}
int isEmpty1(stcq *s)
{
    if (s->f1 == s->r1)
    {
        s->f1 = -1;
        return 1;
    }
    return 0;
}
void push1(stcq *s, char e[])
{
    if (isFull1(s))
    {
        printf("\nSTRING CQ 1 FULL\n");
    }
    else
    {
        s->r1 = (s->r1 + 1) % max;
        strcpy(s->a[s->r1], e);
        if (s->f1 == -1)
            s->f1 = 0;
    }
}
char *pop1(stcq *s)
{
    if (s->f1 == -1)
    {
        printf("\nSTRING CQ 1 EMPTY\n");
        return "ERR";
    }
    else
    {
        int n = isEmpty1(s);
        if (s->f1 == -1)
        {
            return (s->a[s->r1]);
        }
        int k = s->f1;
        s->f1 = ((s->f1 + 1) % max);
        return (s->a[k]);
    }
}
void display1(stcq *s)
{
    if (s->f1 == -1 && isEmpty1(s))
    {
        printf("\nEMPTY CQ 1\n");
    }
    else
    {
        int i;
        for (i = s->f1; (i % max) != s->r1; i++)
        {
            printf("%s ", s->a[(i % max)]);
        }
        printf("%s ", s->a[s->r1]);
        printf("\n");
    }
}
int isFull2(stcq *s)
{
    int k = (s->r2 + 1) % MAX;
    return (k == s->f2);
}
int isEmpty2(stcq *s)
{
    if (s->f2 == s->r2)
    {
        if (MAX % 2 == 0)
        {
            s->f2 = MAX / 2 - 1;
        }
        else
        {
            s->f2 = MAX / 2;
        }
        return 1;
    }
    return 0;
}
void push2(stcq *s, char e[])
{
    if (isFull1(s))
    {
        printf("\nSTRING CQ 2 FULL\n");
    }
    else
    {
        s->r2 = (s->r2 + 1) % MAX;
        strcpy(s->a[s->r2], e);
        if (s->f2 == MAX / 2 - 1 || s->f2 == MAX / 2)
            s->f2 += 1;
    }
}
char *pop2(stcq *s)
{
    if (s->f2 == MAX / 2 - 1 || s->f2 == MAX / 2)
    {
        printf("\nSTRING CQ 2 EMPTY\n");
        return "ERR";
    }
    else
    {
        int n = isEmpty1(s);
        if (s->f2 == MAX / 2 - 1 || s->f2 == MAX / 2)
        {
            return (s->a[s->r2]);
        }
        int k = s->f2;
        s->f2 = ((s->f2 + 1) % MAX);
        return (s->a[k]);
    }
}
void display2(stcq *s)
{
    if ((s->f2 == MAX / 2 - 1 || s->f2 == MAX / 2) && isEmpty1(s))
    {
        printf("\nEMPTY CQ 2\n");
    }
    else
    {
        int i;
        for (i = s->f2; (i % MAX) != s->r2; i++)
        {
            printf("%s ", s->a[(i % MAX)]);
        }
        printf("%s ", s->a[s->r2]);
        printf("\n");
    }
}
int main()
{
    int ch;
    char *e = (char *)calloc(max, sizeof(char));
    stcq *s = (stcq *)malloc(sizeof(stcq));
    s->f1 = -1;
    s->r1 = -1;
    int c = 0;
    if (MAX % 2 == 0)
    {
        s->f2 = MAX / 2 - 1;
        s->r2 = MAX / 2 - 1;
    }
    else
    {
        s->f2 = MAX / 2;
        s->r2 = MAX / 2;
    }
    do
    {
        printf("Enter your choice:\n");
        printf("1.PUSH\t2.POP\t3.DISPLAY\t4.EXIT\n");
        scanf("%d", &ch);
        fflush(stdin);
        switch (ch)
        {
        case 1:
            printf("Input the String to push\n");
            scanf("%s", e);
            fflush(stdin);
            printf("1.PUSH AT 1\t2.PUSH AT 2\n");
            scanf("%d", &c);
            fflush(stdin);
            if (c == 1)
                push1(s, e);
            else if (c == 2)
                push2(s, e);
            break;
        case 2:
            printf("1.POP AT 1\t2.POP AT 2\n");
            scanf("%d", &c);
            fflush(stdin);
            if (c == 1)
            {
                strcpy(e, pop1(s));
                if (strcmp(e, "ERR") != 0)
                {
                    printf("Removed: %s\n", e);
                    if (s->f1 == -1)
                        s->r1 = -1;
                }
            }
            else if (c == 2)
            {
                strcpy(e, pop2(s));
                if (strcmp(e, "ERR") != 0)
                {
                    printf("Removed: %s\n", e);
                    if (s->f2 == MAX / 2 - 1 || s->f2 == MAX / 2)
                        s->r2 = s->f2;
                }
            }
            free(e);
            break;
        case 3:
            printf("1.DISPLAY AT 1\t2.DISPLAY AT 2\n");
            scanf("%d", &c);
            fflush(stdin);
            if (c == 1)
                display1(s);
            else if (c == 2)
                display2(s);
            break;
        default:
            printf("\nEXIT STATUS INITIATED\n");
            exit(0);
            break;
        }
    } while (ch != 4);
    return 0;
}