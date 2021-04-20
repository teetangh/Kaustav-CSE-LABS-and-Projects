#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
  if (n == 0 | n == 1)
  {
    return 1;
  }
  else
  {
    return fib(n - 1) + fib(n - 2);
  }
}
void main()
{
  int n;
  int count;
  printf("Please enter the no. of elements for fibonacci series");
  scanf("%d", &count);

  for (int i = 0; i < count; i++)
  {
    printf("%d \t", fib(i));
  }
}