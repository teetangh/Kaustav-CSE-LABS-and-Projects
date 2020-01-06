#include "CharStack.h"

void main()
{
  char temp[20];
  stack s;
  s.top = -1;

  printf("Enter the word to be checked as Palindrome \t");
  gets(temp);

  for (int i = 0; i < strlen(temp); i++)
  {
    /* code */
    push(&s, temp[i]);
  }

  for (int i = 0; i < strlen(temp); ++i)
  {
    /* code */
    if (temp[i] != pop(&s))
    {
      printf("Not a Palindrome \n");
      exit(0);
    }
  }
  printf("Yes it is a Palindrome \n");
}