class fibo {
        public static void main(String args[]) {
                int f = 0, s = 1, t = 0, i, n = 5, temp = 0;
                for (i = 2; i < n + 1; i++) {
                        t = f + s;
                        f = s;
                        s = t;
                }
                System.out.println("fibonacci=" + t);
        }
}
