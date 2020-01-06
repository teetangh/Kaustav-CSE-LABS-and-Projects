class A extends Thread {
    @Override
    public void run() {
        for (int i = 1; i < 5; i++) {
            try {

                if (i == 2)
                    sleep(5_000);
            } catch (Exception e) {
                // TODO: handle exception
            }

            System.out.println("A" + i);
        }
        System.out.println("A Exit");
    }
}

class B extends Thread {
    @Override
    public void run() {
        for (int j = 0; j < 5; j++) {
            System.out.println("B" + j);
        }
        System.out.println("B Exit");
    }
}

class YieldTest {
    public static void main(String[] args) {
        A a = new A();
        B b = new B();
        a.start();
        b.start();
    }
}