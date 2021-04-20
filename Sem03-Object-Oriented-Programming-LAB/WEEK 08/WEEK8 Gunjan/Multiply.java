class M implements Runnable {
    int x;
    multi m;
    Thread t;

    public M(multi m1, int x1) {
        x = x1;
        m = m1;
        Thread t = new Thread();
        t.start();
    }

    @Override
    public void run() {
        m.mul(x);
    }
}

class multi {
    synchronized void mul(int x) {
        try {
            for (int i = 0; i < 10; i++) {
                System.out.println(x + "*" + (i + 1) + "=" + x * (i + 1));
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            // TODO: handle exception
            System.out.println("Interrupted Exception");
        }
    }
}

class Multiply {
    public static void main(String[] args) {
        multi m = new multi();
        M ob1 = new M(m, 5);
        M ob2 = new M(m, 7);
    }
}