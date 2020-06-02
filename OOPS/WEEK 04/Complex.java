import java.util.*;

class Complexnumber {
    double real;
    double img;

    Complexnumber() {
        System.out.println("Inside the default Constructor");
    }

    Complexnumber(double real, double img) {
        this.real = real;
        this.img = img;
        System.out.println("Inside the Parameterized Constructor");
    }

    void display() {
        System.out.println("The value of the Complexnumber number is " + this.real + " + i " + this.img);
    }
}

class Complex {
    public static void main(String args[]) {
        double a, b;
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter the Real and Imaginary parts separately ");
        a = sc.nextDouble();
        b = sc.nextDouble();

        Complexnumber c1 = new Complexnumber();
        c1.display();

        Complexnumber c2 = new Complexnumber(a, b);
        c2.display();

        sc.close();
    }

}
