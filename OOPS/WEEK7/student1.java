import java.util.*;

class seatsfilledexception extends Exception {
    public void check() {
        System.out.println("Seats filled");
    }
}

public class student1 {
    int reg;
    String l, m;

    String setdate() {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter day month and year");
        int x = s.nextInt();
        int y = s.nextInt();

        int z = s.nextInt();
        GregorianCalendar c = new GregorianCalendar(z, y, x);
        String p = String.valueOf(c.get(Calendar.DATE));
        String q = String.valueOf(c.get(Calendar.MONTH));
        String r = String.valueOf(c.get(Calendar.YEAR));
        String l = r;
        m = String.join("/", p, q, r);
        return l;
    }

    void setreg(String x, int i) throws seatsfilledexception {
        String s = String.valueOf(i);
        String q = x.substring(2, 4);
        String l = q.concat(s);
        String k = q.concat("25");
        int o = Integer.valueOf(k);
        reg = Integer.parseInt(l);
        if (reg > o)
            throw new seatsfilledexception();
    }

    public static void main(String args[]) {
        try {

            student1 x[] = new student1[5];

            for (int i = 0; i < 5; i++) {
                x[i] = new student1();
                String p = x[i].setdate();
                x[i].setreg(p, i + 1);
            }

        } catch (seatsfilledexception e) {
            e.check();
        }

    }
}
