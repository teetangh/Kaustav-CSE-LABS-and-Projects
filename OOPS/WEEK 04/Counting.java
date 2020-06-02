class Counter {
    static int count = 0;

    Counter() {
        System.out.println("Default Constructor called");
        count++;
    }

    static void showCount() {
        System.out.println("Value of count is " + count);
    }
}

class Counting {
    public static void main(String[] args) {
        Counter c1 = new Counter();
        Counter c2 = new Counter();
        Counter c3 = new Counter();
        Counter c4 = new Counter();

        Counter.showCount();
    }
}