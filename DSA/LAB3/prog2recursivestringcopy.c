#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stringcopy(char a[], int beg, int last)
{
  if (beg != last)
  {
    printf("%c", a[beg]);
    return stringcopy(a, (beg + 1), last);
  }
  else
    return '\0';
}

void main()
{
  char a[20];
  int len;

  printf("Please enter the string to be copied \n");
  gets(a);
  len = strlen(a);

  for (int i = 0; i < len; i++)
  {
    printf("%c", a[i]);
  }

  printf("\n");

  stringcopy(a, 0, len);
}