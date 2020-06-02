#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pal(char str[], int l, int h)
{
  if (str[l] != str[h])
  {
    return -1;
  }

  else if (l < h)
  {
    return pal(str, l + 1, h - 1);
  }
  return 1;
}
void main()
{
  char str[50];
  printf("Input the string \n");
  gets(str);

  int x = pal(str,0,strlen(str)-1);

  if (x==1)
  {
    printf("PALINDROME");
  }

  else
  {
    printf("NOT PALINDROME");
  }
  
}