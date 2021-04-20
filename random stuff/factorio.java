class factorio {
        public static void main(String args[]) {
                int n = 6, f = 1;
                while (n > 0) {
                        f = f * n;
                        n = n - 1;
                }
                System.out.println("factorial=" + f);
        }
}
