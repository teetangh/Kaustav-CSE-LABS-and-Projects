class A {
    int i, j;

    void showij() {
        System.out.println("i and j are " + i + " " + j);
    }

}

class B extends A {
    int k;

    void showk() {
        System.out.println("k is " + k);
    }

    void sum() {
        System.out.println("Sum is " + (i + j + k));
    }
}

class SimpleInheritance {
    public static void main(String[] args) {
        A superob = new A();
        B subob = new B();

        superob.i = 10;
        superob.j = 20;
        superob.showij();

        subob.i = 7;
        subob.j = 8;
        subob.k = 9;
        subob.showij();
        subob.showk();
        subob.sum();

    }
}
