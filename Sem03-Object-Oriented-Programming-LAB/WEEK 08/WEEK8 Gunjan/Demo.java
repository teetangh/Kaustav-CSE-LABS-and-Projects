import java.util.*;

class RowSum implements Runnable {
    Thread t;
    int arr[];
    int sum;

    RowSum(int arr[]) {
        this.arr = arr;
        t = new Thread(this);
        t.start();
    }

    @Override
    public void run() {
        sum = 0;
        for (int x : arr)
            sum += x;
    }

}

class Demo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the matrix");
        int mat[][] = new int[sc.nextInt()][sc.nextInt()];
        
        
        System.out.println("Enter the Elements");
        for (int i = 0; i < mat.length; i++)
            for (int j = 0; j < mat[i].length; j++)
                mat[i][j] = sc.nextInt();

        int sum = 0;
        System.out.println("Matrix is :");
        for (int x[] : mat) {
            for (int y : x) {
                System.out.println(y + " ");
            }
            System.out.println();

        }

        RowSum Z[] = new RowSum[mat.length];
        for (int i = 0; i < mat.length; i++) {
            Z[i] = new RowSum(mat[i]);
        }

        System.out.println("Sum is :");
        for (RowSum x : Z) {
            try {
                x.t.join();
                System.out.println(x.sum);
                sum += x.sum;
            } catch (Exception e) {
                // TODO: handle exception
                System.out.println("Interrrupted");
            }

        }
        System.out.println("Total Sum is = " + sum);

    }
}