// This is a single line comment
/* *****This is a
******Multiline Comment
**** */
#pragma startup func1
#pragma exit func2
#include <stdio.h>

void func1()
{
    printf("Inside func1()\n");
}

void func2()
{
    printf("Inside func2()\n");
}

void main()
{
    FILE *fopen(), *fp;
    int c;
    fp = fopen("prog.c", "r"); //Comment
    c = getc(fp);
    while (c != EOF)
    {
        putchar(c);
        c = getc(fp);
    }
    /*multiline
comment */
    fclose(fp);
}