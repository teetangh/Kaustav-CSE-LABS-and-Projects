#include "IntStack.h"

void bindisplay(stack *ps)
{
  printf("Elements in the stack are:\n");
  for (int i = ps->top; i >= 0; i--)
  {
    /* code */
    printf("%d", ps->arr[i]);
  }
}

void main()
{

  stack s;
  s.top = -1;
  int number;
  int temp;

  printf("Enter Number for Dec2Bin conversion \t");
  scanf("%d", &number);

  while (number > 0)
  {
    temp = number % 2;
    push(&s, temp);
    number = number / 2;
  }

  bindisplay(&s);
  printf("\n");
}