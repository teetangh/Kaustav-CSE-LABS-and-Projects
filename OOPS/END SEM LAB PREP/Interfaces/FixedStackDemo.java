interface IntStack {
    void push(int item);

    int pop();
}

class FixedStack implements IntStack {
    public int stck[];
    public int tos;

    FixedStack(int size) {
        stck = new int[size];
        tos = -1;
    }

    public void push(int item) {
        if (tos == stck.length - 1) {
            System.out.println("Stack is Full");
        } else
            stck[++tos] = item;
    }

    public int pop() {
        if (tos < 0) {
            System.out.println("Stack underflow");
            return (0);
        } else
            return stck[tos--];
    }

}

class FixedStackDemo {

    public static void main(String[] args) {
        FixedStack mystack1 = new FixedStack(5);
        FixedStack mystack2 = new FixedStack(8);

        for (int i = 0; i < mystack1.stck.length; i++)
            mystack1.push(i);
        for (int i = 0; i < mystack2.stck.length; i++)
            mystack2.push(i);

        for (int i = 0; i < mystack1.stck.length; i++)
            System.out.print(mystack1.pop() + "\t");
        System.out.println();
        for (int i = 0; i < mystack2.stck.length; i++)
            System.out.print(mystack2.pop() + "\t");
        // mystack2.pop();

    }
}
