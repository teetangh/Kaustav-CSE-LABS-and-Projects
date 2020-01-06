#include <stdio.h>

void main()

{ //All variables
   int r1, c1, r2, c2;
   int A[10][10];
   int B[10][10];
   int C[10][10];
   int i, j, k;

   // Main code
   //Dimensions
   do
   {

      printf("Please enter 2 valid matrices \n");
      printf("Please enter rows and columns of the first matrix \n");
      scanf("%d%d", &r1, &c1);

      printf("Please enter rows and columns of the second matrix \n");
      scanf("%d%d", &r2, &c2);
   } while (!(c1 == r2));

   // 1st matrix input
   printf("1st matrix input \n");
   for (i = 0; i < r1; i++)
   {
      for (j = 0; j < c1; j++)
      {
         scanf("%d", &A[i][j]);
      }

      printf("\n");
   }

   // 2nd matrix input
   printf("2nd matrix input \n");
   for (i = 0; i < r2; i++)
   {
      for (j = 0; j < c2; j++)
      {
         scanf("%d", &B[i][j]);
      }

      printf("\n");
   }

   //Actual Multiplication
   for (i = 0; i < r1; i++)
   {
      for (j = 0; j < c2; j++)
      {
         C[i][j] = 0;
         for (k = 0; k < c1; k++)
         {
            C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
         }
      }
   }

   //Displayling the result
   for (i = 0; i < r1; i++)
   {
      for (j = 0; j < c2; j++)
      {
         printf("%d ", C[i][j]);
      }

      printf("\n");
   }
}