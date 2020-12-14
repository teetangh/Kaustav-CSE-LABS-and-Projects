
#pragma startup func1
#pragma exit func2
#include <stdio.h>
#include <stdlib.h>

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
 fp = fopen("prog.c", "r");  c = getc(fp);
 while (c != EOF)
 {
 putchar(c);
 c = getc(fp);
 }
 
 fclose(fp);
}