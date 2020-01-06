import java.util.*;/*
                   * To change this license header, choose License Headers in Project Properties.
                   * To change this template file, choose Tools | Templates
                   * and open the template in the editor.
                   */

/**
 *
 * @author sameer admin
 */
class invaliddayexception extends Exception {
    public void check() {
        System.out.println("Day not valid");
    }
}

class invalidmonthexception extends Exception {
    public void check() {

        System.out.println("Month not valid");
    }
}

public class currentdate {
    public int date, month, year;

    void createdate() throws invalidmonthexception, invaliddayexception {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter year,month and date");
        year = s.nextInt();
        month = s.nextInt();
        if (month > 12)
            throw new invalidmonthexception();
        else {
            date = s.nextInt();
            if (date > 31 || (month == 2 && date > 28))
                throw new invaliddayexception();
            if (month == 4 || month == 6 || month == 9 || month == 11) {
                if (date > 30)
                    throw new invaliddayexception();
            }
        }
    }

    void display() {
        System.out.println(date + "/" + month + "/" + year);
    }

    public static void main(String args[]) {
        try {
            currentdate a = new currentdate();
            a.createdate();
            a.display();
        } catch (invalidmonthexception e) {
            e.check();

        } catch (invaliddayexception e) {
            e.check();
        }

    }

}
