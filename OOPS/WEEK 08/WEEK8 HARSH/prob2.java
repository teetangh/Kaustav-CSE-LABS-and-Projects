import java.util.*;

class Sum {
    int rsum(int a[]) {
        int s = 0;
        for (int i = 0; i < a.length; i++) {
            s = s + a[i];
        }

        System.out.println("Sum of row: " + s);
        return s;

    }
}

class prob2 implements Runnable {
    Thread t;
    int a[];
    int rsum;
    Sum s;

    prob2(int arr[], Sum ob) {
        t = new Thread(this);
        a = arr;
        rsum = 0;
        t.start();
    }

    @Override
    public void run() {
        rsum = s.rsum(a);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = 0;
        int sum = 0;
        int c = 0;
        System.out.println("Input the number of Rows and Columns");
        r = sc.nextInt();
        c = sc.nextInt();
        int arr[][] = new int[r][c];
        System.out.println("Input the array elements");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        Sum s = new Sum();
        prob2 ob[] = new prob2[r];
        for (int i = 0; i < r; i++) {

            ob[i] = new prob2(arr[i], s);
            try {
                ob[i].t.join();
            } catch (Exception e) {
                // TODO: handle exception
                System.out.println(e);
            } finally {
                sum = sum + ob[i].rsum;
            }

        }
        System.out.println("Sum of Matrix is " + sum);
    }
}