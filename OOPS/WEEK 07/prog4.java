import java.util.*;

interface series {
        int getnext();

        void reset();

        void setstart(int x);
}

class Bytwos implements series {
        int i, j;

        public int getnext() {
                i += 2;
                return i;
        }

        public void reset() {
                i = j;
                System.out.println("Reset");
        }

        public void setstart(int x) {
                i = x;
                j = x;
        }

        void disp(int k) {
                while (k != 0) {
                        i += 2;
                        System.out.println(i);
                        k--;
                }
        }
}

class prog4 {
        public static void main(String args[]) {
                Scanner sc = new Scanner(System.in);
                Bytwos b = new Bytwos();
                System.out.println("Set first value");
                int p = sc.nextInt();
                b.setstart(p);
                int n, y, l;
                do {
                        System.out.println("Enter 1 for get next 2 for reset 3 for set 4 for display 5 to    exit");
                        n = sc.nextInt();
                        switch (n) {
                        case 1:
                                System.out.println(b.getnext());
                                break;
                        case 2:
                                b.reset();
                                break;
                        case 3:
                                System.out.println("Enter number ");
                                y = sc.nextInt();
                                b.setstart(y);
                                break;
                        case 4:
                                System.out.println("Enter number of terms");
                                l = sc.nextInt();
                                b.disp(l);
                                break;
                        }
                } while (n != 5);

        }
}
