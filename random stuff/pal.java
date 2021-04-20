class pal {
        public static void main(String args[]) {
                int n = 656, rev = 0, r, d;
                d = n;
                while (n > 0) {
                        r = n % 10;
                        rev = rev * 10 + r;
                        n = n / 10;
                }
                if (rev == d)
                        System.out.println("is palindrome");
                else
                        System.out.println("is not palindrome");
        }
}
