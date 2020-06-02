#include <stdio.h>

void fun1(int *x)
{
  printf("The value at a is %d \n", *x);
}

int *fun2(int *x)
{
  int *y;
  y = x;
  return y;
}

void main()
{
  int a = 10;
  int *b = &a;

  fun1(b);

  int c = 30;
  int *d = &c;
  int *e = fun2(d);
  printf("The value at c is %d \n", *e);

  int p = 100;
  int *q = &p;
  int **r = &q;

  printf("The value at p is %d \n", p);
  printf("The value at p using *q is %d \n", *q);
  printf("The value at p using **r is %d \n", **r);
}