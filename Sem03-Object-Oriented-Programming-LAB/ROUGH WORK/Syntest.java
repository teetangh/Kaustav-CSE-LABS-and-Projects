class A {
    synchronized void addnew(int i) {
        Thread t = Thread.currentThread();

        for (int n = 1; n <= 5; n++) {
            System.out.println(t.getName() + " " + (i + n));
        }
    }
}

class B extends Thread {
    A a1 = new A();

    public void run() {
        a1.addnew(100);
    }

}

class Syntest {
    public static void main(String[] args) {
        B b = new B();
        Thread t1 = new Thread(b);
        Thread t2 = new Thread(b);

        t1.setName("T1");
        t2.setName("T2");
        t1.start();
        t2.start();

    }
}