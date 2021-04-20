import java.util.Scanner;

class funcMat {
   static int a[][], r, c;

   static void insert() {
      int i, j;
      Scanner sc = new Scanner(System.in);
      for (i = 0; i < r; i++) {
         for (j = 0; j < c; j++) {
            a[i][j] = sc.nextInt();
         }
      }
   }

   static void display() {
      for (int x[] : a) {
         for (int y : x) {
            ;
         }
         System.out.println();
      }
   }

   static void sum() {
      int sum = 0;
      for (int x[] : a) {
         for (int y : x) {
            sum = sum + y;
         }
      }
   }

 public static void main(String args[])
  Scanner sc=new Scanner(System.in);
  r=sc.nextInt();
  c=sc.nextInt();
  a[][]= new int[r][c];
  insert();
  display();
  sum();
 
}
