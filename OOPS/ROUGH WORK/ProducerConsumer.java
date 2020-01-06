class Q {
    int num;
    boolean valueSet = false;

    public synchronized void put(int num) {
        while (valueSet) {
            try {
                wait(1000);
            } catch (Exception e) {
                // TODO: handle exception
            }
        }
        System.out.println("Put: " + num);
        this.num = num;
        valueSet = true;
        notify();

    }

    public synchronized void get() {
        while (!valueSet) {
            try {
                wait(1000);
            } catch (Exception e) {
                // TODO: handle exception
            }
        }
        System.out.println("Got: " + num);
        valueSet = false;
        notify();

    }
}

class Producer implements Runnable {
    Q q;

    Producer(Q q) {
        this.q = q;
        Thread t = new Thread(this, "Producer");
        t.start();
    }

    @Override
    public void run() {
        int i = 0;
        while (true) {
            q.put(i++);
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
                // TODO: handle exception
            }
        }
    }
}

class Consumer implements Runnable {
    Q q;

    Consumer(Q q) {
        this.q = q;
        Thread t = new Thread(this, "Consumer");
        t.start();
    }

    @Override
    public void run() {
        while (true) {
            q.get();
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
                // TODO: handle exception
            }
        }
    }
}

class ProducerConsumer {
    public static void main(String[] args) {
        Q q = new Q();
        new Producer(q);
        new Consumer(q);
    }
}