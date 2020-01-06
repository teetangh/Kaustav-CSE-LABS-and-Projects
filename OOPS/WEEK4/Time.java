import java.util.*;

class timevalue {
    double hours;
    double minutes;
    double seconds;

    timevalue() {
        System.out.println("This is the default constructor");
    }

    timevalue(double hours, double minutes, double seconds) {
        System.out.println("This is the parameterized constructor");
        this.hours = hours;
        this.minutes = minutes;
        this.seconds = seconds;
    }

    void display() {
        System.out.println("The value of time is " + hours + " " + minutes + " " + seconds);
    }
}

class Time {
    public static void main(String[] args) {
        double a, b, c;
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter the hours minutes and seconds separately ");
        a = sc.nextDouble();
        b = sc.nextDouble();
        c = sc.nextDouble();

        timevalue t1 = new timevalue();

        t1.display();

        timevalue t2 = new timevalue(a, b, c);

        t2.display();
        
        sc.close();
    }
}