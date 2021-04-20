import java.util.*;

class Bankaccount {
    String name;
    long accountno;
    String type;
    double balance;
    static double rate;

    Bankaccount() {
        System.out.println("This is the default constructor");
    }

    Bankaccount(String name, long accountno, String type, double balance, double rate) {
        System.out.println("This is the parametrized constructor");
        this.name = name;
        this.accountno = accountno;
        this.type = type;
        this.balance = balance;
        this.rate = rate;
    }

    void deposit(double amount) {
        this.balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            this.balance -= amount;
        } else {
            System.out.println("Insufficient balance");
        }
    }

    void display() {
        System.out.println("Name is " + name);
        System.out.println("Accountno is " + accountno);
        System.out.println("Type of account is " + type);
        System.out.println("Balance is  " + balance);
        System.out.println("Rate is " + rate);
    }

    static void displayrate() {
        System.out.println("Rate from static method is " + rate);
    }
}

class Bank {
    public static void main(String[] args) {
        String a;
        long b;
        String c;
        double d;
        double e;

        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter details String name,long accountno,String type,double balance,double rate");
        a = sc.nextLine();
        b = sc.nextLong();

        // Flushing the buffer
        sc.nextLine();

        c = sc.nextLine();
        d = sc.nextDouble();
        e = sc.nextDouble();

        Bankaccount b1 = new Bankaccount();

        b1.display();

        System.out.println("-----------------------------");

        Bankaccount b2 = new Bankaccount(a, b, c, d, e);

        b2.deposit(150);
        b2.withdraw(50);

        b2.display();

        Bankaccount.displayrate();

        sc.close();
    }

}