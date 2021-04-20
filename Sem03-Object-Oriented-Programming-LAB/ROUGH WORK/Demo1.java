class X {
    int a;

    X(int i) {
        a = i;
    }

    void show() {

        System.out.println("a in super " + a);
    }
}

class Y extends X {
    int a;

    Y(int i, int y) {
        super(i);
        a = y;
    }

    void show() {
        super.show();
        System.out.println("a in subclass " + a);
    }
}

class Demo1 {
    public static void main(String[] args) {
        Y y1 = new Y(10, 20);
        X x1 = new X(10);
        y1.show();
        x1.show();
    }
}