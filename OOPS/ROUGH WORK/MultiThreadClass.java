import java.lang.*;

class ThreadA extends Thread {
    public void run() {
        for (int i = 1; i < 10; i++) {
            System.out.println("From Thread A with i = " + i);
        }
        System.out.println("Exiting From Thread A ");
    }
}

class ThreadB extends Thread {
    public void run() {
        for (int j = 1; j < 10; j++) {
            System.out.println("From Thread B with j = " + j);
        }
        System.out.println("Exiting From Thread B ");
    }
}

class ThreadC extends Thread {
    public void run() {
        for (int k = 1; k < 10; k++) {
            System.out.println("From Thread C with k = " + (k));
        }
        System.out.println("Exiting From Thread C ");
    }
}

class MultiThreadClass {
    public static void main(String[] args) {
        ThreadA a = new ThreadA();
        ThreadB b = new ThreadB();
        ThreadC c = new ThreadC();

        a.start();
        b.start();
        c.start();

        System.out.println("Multithreading is over ....");
    }
}