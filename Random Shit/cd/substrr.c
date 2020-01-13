#include <stdio.h>
 
void substring(char [], char[], int, int);
 
int main()
{
   char string[1000], sub[1000];
   int position, length, c = 0;
 
   printf("Input a string\n");
   gets(string);
 
   printf("Enter the position and length of substring\n");
   scanf("%d%d", &position, &length);
 
   substring(string, sub, position, length);
 
   printf("Required substring is \"%s\"\n", sub);
 
   return 0;
}
// C substring function definition
void substring(char s[], char sub[], int p, int l) {
   int c = 0;
   
   while (c < l) {
      sub[c] = s[p+c-1];
      c++;
   }
   sub[c] = '\0';
}