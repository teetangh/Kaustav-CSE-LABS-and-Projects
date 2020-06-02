#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[25];
    int roll;
    double cg;
} st;

int read(st *p)
{
    fflush(stdin);
    printf("Input name: \n");
    gets(p->name);

    printf("Input Roll: \n");
    scanf("%d", &(p->roll));

    printf("Input Cgpa: \n");
    scanf("%lf", &(p->cg));

    fflush(stdin);
    return 0;
}

int display(st *p)
{
    printf("\n Name: \n");
    puts(p->name);

    printf("\n Roll: \n");
    printf("%d", p->roll);

    printf("\n Cgpa: \n");
    printf("%lf", p->cg);

    printf("\n ");

    return 0;
}

int sort(st *p, int n)
{
    int i = 0, j = 0, t = 0;

    char namet[25];
    double cgt = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            /* code */
            if ((p + j)->roll > (p + j + 1)->roll)
            {
                //Roll Swap
                t = (p + j)->roll;
                (p + j)->roll = (p + j + 1)->roll;
                (p + j + 1)->roll = t;

                //Cgpa Swap
                cgt = (p + j)->cg;
                (p + j)->cg = (p + j + 1)->cg;
                (p + j + 1)->cg = cgt;

                //NameSwap
                strcpy(namet, (p + j)->name);
                strcpy((p + j)->name, (p + j + 1)->name);
                strcpy((p + j + 1)->name, namet);
            }
        }
    }
    return 0;
}

int main()
{
    int n, i = 0;
    printf("Input the number of students \n");
    scanf("%d", &n);

    st *p = (st *)calloc(n, sizeof(st));
    printf("Input the details of students \n");

    while (i < n)
    {
        read(p + i);
        i++;
    }

    sort(p, n);
    printf("SORTED LIST is: \n");

    for (i = 0; i < n; i++)
    {
        display((p + i));
    }
    return 0;
}