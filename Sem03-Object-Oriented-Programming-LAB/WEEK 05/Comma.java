import java.util.Scanner;

class Comma {

    public static void main(String[] args) {
        System.out.println("Please enter number for comma");
        Scanner sc = new Scanner(System.in);
        long num = sc.nextLong();
        String str = String.valueOf(num);
        int n = str.length();
        for (int i = n - 1; i >= 0; i--) {
            System.out.print(str.charAt(n - i - 1));
            if (i % 3 != 0 || i == 0)
                continue;
            else
                System.out.print(",");
        }

        sc.close();
    }
}