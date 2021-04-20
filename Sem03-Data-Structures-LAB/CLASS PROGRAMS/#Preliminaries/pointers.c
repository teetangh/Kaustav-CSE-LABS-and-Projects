#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a = 10;
    int *p = &a;
    int **q = &p;

    printf("q address %p \n", q);
    printf("p address %p \n", p);
    printf("*q address %p \n", *q);
    printf("**q address %p \n", **q);

    printf("q value %d \n", q);
    printf("*q value %d \n", *q);
    printf("**q value %d \n", **q);

    printf("a address %p \n", a);
    printf("a value %d \n", a);
}