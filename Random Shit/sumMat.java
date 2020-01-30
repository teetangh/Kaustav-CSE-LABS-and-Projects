import java.util.Scanner;

class sumMat {
        public static void main(String args[]) {
                Scanner sc = new Scanner(System.in);
                int r1, c1, r2, c2, i, j;
                System.out.println("Enter the order of the first and second matrices");
                r1 = sc.nextInt();
                c1 = sc.nextInt();
                r2 = sc.nextInt();
                c2 = sc.nextInt();
                int a[][] = new int[r1][c1];
                int b[][] = new int[r2][c2];
                System.out.println("Enter the elements of the first matrix");
                for (i = 0; i < r1; i++) {
                        for (j = 0; j < c1; j++) {
                                a[i][j] = sc.nextInt();
                        }
                }
                System.out.println("Enter the elements of the second matrix");
                for (i = 0; i < r2; i++) {
                        for (j = 0; j < c2; j++) {
                                b[i][j] = sc.nextInt();
                        }
                }
                if ((r1 != r2) || (c1 != c2)) {
                        System.out.println("Invalid matrices");
                        sc.close();
                        return;
                }
                int c[][] = new int[r1][c1];
                for (i = 0; i < r1; i++) {
                        for (j = 0; j < c1; j++) {
                                c[i][j] = a[i][j] + b[i][j];
                        }
                }
                System.out.println("The sum of matrices is");
                for (i = 0; i < r1; i++) {
                        for (j = 0; j < c1; j++) {
                                System.out.print(c[i][j] + " ");
                        }
                        System.out.println("\t");
                }
                sc.close();
        }
}
